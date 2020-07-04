#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a=10;
   int *p1;
   int **p2;//double pointer

   p1=&a;
   p2=&p1;

   printf("Address of a=%d\n",&a);
   printf("Address of p1=%d\n",&p1);
   printf("Address of p2=%d\n",&p2);

   printf("Value at the address *p2=%d\n",*p2);
   printf("Value at the address *p1=%d\n",*p1);
   printf("Value at the address **p2=%d\n",**p2);


    return 0;
}
