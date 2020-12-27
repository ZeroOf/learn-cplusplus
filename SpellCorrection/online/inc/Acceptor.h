#ifndef __WIZ_ACCEPTOR_H__
#define __WIZ_ACCEPTOR_H__

#include "Socket.h"
#include "InetAddress.h"

namespace wiz
{
class Acceptor
{
public:
	Acceptor(int listenfd, const InetAddress &addr);
	void ready();
	int accept();

	int fd() const {return _listenSock.fd();}
private:
	void setReuseAddr(bool on);
	void setReusePort(bool on);
	void bind();
	void listen();
private:
	Socket _listenSock;
	InetAddress _addr;
};

}
#endif
