#ifndef UNIXNET_H
#define UNIXNET_H

#include<unistd.h>    				//read,write
#include<sys/socket.h> 				//socket,connect,sockaddr
#include<arpa/inet.h>               //inet_pton,inet_ntop 
#include<netinet/in.h>              //sockaddr_in  
#include<string.h>                  //strlen
#include<strings.h>                 //bzero
#include<sys/types.h>               //socklen_t
#include<stdlib.h>                  //exit()
#include<stdio.h>

int Socket(int family,int type,int protocol);
int Connect(int sockfd,const struct sockaddr *servaddr,socklen_t addrlen);
int Inet_pton(int family,const char *strptr,void *addrptr);
ssize_t writen(int fd,const void *vptr,size_t n);
#endif