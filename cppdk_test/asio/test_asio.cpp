#include <iostream>
#include <cppdk/asio/asio.hpp>

void HandleClient(std::shared_ptr<asio::ip::tcp::socket> clientSocket)
{
    try
    {
        // read data from client
        asio::streambuf buf;
		
		std::cout << "read_until Start" << std::endl;
        asio::read_until(*clientSocket, buf, "\n");
		std::cout << "read_until End" << std::endl;
        
        // output recv data to stdin
        std::istream input(&buf);
        std::string message;
        std::getline(input, message);
        std::cout << "Recv Msg : " << message << std::endl;
        
        // reply client
        std::string response = "Server have already received : " + message + "\n";
        asio::write(*clientSocket, asio::buffer(response));
    }
    catch (std::exception& e)
    {
        std::cerr << "Err : " << e.what() << std::endl;
    }
}

void StartServer()
{
    try
    {
        // create ioContext
        asio::io_context ioContext;
        
        // create Listener
        asio::ip::tcp::acceptor acceptor(ioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 9999));
        
        std::cout << "Server start, listen : 9999" << std::endl;
        
        while (true)
        {
            // wait and recv client connect
            std::shared_ptr<asio::ip::tcp::socket> clientSocket = std::make_shared<asio::ip::tcp::socket>(ioContext);
            acceptor.accept(*clientSocket);
            
			std::cout << "Thread Start HandleClient..." << std::endl;
			
            // deal client request
            std::thread(HandleClient, clientSocket).detach();
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Err : " << e.what() << std::endl;
    }
}

int main()
{
    StartServer();
    return 0;
}