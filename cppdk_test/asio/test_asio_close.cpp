#include <iostream>
#include <cppdk/asio/asio.hpp>

void handle_read(const std::error_code& error, std::size_t bytes_transferred,
                 std::shared_ptr<asio::ip::tcp::socket> socket,
                 std::vector<char>& buffer)
{
    if (!error)
    {
        std::string message(buffer.data(), bytes_transferred);
        std::cout << "Received: " << message << std::endl;

        // close
        socket->close();
    }
}

void start_read(std::shared_ptr<asio::ip::tcp::socket> socket,
                std::vector<char>& buffer)
{
    socket->async_read_some(asio::buffer(buffer),
                            [socket, &buffer](const std::error_code& error, std::size_t bytes_transferred)
    {
        handle_read(error, bytes_transferred, socket, buffer);
    });
}

void start_accept(std::shared_ptr<asio::ip::tcp::acceptor> acceptor,
                  std::shared_ptr<asio::ip::tcp::socket> socket,
                  std::vector<char>& buffer)
{
    acceptor->async_accept(*socket, [acceptor, socket, &buffer](const std::error_code& error)
    {
        if (!error)
        {
            std::cout << "Client connected" << std::endl;
            start_read(socket, buffer);
        }
        else
        {
            std::cerr << "Error accepting connection: " << error.message() << std::endl;
        }
    });
}

int main()
{
    try
    {
        asio::io_context io_context;

        asio::ip::tcp::acceptor acceptor(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 9999));

        std::cout << "Server started. Listening on port 9999" << std::endl;

        std::shared_ptr<asio::ip::tcp::socket> socket(new asio::ip::tcp::socket(io_context));

        std::vector<char> buffer(1024);

        start_accept(std::make_shared<asio::ip::tcp::acceptor>(std::move(acceptor)), socket, buffer);

        io_context.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}