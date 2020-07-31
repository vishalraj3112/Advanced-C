#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game(int sig){
	printf("\nFinal Score:%d",score);
	exit(0);
}

void error(char * msg){
	fprintf(stderr, "%s:%s\n",msg,strerror(errno) );
	exit(1);
}

void delay_handler(int sig){
	printf("\nTime Up !\n");
	raise(SIGINT);//to use the same function end_game, this was done
}

int main(){

	signal(SIGINT,end_game);//Installing the handler first
	signal(SIGALRM,delay_handler);//installing alarm handler

	srand(time(0));

	while(1){
		int a =rand() % 11;
		int b= rand() % 11;

		char txt[4];

		printf("\nWhat is %d times %d:",a,b);
		
		alarm(5);//Start the alarm as soon as question is priting,
		         //and reset it everytime after new question is printed

		fgets(txt,4,stdin);

		int answer = atoi(txt);

		if(answer== a*b){
			score ++;	
		}else{
			printf("\nWrong\n");
			
		}


	}

	return 0;
}