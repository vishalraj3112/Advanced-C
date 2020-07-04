#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *vptr=NULL;

    int i=5;
    float f=5.23;

    vptr=&i;//assigning to int type
    printf("Int is:%d\n",*(int *)vptr);//needs to be casted to a type while dereferencing it

    vptr=&f;
    printf("Float is:%0.2f\n",*(float*)vptr);

    return 0;
}
