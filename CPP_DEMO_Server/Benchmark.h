#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <functional>
#include <iostream>
#include <deque>
#include "Shared.h"
#include "PacketBNTBX2.h"
#include "PacketBNTBX2_Msg0802.h"

template <class tServer>
class tBenchmark
{
	struct tServerHandler : public tServer
	{
		tBenchmark* p_obj;

		//tServerHandler(boost::asio::io_context& io_Context) :tServer(io_Context) {}// , p_obj(obj) {}
		tServerHandler(tBenchmark* obj, boost::asio::io_context& io_Context) :tServer(io_Context), p_obj(obj) {}

		//virtual void OnConnected(tIConnection* connection)
		//{
		//	//p_obj->p_ServerActiveConnection = connection;
		//}
		virtual void OnReceived(const tVectorUInt8&& data) override
		{
			p_obj->OnReceived(std::forward<const tVectorUInt8>(data));
		}
		//void Send(const tVectorUInt8&& data) { };
	};

	//boost::asio::io_context& m_IO_Context;

	boost::shared_ptr<tServerHandler> m_Server;

	//boost::shared_ptr<tServerHandler> m_Server;

//	tIConnection p_ServerActiveConnection = nullptr;

	std::deque<tVectorUInt8> m_ServerQueue;

public:
	tBenchmark(boost::asio::io_context& io_context)
		//:m_Server(this, io_context)//, m_IO_Context(io_context)//, std::bind(&tBenchmark::Received, (void*)this, std::placeholders::_1))
	{
		m_Server = boost::shared_ptr<tServerHandler>(new tServerHandler(this, io_context));
		//m_Server = boost::shared_ptr<tServer>(new tServer(io_context));

		m_Server.get()->Start();
		//m_Server = boost::shared_ptr<tServerHandler>(new tServerHandler(this, io_context));
		//struct
		//{
		//	void OnReceived(tVectorUInt8& data)
		//	{
		//		this->Re
		//	}
		//};
		//auto Bound = std::bind(&tBenchmark::Received, this, std::placeholders::_1);
		////boost::bind()
		//auto Bound = boost::bind(&tBenchmark::Received, this, boost::asio::placeholders::bytes_transferred);
	}

private:
	//virtual void OnConnected(tServerTCPConnection::tPointer connection) override
	//{
	//}

	void OnReceived(const tVectorUInt8&& data)
	{
		std::cout << data.size() << '\n';

		tPacketBNTBX2 Packet;

		if (tPacketBNTBX2::TryParse(data, Packet))
		{
			std::cout << "tPacketBNTBX2::TryParse() OK\n";

			switch (Packet.GetMsgID())
			{
			case tPacketBNTBX2::tMsgID::Msg08:
			{
				switch (Packet.GetMsgVER())
				{
				case 0x02:
				{
					try
					{
						tMsgBNTBX0802Cmd Cmd = Packet.GetMsg<tMsgBNTBX0802Cmd>();

						std::cout << "tPacketBNTBX2::GetMsg<tPayloadBNTBX0802>() OK " << static_cast<int>(Cmd.CheckID) << '\n';

						tMsgBNTBX0802Rsp Msg(0x23);

						m_ServerQueue.push_back(Msg.ToVector());
					}
					catch (std::exception ex)
					{
						std::cout << "tPacketBNTBX2::GetMsg<tPayloadBNTBX0802>() ER: " << ex.what() << '\n';
					}

					break;
				}
				}

				break;
			}
			}
		}
	}

	//virtual void Send(const tVectorUInt8&& data) override
	//{
	//	//Se
	//}
};