#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <functional>
#include <iostream>
#include <deque>
//#include "Measure.h"
#include "ServerTCP.h"
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
		virtual void OnReceived(const unsigned int connectionID, const tVectorUInt8&& data) override
		{
			p_obj->OnReceived(connectionID, std::forward<const tVectorUInt8>(data));
		}
		//void Send(const tVectorUInt8&& data) { };
	};

	boost::shared_ptr<tServerHandler> m_Server;

	std::deque<tVectorUInt8> m_ServerQueue;

public:
	tBenchmark(boost::asio::io_context& io_context)
		:m_Server(new tServerHandler(this, io_context))
	{
		//m_Server = boost::shared_ptr<tServerHandler>(new tServerHandler(this, io_context));

		m_Server->Start();

		//m_Server.reset();
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

	void DisplayConnections()
	{
		std::vector<tMeasureConnection> MeasureConnection = m_Server->GetMeasureConnection();

		for (auto& i : MeasureConnection)
		{
			std::cout << " " << i << '\n';
		}

		//m_Server->DisplayConnections();
	}
private:
	//virtual void OnConnected(tServerTCPConnection::tPointer connection) override
	//{
	//}

	void OnReceived(const unsigned int connectionID, const tVectorUInt8&& data)
	{
		//std::cout << data.size() << '\n';

		tPacketBNTBX2 Packet;

		if (tPacketBNTBX2::TryParse(data, Packet))
		{
			//std::cout << "tPacketBNTBX2::TryParse() OK\n";

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

						//std::cout << "tPacketBNTBX2::GetMsg<tPayloadBNTBX0802>() OK " << static_cast<int>(Cmd.CheckID) << '\n';

						tMsgBNTBX0802Rsp Rsp(0x23);

						tPacketBNTBX2 PacketAns;

						PacketAns.SetMsg(Rsp);

						m_Server->Send(connectionID, PacketAns.ToVector());
						//m_ServerQueue.push_back(Msg.ToVector());
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
			//case tPacketBNTBX2::tMsgID::Msg09:
			//{
			//	switch (Packet.GetMsgVER())
			//	{
			//	case 0x02:
			//	{
			//		try
			//		{
			//			tMsgBNTBX0802Cmd Cmd = Packet.GetMsg<tMsgBNTBX0802Cmd>();

			//			//std::cout << "tPacketBNTBX2::GetMsg<tPayloadBNTBX0802>() OK " << static_cast<int>(Cmd.CheckID) << '\n';

			//			tMsgBNTBX0802Rsp Msg(0x23);

			//			m_Server->Send(Msg.ToVector());
			//			//m_ServerQueue.push_back(Msg.ToVector());
			//		}
			//		catch (std::exception ex)
			//		{
			//			std::cout << "tPacketBNTBX2::GetMsg<tPayloadBNTBX0802>() ER: " << ex.what() << '\n';
			//		}

			//		break;
			//	}
			//	}

			//	break;
			//}
			}
		}
	}

public:
	std::ostream& operator<< (std::ostream& out)
	{
		std::vector<tMeasureConnection> MeasureConnection = m_Server->GetMeasureConnection();

		for (auto& i : MeasureConnection)
		{
			out << " " << i << '\n';
		}

		return out;
	}

	//friend std::ostream& operator<< (std::ostream& out, const tBenchmark<tServer>& bm);
};

//template <class tServer>
//inline std::ostream& operator<< (std::ostream& out, const tBenchmark<tServer>& bm)
//{
//	//std::time_t TimeStart = std::chrono::system_clock::to_time_t(measureConnection.TimePointStart);
//
//	//tm TimeinfoStart;
//	//localtime_s(&TimeinfoStart, &TimeStart);
//
//	std::vector<tMeasureConnection> MeasureConnection;// = bm.m_Server->GetMeasureConnection();
//
//	for (auto& i : MeasureConnection)
//	{
//		out << " " << i << '\n';
//	}
//
//	return out;
//}