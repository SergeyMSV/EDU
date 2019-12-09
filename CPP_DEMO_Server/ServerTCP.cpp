#include "ServerTCP.h"

void tServerTCP::tServerTCPConnection::Start()
{
	m_Socket.async_read_some(
		boost::asio::buffer(m_DataReceived),
		boost::bind(
			&tServerTCPConnection::HandleRead, shared_from_this(),
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
}

void tServerTCP::tServerTCPConnection::Send(const tVectorUInt8&& data)
{
	//if (m_DataSend.size() < 10)//TEST Queue
	if (m_DataSendInProgress.size() > 0)
	{
		m_DataSend.push_back(std::forward<const tVectorUInt8>(data));
	}
	else
	{
		AsyncWrite(std::forward<const tVectorUInt8>(data));
	}
}

void tServerTCP::tServerTCPConnection::HandleRead(const boost::system::error_code& error, size_t bytes_transferred)
{
	if (!error)
	{
		m_Server->OnReceived(m_ConnectionID, tVectorUInt8(m_DataReceived.begin(), m_DataReceived.begin() + bytes_transferred));

		m_MeasureConnection.AddByteQtyReceived(bytes_transferred);

		Start();
	}
	else
	{
		HandleBreak(error);
	}
}

void tServerTCP::tServerTCPConnection::HandleWrite(const boost::system::error_code& error, size_t bytes_transferred)
{
	m_DataSendInProgress.clear();

	m_MeasureConnection.AddByteQtySent(bytes_transferred);

	if (!error)
	{
		if (m_DataSend.size() > 0)
		{
			AsyncWrite(std::move(m_DataSend.front()));

			m_DataSend.pop_front();
		}
	}
	else
	{
		HandleBreak(error);
	}
}

void tServerTCP::tServerTCPConnection::AsyncWrite(const tVectorUInt8&& data)
{
	m_DataSendInProgress = const_cast<tVectorUInt8&&>(data);

	m_Socket.async_write_some(
		boost::asio::buffer(m_DataSendInProgress),
		boost::bind(
			&tServerTCPConnection::HandleWrite, shared_from_this(),
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
}

void tServerTCP::tServerTCPConnection::HandleBreak(const boost::system::error_code& error)
{
	m_Socket.close();

	m_MeasureConnection.Closed();

	m_Server->HandleBreak(shared_from_this(), error);
}