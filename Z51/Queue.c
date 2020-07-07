#include<stdio.h>
#include<stdlib.h>

#define MAX 50

void enqueue();
void dequeue();
void display();

int queue_array[MAX];
int front=-1;
int rear=-1;

int main(){

	int choice;

	while(1){

		printf("Enter your choice:");
		scanf("%d",&choice);

		switch(choice){
			case 1:
			enqueue();
			break;
			case 2:
			dequeue();
			break;
			case 3:
			display();
			break;
			case 4:
			exit(1);

			default:
			printf("Wrong choice");
			break;
		}
	}
}


void enqueue(){//add from end

int add_item=0;

	if(rear==(MAX-1)){
		printf("Queue overflow");
	}else{
		if(front==-1)
			front=0;

		printf("Value to be inseted:");
		scanf("%d",&add_item);
		rear=rear+1;
		queue_array[rear]=add_item;
	}
}

void dequeue(){//remove from front
	if(front==-1 || front>rear){
		printf("Queue Underflow");
		return;
	}
	else{
		printf("Element deleted from queue:%d\n",queue_array[front]);
		front+=1;
	}
}

void display(){
	if(front==-1){
		printf("Queue is empty.\n");
	}else{
		printf("Queue is:\n");
		for(int i=front; i<=rear; i++)
			printf("%d ",queue_array[i]);
		printf("\n");
		printf("front:%d\n",front);
		printf("rear:%d\n",rear);
	}
}