#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

//void (*signal( int sig, void (*handler) (int))) (int); this is prototype of signal in signal.h

void handler_dividebyzero(int signnum);//this is the prototype of the handler function, takes only the int signal number


int main()
{

    int result = 0;
    int v1=0,v2=0;
    int signum2=5;

    void (*signalHandlerReturn)(int);//this is the function pointer required for signal() function, it
                                    //takes only int which is the result of signal() function

    signalHandlerReturn =signal(SIGFPE, handler_dividebyzero);//here no & is required since parameter in signal is a pointer

    if(signalHandlerReturn==SIG_ERR){
        perror("Signal error:");
      // printf("signalHandlerReturn:%d",signalHandlerReturn);
        return 1;
    }

    //raise(signum2);//both cant be raised simultaniously
    //signal(signum2,handler_dividebyzero);
    v1=121;
    v2=0;
    result=v1/v2;

        return 0;
}


void handler_dividebyzero(int signum){

if(signum==SIGFPE)//floating point value
{

    printf("Received sigfpe, divide by zero error !");
    exit(0);
}else if(signum==5){

    printf("Signum 2!");
    exit(0) ;
}else{

printf("none !");

}

}
