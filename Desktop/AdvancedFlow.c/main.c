#include <stdio.h>


int main()
{
    int count=5;
    int count_left_star=0;

    for(int i=1;i<=5;i++){
        for(int j=1;j<=count;j++){
            if(j==count){
                printf("*");
            }else if((j==(count-count_left_star))||(i==5)){
            printf("*");
            }else{
                printf(" ");
            }

        }
        printf("\n");
        count++;
        count_left_star+=2;

    }

    //comma operator
    for(i=0,j=100;i!=10;++i,j-=10){
        //Here single for loop is used for performing both
        //expression evaluation of i and j simultaniously.
    }

}
