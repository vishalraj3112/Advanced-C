#include <stdio.h>
#include <malloc.h>
//--- This program is a combination of variable length array and flexible array.

struct myStruct{
int length;
int myArray[]; //flexible array member
};

int main()
{
    int s;
    struct myStruct *m=NULL;

    printf("Enter the size of the array required:");
    scanf("%d",&s);

    size_t size=sizeof(struct myStruct);
    m=malloc(size+(sizeof(int)*s));

    for(int i=0;i<s;i++){//storing
        scanf("%d ",&(m->myArray[i]));
    }

    for(int i=0;i<s;i++){//printing
        printf("%d ",(m->myArray[i]));
    }

    return 0;

}
