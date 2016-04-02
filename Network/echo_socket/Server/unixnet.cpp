#include"unixnet.h"
#include<iostream>
using namespace std;

int Socket(int family,int type,int protocol)
{
	int sockFd = socket(family,type,protocol);
	if (sockFd<0)
	{
		cerr<<"Socket create failed!"<<endl;
	}
	return sockFd;
}

int Connect(int sockfd,const struct sockaddr *servaddr,socklen_t addrlen)
{
	int n;
	if((n=connect(sockfd,servaddr,addrlen))<0)
	{
		cerr<<"Connect error!"<<endl;
	}
	return n;
}

int Inet_pton(int family,const char *strptr,void *addrptr)
{
	int n;
	if((n=inet_pton(family,strptr,addrptr))<=0)
	{
		cerr<<"Inet_pton error!"<<endl;
	}
	return n;
}

ssize_t writen(int fd,const void *vptr,size_t n)
{
	size_t nleft = n;
	size_t nwrite = 0;
	const char *pmsg = static_cast<const char*>(vptr);
	while(nleft)
	{
		if ((nwrite=write(fd,pmsg,nleft))<0)
		{
			cout<<"Didn't write"<<endl;
			if (nleft == n)
			{
				return -1;
			}
		}
		else
		{
			cout<<"write:"<<nwrite<<endl;
			nleft -= nwrite;
			pmsg += nwrite;
		}
	}
	return n;
}