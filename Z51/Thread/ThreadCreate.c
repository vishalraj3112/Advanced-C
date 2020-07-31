//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);
//int pthread_join(pthread_t thread, void **retval);
//void pthread_exit(void *retval);
//*********-----Protytypes of thread creation funtions
#include<stdio.h>
#include<pthread.h>

void * thread_1_function(){//function of thread execution

	printf("In Thread 1 !\n");
	return NULL;

}

int main(int argc,char * argv[]){
	pthread_t thread =0;
	pthread_create(&thread,NULL,thread_1_function,NULL);//create the thread
	pthread_join(thread,NULL);//wait for the particular thread to complete exceution and join
	pthread_exit(NULL);//exit all the threads after completion 
	return 0;
}

//to execute use this command---> gcc -o threadCreate ThreadCreate.c -l pthread
