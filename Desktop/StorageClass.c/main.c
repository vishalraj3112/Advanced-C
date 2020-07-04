#include <stdio.h>

void registerFunction();//prototype

static int static_global_variable;//This variable cannot be externed and only used in this file.


static int foo(){//This function cannot be accessed from another file.

static int static_var=0;//allocated on heap not on stack
int auto_variable=0;

printf("auto=%d , static=%d\n",auto_variable,static_var);

auto_variable++;//This variable is going to be created on every call
static_var++;//This local variable is going to retain its value

return static_var;

}


int main()
{
    for(int i=0;i <5; i++){

        foo();
    }

    registerFunction();


    return 0;
}
