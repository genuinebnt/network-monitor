#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/system/error_code.hpp>

#include <iomanip>
#include <iostream>
#include <thread>

using tcp = boost::asio::ip::tcp;
namespace beast = boost::beast;
namespace net = boost::asio;

void Log(const std::string &where, boost::system::error_code ec) {
  std::cerr << "[" << std::setw(20) << where << ":"
            << std::this_thread::get_id() << "] " << (ec ? "Error: " : "OK")
            << (ec ? ec.message() : "") << std::endl;
}

int main() {
  net::io_context ioc{};

  tcp::socket socket{ioc};

  boost::system::error_code ec{};

  tcp::resolver resolver{ioc};
  auto address{"ltnm.learncppthroughprojects.com"};
  auto resolveIt{resolver.resolve(address, "80", ec)};
  if (ec) {
    Log("resolving", ec);
    return -1;
  }

  socket.connect(*resolveIt, ec);
  beast::websocket::stream<beast::tcp_stream> ws(std::move(socket));

  ws.handshake(address, "/echo");

  ws.write(net::buffer(std::string("Hello there")));
  beast::flat_buffer buffer;
  ws.read(buffer);
  if (ec) {
    Log("ws.handshake", ec);
    return -1;
  }

  std::cout << beast::make_printable(buffer.data()) << std::endl;

  ws.close(beast::websocket::close_code::normal);

  return 0;
}