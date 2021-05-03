//
// Created by Singl on 2021/4/28.
//

#ifndef CPP_PRACTICE_TCPCLIENT_H
#define CPP_PRACTICE_TCPCLIENT_H

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "io_interface.h"

class TcpClient : public boost::enable_shared_from_this<TcpClient> {
 public:
  TcpClient(boost::asio::io_context &ioContext, boost::shared_ptr<IOInterface> ptr_io_interface);

  void Start(boost::asio::ip::basic_resolver_results<boost::asio::ip::tcp> remote);

  void SendMsg(const std::string msg, uint32_t msg_type);

  void Close();

 private:
  void HandleConnect(const boost::system::error_code &ec);
  void HandleRead(const boost::system::error_code &ec, size_t recv_size);

 private:
  boost::asio::strand<boost::asio::io_context::executor_type> strand_;
  boost::asio::ip::tcp::socket socket_;
  boost::shared_ptr<IOInterface> ptr_io_interface_;
  boost::asio::streambuf recv_buf_;
};

#endif //CPP_PRACTICE_TCPCLIENT_H
