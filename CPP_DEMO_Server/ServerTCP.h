#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <deque>
#include <vector>
//#include <iostream>//TEST
#include <mutex>
#include "Measure.h"
#include "Shared.h"

using boost::asio::ip::tcp;
///////////////////////////////////////////////////////////////////////////////////////////////////
class tServerTCP : public boost::enable_shared_from_this<tServerTCP>
{
	typedef boost::shared_ptr<tServerTCP> tPointer;

	class tServerTCPConnection : public boost::enable_shared_from_this<tServerTCPConnection>
	{
		friend tServerTCP;

		unsigned int m_ConnectionID;

		tMeasureConnection m_MeasureConnection;

		tcp::socket m_Socket;

		tVectorUInt8 m_ReceivedData = tVectorUInt8(4096);

		tServerTCP::tPointer m_Server;

		tServerTCPConnection(boost::asio::io_context& io_context, tServerTCP::tPointer server)
			:m_Socket(io_context), m_Server(server)
		{
			static unsigned int ConnectionID = 0;

			m_MeasureConnection = tMeasureConnection(m_ConnectionID = ConnectionID++);

			//std::cout << "tServerTCPConnection: " << m_MeasureConnection.ID << '\n';
		}

	public:
		typedef boost::shared_ptr<tServerTCPConnection> tPointer;

		virtual ~tServerTCPConnection()
		{
			m_Socket.close();

			//std::cout << "~tServerTCPConnection: " << m_MeasureConnection.ID << '\n';
		}

		static tPointer Create(boost::asio::io_context& io_context, tServerTCP::tPointer server)
		{
			return tPointer(new tServerTCPConnection(io_context, server));
		}

		tcp::socket& socket()
		{
			return m_Socket;
		}

		void Start()
		{
			m_Socket.async_read_some(
				boost::asio::buffer(m_ReceivedData),
				boost::bind(
					&tServerTCPConnection::HandleRead, shared_from_this(),
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred));
		}

		void Send(const tVectorUInt8&& data)//[TBD]shall be async
		{
			size_t Bytes = m_Socket.write_some(boost::asio::buffer(data));

			m_MeasureConnection.AddByteQtySent(Bytes);
		}

	private:
		void HandleRead(const boost::system::error_code& error, size_t bytes_transferred);
	};

	friend tServerTCPConnection;

	boost::asio::io_context& m_IO_Context;

	tcp::acceptor m_Acceptor;

	std::mutex m_ConnectionsMtx;
	std::deque<tServerTCPConnection::tPointer> m_Connections;

public:
	explicit tServerTCP(boost::asio::io_context& io_context)
		:m_IO_Context(io_context), m_Acceptor(tcp::acceptor(m_IO_Context, tcp::endpoint(tcp::v4(), 50025)))
	{
		
	}

	void Start()
	{
		tServerTCPConnection::tPointer Connection = tServerTCPConnection::Create(m_IO_Context, shared_from_this());

		m_Acceptor.async_accept(Connection->socket(), boost::bind(&tServerTCP::HandleAccept, this, Connection, boost::asio::placeholders::error));
	}

	void Send(const unsigned int connectionID, const tVectorUInt8&& data)
	{
		std::lock_guard<std::mutex> Mtx(m_ConnectionsMtx);

		for (auto& i : m_Connections)
		{
			if (connectionID == i->m_ConnectionID)
			{
				i->Send(std::forward<const tVectorUInt8>(data));

				break;
			}
		}
	}

	std::vector<tMeasureConnection> GetMeasureConnection()
	{
		std::vector<tMeasureConnection> MeasureConnection;

		std::lock_guard<std::mutex> Mtx(m_ConnectionsMtx);

		MeasureConnection.reserve(m_Connections.size());

		for (auto& i : m_Connections)
		{
			MeasureConnection.push_back(i->m_MeasureConnection);
		}

		return MeasureConnection;
	}

private:
	void HandleAccept(tServerTCPConnection::tPointer connection, const boost::system::error_code& error)
	{
		if (!error)
		{
			{
				std::lock_guard<std::mutex> Mtx(m_ConnectionsMtx);

				m_Connections.push_back(connection);
			}

			//OnConnected(connection);
			
			connection->Start();
		}

		//[TBD] Handle errors

		Start();
	}

	void HandleBreak(tServerTCPConnection::tPointer connection, const boost::system::error_code& error)
	{
		//for (auto i : m_Connections)
		//{
			//[TBD]Remove closed connection from the queue

			std::cout << "HandleBreak " << connection->m_MeasureConnection.ID <<" "<< error << '\n';

			//if (*i.get() == connection.get())
			//{
			//}
		//}
	}

protected:
	//virtual void OnConnected(const unsigned int connectionID) = 0;
	//virtual void OnDisconnected(const unsigned int connectionID) = 0;
	virtual void OnReceived(const unsigned int connectionID, const tVectorUInt8&& data) = 0;
};
///////////////////////////////////////////////////////////////////////////////////////////////////