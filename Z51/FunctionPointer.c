#include<stdio.h>

void funct1(int);
void funct2(int);

typedef void FuncType(int);//FuncType is any function with return void and parameter int


int main(){

	FuncType *funct_ptr=NULL;//instatiating function pointer
	//Same typedef is used for function pointer and normal function since both need to be same

	funct_ptr=&funct1;//assigning function pointer(not necessary to use &)
	//funct_ptr=funct1; is also okay
	printf("Address of function pointer:%d\n",funct1);
	printf("Address of function pointer:%d\n",&funct1);

	//calling the function
	(*funct_ptr)(100);

	funct_ptr=funct2;

	(*funct_ptr)(200);

}

void funct1(int a){

	printf("funct1 variable is:%d\n",a );
}

void funct2(int a){

	printf("funct2 variable:%d\n", a);

}