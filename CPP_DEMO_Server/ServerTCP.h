#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

using boost::asio::ip::tcp;
///////////////////////////////////////////////////////////////////////////////////////////////////
class tServerTCPConnection : public boost::enable_shared_from_this<tServerTCPConnection>
{
	tcp::socket m_Socket;

	tVectorUInt8 m_ReceivedData;

	tServerTCPConnection(boost::asio::io_context& io_context)
		:m_Socket(io_context)
	{

	}

public:
	typedef boost::shared_ptr<tServerTCPConnection> tPointer;

	static tPointer Create(boost::asio::io_context& io_context)
	{
		return tPointer(new tServerTCPConnection(io_context));
	}

	tcp::socket& socket()
	{
		return m_Socket;
	}

	void Start()
	{
		//[TBD] READING 08 Cmd
		m_ReceivedData = tVectorUInt8(4096);

		m_Socket.async_read_some(
			boost::asio::buffer(m_ReceivedData),
			boost::bind(
				&tServerTCPConnection::HandleRead, shared_from_this(),
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}

private:
	void HandleRead(const boost::system::error_code& error, size_t bytes_transferred)
	{
		if (!error)
		{
			std::cout << "HandleRead: " << bytes_transferred << '\n';

			//boost::shared_ptr<std::string> message(new std::string(make_daytime_string()));

			//socket_.async_send_to(boost::asio::buffer(*message), remote_endpoint_,
			//	boost::bind(&udp_server::handle_send, this, message,
			//		boost::asio::placeholders::error,
			//		boost::asio::placeholders::bytes_transferred));

			Start();
		}
	}
	//void handle_read(const boost::system::error_code& error, size_t /*bytes_transferred*/)
	//{
	//	if (!error)
	//	{
	//		message_ = make_daytime_string();

	//		boost::asio::async_write(socket_, boost::asio::buffer(message_),
	//			boost::bind(&tcp_connection::handle_write, shared_from_this(),
	//				boost::asio::placeholders::error,
	//				boost::asio::placeholders::bytes_transferred));
	//	}
	//}
	//void handle_write(const boost::system::error_code& error, size_t /*bytes_transferred*/)
	//{
	//	if (!error)
	//	{
	//		message_ = make_daytime_string();

	//		boost::asio::async_write(socket_, boost::asio::buffer(message_),
	//			boost::bind(&tcp_connection::handle_write, shared_from_this(),
	//				boost::asio::placeholders::error,
	//				boost::asio::placeholders::bytes_transferred));
	//	}
	//}
};
///////////////////////////////////////////////////////////////////////////////////////////////////
class tServerTCP
{
	boost::asio::io_context& m_IO_Context;

	tcp::acceptor m_Acceptor;

public:
	explicit tServerTCP(boost::asio::io_context& io_context)
		:m_IO_Context(io_context), m_Acceptor(tcp::acceptor(m_IO_Context, tcp::endpoint(tcp::v4(), 50025)))
	{
		StartAccept();
	}

private:
	void StartAccept()
	{
		tServerTCPConnection::tPointer Connection = tServerTCPConnection::Create(m_IO_Context);

		m_Acceptor.async_accept(Connection->socket(), boost::bind(&tServerTCP::HandleAccept, this, Connection, boost::asio::placeholders::error));
	}

	void HandleAccept(tServerTCPConnection::tPointer connection, const boost::system::error_code& error)
	{
		if (!error)
		{
			connection->Start();
		}

		//[TBD] Handle errors

		StartAccept();
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////