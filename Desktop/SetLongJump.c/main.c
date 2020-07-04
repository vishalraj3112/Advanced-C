#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;

void myFunction(){
printf("In my function\n");

longjmp(buf,1);//just like throw in c++

//This point is not reached
printf("This point is never reached due to longjump\n");


}

int main()
{
    if(setjmp(buf))//just like try in c++
        printf("back in main\n");
    else{
    printf("first time through\n");
    myFunction();
    }
    return 0;
}
