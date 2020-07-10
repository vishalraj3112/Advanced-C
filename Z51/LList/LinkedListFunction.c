#include "LinkedList.h"


void insertAtBeginning(ListNodePtr *head,char val){
	ListNodePtr new_node=malloc(sizeof(node_t));
	new_node->data = val;
	new_node->nextPtr = *head;
	*head = new_node;
}

void insertAtEnd(ListNodePtr *head,char val){

	ListNodePtr current=*head;

		if(current != NULL){
			while(current->nextPtr!=NULL){
				current=current->nextPtr;//In the end this will be the last node
			}

			current->nextPtr=malloc(sizeof(node_t));
			current->nextPtr->data=val;
			current->nextPtr->nextPtr=NULL;
		}else
		{
			current=malloc(sizeof(node_t));
			current->data=val;
			current->nextPtr=NULL;
			*head=current;
		}
}

void printList(ListNodePtr currentPtr){

	if(currentPtr==NULL){
		printf("List is isEmpty\n");
	}
	else{
		printf("The list is:");

		while(currentPtr!=NULL){
			printf("%c-->",currentPtr->data );
			currentPtr= currentPtr->nextPtr;
		}
	}
}

void insertn(ListNodePtr *head,char value){

ListNodePtr previousPtr;
ListNodePtr currentPtr;
ListNodePtr newPtr;

//First creating the new data field

newPtr=malloc(sizeof(node_t));

if(newPtr!=NULL){

newPtr->data=value;
newPtr->nextPtr=NULL;

currentPtr=*head;
previousPtr=NULL;

while(currentPtr!=NULL && (currentPtr->data<value)){
    previousPtr=currentPtr;
    currentPtr=currentPtr->nextPtr;
}

if(previousPtr==NULL){
 newPtr->nextPtr=*head;
 *head=newPtr;

}else{
previousPtr->nextPtr=newPtr;
newPtr->nextPtr=currentPtr;
}

}else{
printf("No memory available for:%c!",value);
}
}


void deleteAtBeginning(ListNodePtr *head){

ListNodePtr tempPtr;
//just free the first pointer

if(head==NULL){
    return;
}else{
    tempPtr=*head;
    *head=(*head)->nextPtr;
    free(tempPtr);
    }

}


char delete(ListNodePtr *head,char value){

ListNodePtr previousPtr;
ListNodePtr currentPtr;
ListNodePtr tempPtr;

if(value==(*head)->data){

    tempPtr=*head;
    *head=(*head)->nextPtr;
    free(tempPtr);
    return value;
}else{

previousPtr=*head;
currentPtr=(*head)->nextPtr;

while(currentPtr!= NULL && currentPtr->data!=value){//traversing through the list

    previousPtr=currentPtr;
    currentPtr=currentPtr->nextPtr;
}

if(currentPtr!=NULL){

    tempPtr=currentPtr;
    currentPtr=currentPtr->nextPtr;
    free(tempPtr);
    return value;

        }
}

return '\0';

}


int isEmpty(ListNodePtr head){

    return head == NULL;

}

