#include <stdio.h>

struct packed_struct {
unsigned int:3; //unused bits
unsigned int f1:1;//size of field
unsigned int f2:1;//size of field
unsigned int f3:1;//size of field
unsigned int type:8;
unsigned int index:18;
};

int main(){

    struct packed_struct packed_data={.f1=1,.index=200};

    packed_data.type=248;

    int data=packed_data.type;//accessing the field member

    printf("%d\n",data);

    if(packed_data.f1){
        printf("F1 is Set !\n");
    }

    printf("%d ",packed_data.index);

}
