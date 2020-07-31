#include "TCPHeader.h"

int main(int argc,char *argv[]){
	int socket_desc=0,sock=0,clientLen=0;
	struct sockaddr_in client;//client socket address
	char client_message[200]={0};//buffer for sending message to client
	char message[100]={0};
	const char pMessage[5] ="hello";

	socket_desc=socketCreate();
	if(socket_desc==-1){
		printf("Could not create socket\n");
		return 1;
	}
	printf("Socket Created !\n");

	if(bindCreateSocket(socket_desc)<0){
		perror("bind failed.");
		return 1;
	}

	printf("Bind done !\n");

	listen(socket_desc,3);//for 3 clients

	while(1){
		printf("Wainting for incoming connections...\n");
		clientLen=sizeof(struct sockaddr_in);

	sock=accept(socket_desc,(struct sockaddr*)&client,(socklen_t*)&clientLen);
	//sock is the new file descripter of the accepted socket
	if(sock<0){
		perror("accept failed");
		return 1;
	}

	printf("Connection accepted !\n");

	memset(client_message,'\0',sizeof client_message);
	memset(message,'\0',sizeof message);

	if(recv(sock,client_message,200,0)<0){
		printf("Recv Failed !\n");
		break;
	}

	printf("Client reply:%s\n",client_message );

	//if(strcmp(pMessage,client_message)==0){// ! NOTE:pointer and array can be compared !
		strcpy(message,"Hi there !");
	//}
	// else{
	// 	strcpy(message,"Invalid message !");
	// }

	if(send(sock,message,strlen(message),0)<0){
		printf("Sending Failed !\n");
		return 1;
	}

	close(sock);
	sleep(1);
	}

	return 0;
}