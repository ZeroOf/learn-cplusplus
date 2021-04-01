#include "Socket.h"
#include "SocketUtil.h"
#include "InetAddress.h"

namespace wiz
{

Socket::Socket(int sockfd)
: _sockfd(sockfd)
{}

Socket::Socket()
: _sockfd(createSocketFd())
{}

Socket::~Socket()
{
	::close(_sockfd);
}

void Socket::nonblock()
{
	setNonblock(_sockfd);
}
void Socket::shutdownWrite()
{
	if(::shutdown(_sockfd, SHUT_WR) == -1){
		perror("shutdown write error!");
	}
}
InetAddress Socket::getLocalAddr(int sockfd)
{
	struct sockaddr_in addr;
	socklen_t len = sizeof(sockaddr_in);
	if(::getsockname(sockfd,(struct sockaddr *)&addr, &len) == -1){
		perror("getsockname error");
	}
	return InetAddress(addr);
}
InetAddress Socket::getPeerAddr(int sockfd)
{
	struct sockaddr_in addr;
	socklen_t len = sizeof(sockaddr_in);
	if(::getpeername(sockfd, (struct sockaddr*) &addr, &len) == -1){
		perror("getpeername error");		
	}
	return InetAddress(addr);
}
}
