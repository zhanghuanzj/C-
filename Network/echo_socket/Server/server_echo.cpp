#include<iostream>
#include "unixnet.h"
using namespace std;

int server_echo(int sockfd)
{
	char msg[1000];
	int nread=0;
	cout<<"Begin to read"<<endl;
	while((nread=read(sockfd,msg,1000))>0)
	{
		cout<<"Receive:"<<nread<<endl;
		write(sockfd,msg,nread);
	}
	if (nread<0)
	{
		cout<<"server echo error!"<<endl;
	}
}
int main(int argc,char **argv)
{
	int listenSocket;
	listenSocket = Socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in servaddr,clientAddr;
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5577);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(listenSocket,(sockaddr*)&servaddr,sizeof(servaddr));
	listen(listenSocket,100);

	while(true)
	{
		socklen_t caddrlen = sizeof(clientAddr);
		cout<<"Ready"<<endl;
		int confd = accept(listenSocket,(sockaddr*)&clientAddr,&caddrlen);
		cout<<"Connected!"<<endl;
		if (fork()==0)
		{
			close(listenSocket);
			server_echo(confd);
			exit(0);                     //Auto close all fileDescription
		}
		close(confd);
	}
}
