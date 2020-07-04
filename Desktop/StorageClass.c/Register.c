#include<stdio.h>

void registerFunction(){

register int number = 10;//register type variable has to be declared withing a function,not global

printf("register_var:%d",number);

}
