#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <deque>
#include <iostream>//TEST
#include "Shared.h"
//#include "ServerTCPConnection.h"

using boost::asio::ip::tcp;

class tServerTCP;
typedef boost::shared_ptr<tServerTCP> tServerTCPPointer;

///////////////////////////////////////////////////////////////////////////////////////////////////
class tServerTCPConnection : public boost::enable_shared_from_this<tServerTCPConnection>
{
	tcp::socket m_Socket;

	tVectorUInt8 m_ReceivedData = tVectorUInt8(4096);

	tServerTCPPointer m_Server;

	tServerTCPConnection(boost::asio::io_context& io_context, tServerTCPPointer server)
		:m_Socket(io_context), m_Server(server)
	{

	}

public:
	typedef boost::shared_ptr<tServerTCPConnection> tPointer;

	virtual ~tServerTCPConnection()
	{
		m_Socket.close();

		std::cout << "~tServerTCPConnection\n";
	}

	static tPointer Create(boost::asio::io_context& io_context, tServerTCPPointer server)
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

	void Send(const tVectorUInt8&& data)
	{
		m_Socket.write_some(boost::asio::buffer(data));
	}

private:
	void HandleRead(const boost::system::error_code& error, size_t bytes_transferred);
};
///////////////////////////////////////////////////////////////////////////////////////////////////
class tServerTCP : public boost::enable_shared_from_this<tServerTCP>
{
	friend tServerTCPConnection;

	boost::asio::io_context& m_IO_Context;

	tcp::acceptor m_Acceptor;

	std::deque<tServerTCPConnection::tPointer> m_Connections;

public:
	//typedef boost::shared_ptr<tServerTCP> tPointer;

	explicit tServerTCP(boost::asio::io_context& io_context)
		:m_IO_Context(io_context), m_Acceptor(tcp::acceptor(m_IO_Context, tcp::endpoint(tcp::v4(), 50025)))
	{
		
	}

	void Start()
	{
		tServerTCPConnection::tPointer Connection = tServerTCPConnection::Create(m_IO_Context, shared_from_this());

		m_Acceptor.async_accept(Connection->socket(), boost::bind(&tServerTCP::HandleAccept, this, Connection, boost::asio::placeholders::error));
	}

private:
	void HandleAccept(tServerTCPConnection::tPointer connection, const boost::system::error_code& error)
	{
		if (!error)
		{
			//m_Connections.push_back(connection);

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

			std::cout << "HandleBreak " << error << '\n';

			//if (*i.get() == connection.get())
			//{
			//}
		//}
	}

protected:
	//virtual void OnConnected(tIConnection* connection) = 0;
	//virtual void OnDisconnected(const tVectorUInt8&& data) = 0;
	virtual void OnReceived(const tVectorUInt8&& data) = 0;

public:
	void Send(const tVectorUInt8&& data)
	{
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////