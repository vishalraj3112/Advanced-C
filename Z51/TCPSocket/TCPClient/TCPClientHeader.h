#ifndef _TCP_CLIENT_HEADER_H_
#define _TCP_CLIENT_HEADER_H_

#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

short socketCreate(void);
int socketConnect(int hSocket);
int socketSend(int hSocket,char *Rqst,short lenRqst);
int socketReceive(int hSocket,char *Rsp,short RvcSize);


#endif