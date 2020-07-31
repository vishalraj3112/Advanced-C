#include "TCPHeader.h"

short socketCreate(void){
	short hSocket;
	printf("Creating the socket\n");
	hSocket=socket(AF_INET,SOCK_STREAM,0);
	return hSocket;
}

int bindCreateSocket(int hSocket){
	int iRetval=-1;
	int clientPort=12345;

	struct sockaddr_in remote = {0};

	remote.sin_family=AF_INET;
	remote.sin_addr.s_addr=htonl(INADDR_ANY);
	remote.sin_port=htons(clientPort);

	iRetval=bind(hSocket,(struct sockaddr*)&remote,sizeof(remote));

	return iRetval;
}


