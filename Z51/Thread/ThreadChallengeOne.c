//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);
//int pthread_join(pthread_t thread, void **retval);
//void pthread_exit(void *retval);
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#define NTHREADS 10

int g=0;

pthread_mutex_t lock; //creating the mutex lock

void* threadFunction(void *ptr);

int main(){


	pthread_t tid[NTHREADS];
	int i=0,j=0;
	int array[]={0,1,2,3,4,5,6,7,8,9};

	if(pthread_mutex_init(&lock,NULL)!=0){
		printf("Lock creation error:\n");
		return 1;
	}

	for(i=0;i<NTHREADS;i++){
		pthread_create(&tid[i],NULL,threadFunction,(void*) array[i]);//change this without using argument
	}

	for(j=0;j<NTHREADS;j++){
		pthread_join(tid[j],NULL);
	}


	printf("Final count value:%d\n", g);

	return 0;

}

//***This implementation will not ensure mutual exclusion and multiple threads may be accessing the variables at the same time
//***on a shared resource.

// void* threadFunction(void* ptr){

// 	g++;

// 	printf("message from:%d Thread number:%ld variable modifyied:%d\n",(int*)ptr,pthread_self(),g);

// 	printf("message from:%d Thread number:%ld variable read:%d\n",(int*)ptr,pthread_self(),g);
	
// }

//*** To overcome the above issue, we do a mutex lock on the shared resource so that one thread can complete performing operation
//***first

void* threadFunction(void* ptr){

	pthread_mutex_lock(&lock);

	g++;

	printf("message from:%d Thread number:%ld variable modifyied:%d\n",(int*)ptr,pthread_self(),g);

	printf("message from:%d Thread number:%ld variable read:%d\n",(int*)ptr,pthread_self(),g);
	
	pthread_mutex_unlock(&lock);

	return NULL;


}