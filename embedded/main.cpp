#include <iostream>

#include "Application.hpp"

int main(){
	try{
		boost::asio::io_context context;
		Application app(context);
		
		app.Start();
	}catch(...){
		std::cout << "Catch error" << std::endl;
	}

	return 0;
}