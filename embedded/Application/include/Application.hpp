#pragma once

#include <iostream>
#include <thread>
#include <boost/asio.hpp>
#include <chrono>
#include <string>

using namespace std::chrono_literals;

using tcp = boost::asio::ip::tcp;

class Application{
public:
	Application(boost::asio::io_context& context);

	void Start();

private:
	void MainLoop();

	tcp::socket socket;
};