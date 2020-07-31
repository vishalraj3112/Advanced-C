#include "TCPClientHeader.h"

short socketCreate(void){
	short hSocket;
	printf("Creating the socket !\n");
	hSocket=socket(AF_INET,SOCK_STREAM,0);
	return hSocket;
}

int socketConnect(int hSocket){
	int iRetval=-1;
	int ServerPort = 12345;

	struct sockaddr_in remote={0};
	remote.sin_addr.s_addr=inet_addr("127.0.0.1");//local host address
	remote.sin_family=AF_INET;
	remote.sin_port=htons(ServerPort);
	iRetval=connect(hSocket,(struct sockaddr *)&remote,sizeof(struct sockaddr_in));
	return iRetval;
}

int socketSend(int hSocket,char *Rqst,short lenRqst){
	int shortRetval=-1;
	struct timeval tv;
	tv.tv_sec=20;
	tv.tv_usec=0;

	if(setsockopt(hSocket,SOL_SOCKET,SO_SNDTIMEO,(char*)&tv,sizeof(tv))) {
		printf("Time Out\n");
		return -1;
	}

	shortRetval=send(hSocket,Rqst,lenRqst,0);
	return shortRetval;
}

int socketReceive(int hSocket,char *Rsp,short RvcSize){
	int shortRetval=-1;
	struct timeval tv;
	tv.tv_sec=20;
	tv.tv_usec=0;

	if(setsockopt(hSocket,SOL_SOCKET,SO_RCVTIMEO,(char*)&tv,sizeof(tv))) {
		printf("Time Out\n");
		return -1;
	}

	shortRetval=recv(hSocket,Rsp,RvcSize,0);
	//printf("Response:%s\n",Rsp );

	return shortRetval;
}

