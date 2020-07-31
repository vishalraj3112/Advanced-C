#include "TCPClientHeader.h"

//Steps-->
//1.Socket()
//2.Bind()
//3.Listen()
//4.Accept()
//5.Connect()
//6.Send()
//7.Receive()
//8.Close()
//For Client->
//Socket()
//Connect()
//Send/Receive

int main(int argc,char* argv[]){
	int hSocket=0,read_size=0;
	struct sockaddr_in server;
	char sendToServer[100]={0};
//	char server_reply[200]={0};

	hSocket=socketCreate();

	if(hSocket == -1){
		printf("Could not create socket\n");
		return 1;
	}

	printf("Socket is created\n" );

	if(socketConnect(hSocket)<0){
		perror("connect failed.\n");
		return 1;
	}

	printf("Successfully connected with server\n");
	printf("Enter the Number:\n");
	fgets(sendToServer,100,stdin);

	socketSend(hSocket,sendToServer,strlen(sendToServer));

	//read_size=socketReceive(hSocket,server_reply,200);
	//printf("Server Response:%s\n",server_reply );

	close(hSocket);

}




