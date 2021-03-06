#include<iostream>
#include "unixnet.h"
using namespace std;

int client_echo(int sockfd)
{
	char msg[1000];
	cout<<"Input string to echo:"<<endl;
	while(cin>>msg)
	{
		size_t nleft = strlen(msg);
		size_t nwrite = 0;
		writen(sockfd,msg,nleft);
		cout<<"wating for echo"<<endl;
		if((nwrite=read(sockfd,msg,1000))>0)
		{
			cout<<msg<<endl;
		}
		cout<<"input another!"<<endl;
	}
}
int main(int argc,char **argv)
{
	if(argc!=2)
	{
		cerr<<"usage: a.out <Server IP address>"<<endl;
	}
	int clientSocket;
	clientSocket = Socket(AF_INET,SOCK_STREAM,0);
	
	struct sockaddr_in servaddr;
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5577);
	Inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
	
	Connect(clientSocket,(sockaddr*)&servaddr,sizeof(servaddr));

    client_echo( clientSocket);
	    
}
