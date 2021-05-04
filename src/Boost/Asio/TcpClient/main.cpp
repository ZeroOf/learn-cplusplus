//
// Created by God on 2021/5/1.
//

#include "tcp_client.h"
#include <boost/make_shared.hpp>
#include "test_client.h"

boost::shared_ptr<TcpIO::TestClient> Start(boost::asio::io_context &ioContext);

int main() {
    boost::asio::io_context ioContext;
    auto pC = Start(ioContext);
    ioContext.run();
}

boost::shared_ptr<TcpIO::TestClient> Start(boost::asio::io_context &ioContext) {
    boost::shared_ptr<TcpIO::TestClient> pClient = boost::make_shared<TcpIO::TestClient>(ioContext, "127.0.0.1",
                                                                                         "1133");
    pClient->Start();
    return pClient;
}
