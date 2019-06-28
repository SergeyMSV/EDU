#include <boost/asio.hpp>

class tService_1 : public boost::asio::execution_context::service
{
public:
	static boost::asio::execution_context::id id;

public:
	explicit tService_1(boost::asio::execution_context& e)
	:boost::asio::execution_context::service(e)
	{
	}

	virtual void shutdown()
	{
	}
};

boost::asio::execution_context::id tService_1::id;

int main()
{
	//boost::asio::io_context;

	boost::asio::execution_context Execution_Context;

	tService_1& Service_1 = boost::asio::make_service<tService_1>(Execution_Context);

	//Service_1.

	tService_1& Service_11 = boost::asio::use_service<tService_1>(Execution_Context);

	//Service_11.context()



	return 0;
}