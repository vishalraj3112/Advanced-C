#include <stdio.h>
#include <malloc.h>
#include <string.h>

void foo(int *ptr){

	int a=5;
	ptr=&a;
}

//Solution to the above problem -using double pointer to
//change the location of what the pointer is pointing and not
//what the value of pointer's pointing value is.
void fooone(int **ptr){

	int a=5;
	*ptr=&a;

}
//other use is of using the double pointer for function
void footwo(char ** ptr){

	*ptr=malloc(255);
	strcpy(*ptr,"Hello World");

}
int main(){

	int *ptr=NULL;
	char *ptr1=NULL;

	ptr=(int *)malloc(sizeof(int));//allocating memory to 1st copy of*ptr
	*ptr=10;
	foo(ptr);//pass by reference
//*** This is the concept of pass by reference, here the value assigned
//***to *ptr will not change as only the local copy is modifyied	
	printf("%d\n",*ptr );
//Now trying with double pointer
	fooone(&ptr);
	printf("%d\n",*ptr );
	
	//other use
	footwo(&ptr1);
	printf("%s\n",ptr1 );//no dereference required since it is a string

	free(ptr1);

	return 0;
}