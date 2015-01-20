#include <iostream>
#include <boost/asio.hpp>

int main(int argc, char* argv[])
{
        using namespace boost::asio;
        // 所有asio类都需要io_service对象
        io_service iosev;
        ip::tcp::acceptor acceptor(iosev, 
        ip::tcp::endpoint(ip::tcp::v4(), 1000));
        for(;;)
        {
                // socket对象
                ip::tcp::socket socket(iosev);
                // 等待直到客户端连接进来
                acceptor.accept(socket);
                // 显示连接进来的客户端
                std::cout << socket.remote_endpoint().address() << std::endl;
                // 向客户端发送hello world!
                boost::system::error_code ec;

                // 接收数据
                char buf[100];
                size_t len=socket.read_some(buffer(buf), ec);
                std::cout << buf << std::endl;
//                std::cout.write(buf, len);

//                socket.write_some(buffer("Haha"), ec);

                // 如果出错，打印出错信息
                if(ec)
                {
                        std::cout << 
                                boost::system::system_error(ec).what() << std::endl;
                        break;
                }
                // 与当前客户交互完成后循环继续等待下一客户连接
        }
        return 0;
}
