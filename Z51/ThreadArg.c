//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);
//int pthread_join(pthread_t thread, void **retval);
//void pthread_exit(void *retval);

#include<stdio.h>
#include<pthread.h>

void* thread_for_printing(void *dataptr);

int main(void){

char *message1="Thread 1 !";
char *message2="Thread 2 !";

pthread_t thread1;
pthread_t thread2;

int iret1=0;
int iret2=0;

pthread_create(&thread1,NULL,thread_for_printing,(void*)message1);
pthread_create(&thread2,NULL,thread_for_printing,(void*)message2);

pthread_join(thread1,NULL);
pthread_join(thread2,NULL);

printf("Thread 1 returns:%d\n",iret1 );
printf("Thread 2 returns:%d\n",iret2 );

pthread_exit(NULL);



return 0;

}


void * thread_for_printing(void *dataptr){
char *message;
message=(char *)dataptr;

printf("%s\n",message );

}
