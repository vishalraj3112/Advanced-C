#ifndef _TCP_HEADER_H_
#define _TCP_HEADER_H_

#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

short socketCreate(void);

int bindCreateSocket(int hSocket);

#endif //_TCP_HEADER_H_