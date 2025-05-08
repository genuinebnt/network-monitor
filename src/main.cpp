#include <iostream>
#include <boost/asio.hpp>

int main() {
    boost::system::error_code ec{};
    if(ec) {
        std::cerr << "Error: " << ec.message() << std::endl;
    } else {
        std::cout << "OK" << std::endl;
        return 0;
    }
}
