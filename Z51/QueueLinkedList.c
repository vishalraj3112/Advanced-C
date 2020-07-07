#include<stdio.h>
#include<malloc.h>

struct QNode
{
	int key;
	struct QNode* next;
};

struct Queue{
	struct QNode *front,*rear;
};

struct QNode* newNode(int k){//helper function for creating new node
	struct QNode* temp=(struct QNode*)malloc(sizeof(struct QNode));
	temp->key=k;
	temp->next=NULL;
	return temp;
}

struct Queue* createQueue(){
	struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
	q->front=q->rear=NULL;//at the start the new node is both front and rear
	return q;
}

void enQueue(struct Queue* q, int k){

	struct QNode* temp=newNode(k);//done by helper function

	if(q->rear==NULL){//at the start is no other node is there then front and rare is the new node itself
		q->front=q->rear=temp;
		return;
	}

	//Add the new node at the end and change the rear
	q->rear->next=temp;
	q->rear=temp;
}

struct QNode* deQueue(struct Queue* q){

	if(q->front==NULL)
		return NULL;

	struct QNode* temp=q->front;
	q->front=q->front->next;//shift one node after
	
	if(q->front==NULL)//if last node is reached, then change the rear to null too	
		q->rear=NULL;

	return temp;

}

int main(){
	struct Queue *q=createQueue();//call the helper function

	enQueue(q,1);
	deQueue(q);
	enQueue(q,3);
	enQueue(q,4);
	enQueue(q,5);
	struct QNode* n=deQueue(q);
	if(n!=NULL){
		printf("Dequued item is:%d\n",n->key );
	}

	return 0;

}