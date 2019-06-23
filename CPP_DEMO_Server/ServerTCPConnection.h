//#pragma once
//
//#include <boost/asio.hpp>
//#include <boost/bind.hpp>
//#include <boost/shared_ptr.hpp>
//#include <boost/enable_shared_from_this.hpp>
//#include "Shared.h"
//#include "ServerTCP.h"
//
//using boost::asio::ip::tcp;
/////////////////////////////////////////////////////////////////////////////////////////////////////
//class tServerTCPConnection : public boost::enable_shared_from_this<tServerTCPConnection>
//{
//	tcp::socket m_Socket;
//
//	tVectorUInt8 m_ReceivedData = tVectorUInt8(4096);
//
//	tServerTCP m_Server;
//	//tServerTCP::tPointer m_Server;
//
//	tServerTCPConnection(boost::asio::io_context& io_context)//, tServerTCP::tPointer server)
//		:m_Socket(io_context)//, m_Server(server)
//	{
//
//	}
//
//public:
//	typedef boost::shared_ptr<tServerTCPConnection> tPointer;
//
//	static tPointer Create(boost::asio::io_context& io_context)//, ::tServerTCP::tPointer server)
//	{
//		return tPointer(new tServerTCPConnection(io_context));//, server));
//	}
//
//	tcp::socket& socket()
//	{
//		return m_Socket;
//	}
//
//	void Start()
//	{
//		m_Socket.async_read_some(
//			boost::asio::buffer(m_ReceivedData),
//			boost::bind(
//				&tServerTCPConnection::HandleRead, shared_from_this(),
//				boost::asio::placeholders::error,
//				boost::asio::placeholders::bytes_transferred));
//	}
//
//	void Send(const tVectorUInt8&& data)
//	{
//		m_Socket.write_some(boost::asio::buffer(data));
//	}
//
//private:
//	void HandleRead(const boost::system::error_code& error, size_t bytes_transferred)
//	{
//		if (!error)
//		{
//			//m_Server.//OnReceived(tVectorUInt8(m_ReceivedData.begin(), m_ReceivedData.begin() + bytes_transferred));
//			//p_Connect->OnReceived(tVectorUInt8(m_ReceivedData.begin(), m_ReceivedData.begin() + bytes_transferred));
//
//			Start();
//		}
//	}
//
//	//virtual void OnReceived(const tVectorUInt8&& data) override
//	//{
//	//}
//};