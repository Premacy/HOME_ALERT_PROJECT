#include "Application.hpp"

Application::Application(boost::asio::io_context& context)
	: 
	socket(context)
{
	std::string ip_string = "127.0.0.1";
	int port = 5555;

	boost::system::error_code ec;
	socket.connect({boost::asio::ip::address::from_string(ip_string), port}, ec);

	if(ec){
		throw std::invalid_argument("Error");
	}else{
		std::cout << "Establish connection" << std::endl;
	}
}

void Application::Start(){
	std::cout << "Start App" << std::endl;
	MainLoop();
}

void Application::MainLoop(){
	while(true){
		std::string str = "Hello, world";

		boost::system::error_code ec;

		std::cout << "Try to send message..." << std::endl;
		socket.send(boost::asio::buffer(str.c_str(), str.size()));

		if(ec){
			std::cout << "Close connection" << std::endl;
			return;
		}
		else{
			std::cout << "Message was sended!" << std::endl;
		}

		std::this_thread::sleep_for(1s);
	}
}