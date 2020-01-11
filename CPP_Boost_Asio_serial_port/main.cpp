#include <iostream>
//#include <istream>
//#include <ostream>
#include <string>
#include <boost/asio.hpp>

#include <utilsBase.h>

//using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
	boost::asio::io_context IO;

	boost::asio::serial_port Port(IO);

	// ... lalalala

	if (!Port.is_open())
	{
		boost::system::error_code Cerr;

		Port.open("COM5", Cerr);

		//if (Cerr.value() == boost::system::errc::argument_list_too_long)
		{
			std::cout << "MEDVED: "<< Cerr.message()<<"\n";
		}


		if (Port.is_open())
		{
			// option settings...
			Port.set_option(boost::asio::serial_port_base::baud_rate(9600), Cerr);
			std::cout << "MEDVED: " << Cerr.message() << "\n";
			Port.set_option(boost::asio::serial_port_base::character_size(8));
			Port.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
			Port.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
			Port.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));

			utils::tVectorUInt8 DataReceived(2048);

			while(Port.is_open())
			{
				std::size_t DataReceivedSize = Port.read_some(boost::asio::buffer(DataReceived), Cerr);

				if (DataReceivedSize > 0)
				{
					std::cout << DataReceived.data();
				}

				if (Cerr.value() != 0)
				{
					std::cout << "PREVED: " << Cerr.message() << "\n";
				}
			}


			std::cout << "PREVED!!\n";

			Port.close();
		}
	}

	return 0;
}