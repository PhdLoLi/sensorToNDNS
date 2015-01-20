#include <iostream>
#include <boost/asio.hpp>

int main(int argc, char* argv[])
{
 //       using namespace boost::asio;

        // 所有asio类都需要io_service对象
  boost::asio::io_service iosev;
  boost::asio::ip::tcp::socket socket(iosev);
  boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::from_string("127.0.0.1"), 1000);
  boost::system::error_code ec;
  socket.connect(ep,ec);
  if(ec)
  {
    std::cout << boost::system::system_error(ec).what() << std::endl;
    return -1;
  }
  //Send data
  socket.write_some(boost::asio::buffer("hello world!"), ec);
  // 接收数据
//  char buf[100];
//  size_t len=socket.read_some(buffer(buf), ec);
// std::cout.write(buf, len);

  return 0;
}
