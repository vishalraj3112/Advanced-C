#include <stdio.h>

#define MAXSIZE 5

struct stack{
 int stk[MAXSIZE];
 int top;

};

typedef struct stack STACK;

STACK s;

void push(void);
int pop(void);
void display(void);

int main()
{
    int options=1;
    int choice;
    s.top=-1;

    while(options){
        printf("Enter you choice:");
        scanf("%d",&choice);

        switch(choice){
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            return;
        }

        fflush(stdin);
        printf("Do you want to continue(0/1)");
        scanf("%d",&options);
    }

    return 0;
}

void push(){

int num;
    if(s.top==(MAXSIZE-1)){//if s.top==4

        printf("Stack is full\n");
        return;

    }else{
        printf("Enter the element to be pushed:");
        scanf("%d",&num);
        s.top=s.top+1;//initially -1 will become 0
        s.stk[s.top]=num;
    }
return;
}


int pop(){
    int num;
    if(s.top==-1){
        printf("List is Empty !");
    }else{
        num=s.stk[s.top];
        printf("Popped element:%d",s.stk[s.top]);
        s.top-=1;
    }

    return num;
}

void display(){
    int i=0;
    if(s.top==-1){
        printf("Stack is empty\n");
        return;
    }else{
        printf("\n The status of stack is:\n");
        for(i=s.top;i>=0;i--){

            printf("%d\n",s.stk[i]);
        }

    }
    printf("\n");
}





