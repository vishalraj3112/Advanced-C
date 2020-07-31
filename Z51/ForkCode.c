#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){

	int n1=0;
	int n2=0;

	n1=fork();
	n2=fork();

	if(n1>0 && n2>0){
		printf("Parent Process\n");
		printf("Parent process Id:%d\n",getpid());
		printf("Parent Parent process Id:%d\n",getppid());
	}

	else if(n1>0 && n2==0){
		printf("First Child Process id:%d\n",getpid());
		printf("First Child parent process Id:%d\n",getppid());
	}

	else if(n1==0 && n2>0){
		printf("Second Child Process id:%d\n",getpid());
		printf("Second Child parent process Id:%d\n",getppid());

	}

	else if(n1==0 && n2==0){
		printf("Third Child Process id:%d\n",getpid());
		printf("Third Child parent process Id:%d\n",getppid());

	}else{
		printf("Something Wrong\n");
	}

	return 0;

}