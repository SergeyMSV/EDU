#include "ServerTCP.h"

void tServerTCP::tServerTCPConnection::HandleRead(const boost::system::error_code& error, size_t bytes_transferred)
{
	if (!error)
	{
		m_Server->OnReceived(m_ConnectionID, tVectorUInt8(m_ReceivedData.begin(), m_ReceivedData.begin() + bytes_transferred));

		m_MeasureConnection.AddByteQtyReceived(bytes_transferred);

		Start();
	}
	else
	{
		m_Socket.close();

		m_MeasureConnection.Closed();

		m_Server->HandleBreak(shared_from_this(), error);
	}
}