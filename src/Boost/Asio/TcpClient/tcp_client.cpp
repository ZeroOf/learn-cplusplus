//
// Created by Singl on 2021/4/28.
//

#include "tcp_client.h"
#include <boost/bind/bind.hpp>
#include <iostream>

TcpClient::TcpClient(boost::asio::io_context &ioContext, boost::shared_ptr<IOInterface> ptr_io_interface)
    : strand_(ioContext.get_executor()), socket_(ioContext) {
  socket_.set_option(boost::asio::socket_base::reuse_address(true));
}

void TcpClient::HandleConnect(const boost::system::error_code &ec) {
  std::cout << __FUNCTION__ << std::endl;
  if (ec) {
    ptr_io_interface_->OnConnectFailed();
    return;
  }
  ptr_io_interface_->OnConnected();
  boost::asio::async_read(
      socket_, recv_buf_, boost::asio::bind_executor(
          strand_, boost::bind(
              &TcpClient::HandleRead, shared_from_this(), boost::placeholders::_1, boost::placeholders::_2)),
      boost::bind(&IOInterface::IsPackageComplate, ptr_io_interface_));
}

void TcpClient::Start(boost::asio::ip::basic_resolver_results<boost::asio::ip::tcp> remote) {
  std::cout << __func__ << std::endl;
  boost::asio::async_connect(
      socket_, remote, boost::asio::bind_executor(
          strand_, boost::bind(&TcpClient::HandleConnect, shared_from_this(), boost::placeholders::_1)));

}
void TcpClient::HandleRead(const boost::system::error_code &ec, size_t recv_size) {
  std::istream input(&recv_buf_);
  std::vector<char> input_buf(recv_size);
  input.readsome(input_buf.data(), recv_size);
  ptr_io_interface_->OnRead(ec, std::move(input_buf));
}
void TcpClient::Close() {
  socket_.cancel();
  socket_.close();
  ptr_io_interface_->OnClose();
}
void TcpClient::SendMsg(const std::string msg, uint32_t msg_type) {
  socket_.async_send(
      boost::asio::buffer(msg), boost::asio::bind_executor(
          strand_, boost::bind(
              &IOInterface::OnSend, ptr_io_interface_, boost::placeholders::_1, boost::placeholders::_2, msg_type)));
}
