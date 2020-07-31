//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);
//int pthread_join(pthread_t thread, void **retval);
//void pthread_exit(void *retval);

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

void* thread_return(void *args){

	char *hello="Hello World !";
	return (void*)hello;
}
int main(int argc, char const *argv[])
{
	char *str;
	pthread_t thread;

	pthread_create(&thread,NULL,thread_return,NULL);
	pthread_join(thread,(void**) &str);//store the returned value from thread in str
	printf("string is:%s\n",str );

	return 0;
}