//
// Created by God on 2021/5/1.
//

#include "tcp_client.h"
#include <boost/make_shared.hpp>

int main() {
    boost::asio::io_context ioContext;
    boost::asio::ip::tcp::resolver resolver(ioContext);
    resolver.async_resolve("192.168.223.78", "22", [&ioContext](const boost::system::error_code &ec,
                                                             boost::asio::ip::tcp::resolver::results_type remote) {
        boost::shared_ptr<TcpClient> tcpClient = boost::make_shared<TcpClient>(ioContext);
        tcpClient->Start(remote);
    });
    ioContext.run();
}