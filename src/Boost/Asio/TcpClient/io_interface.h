//
// Created by God on 2021/5/3.
//

#ifndef CPP_PRACTICE_SRC_BOOST_ASIO_TCPCLIENT_IO_HEADER_H_
#define CPP_PRACTICE_SRC_BOOST_ASIO_TCPCLIENT_IO_HEADER_H_

#include <string>
#include <boost/enable_shared_from_this.hpp>

class IOInterface : public boost::enable_shared_from_this<IOInterface> {
 public:
  virtual void OnRead(boost::system::error_code ec, std::vector<char> msg) = 0;
  virtual void OnConnected() = 0;
  virtual void OnConnectFailed() = 0;
  virtual void OnSend(bool is_success, uint32_t size, uint32_t msgType) = 0;
  virtual bool IsPackageComplate(boost::asio::streambuf) = 0;
  virtual void OnClose() = 0;
};

#endif //CPP_PRACTICE_SRC_BOOST_ASIO_TCPCLIENT_IO_HEADER_H_
