#include <stdio.h>
#include <malloc.h>

typedef struct node{
	char data;//The date val of the list
	struct node *nextPtr;//self pointer of the node pointing to the next node
}node_t;

typedef node_t *ListNodePtr;

//void insert(ListNodePtr *head,char val);
void insertAtEnd(ListNodePtr *head,char val);
void insertAtBeginning(ListNodePtr *head,char val);
char delete(ListNodePtr *head,char val);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPtr);

int main(void){
	ListNodePtr head=NULL;
	int choice=0;
	char item='\0';

	printf("Enter your choice:\n");
	printf("::");
	scanf("%d",&choice);

	while(choice !=6){
		switch(choice){
			case 1:
				printf("Enter Character:\n");
				scanf("\n%c",&item);
				//insert(&head,item);
				printList(head);
				break;

			case 2:
				printf("Enter Character:\n");
				scanf("\n%c",&item);
				insertAtBeginning(&head,item);
				printList(head);
				break;

			case 3:
				printf("Enter Character:\n");
				scanf("\n%c",&item);
				insertAtEnd(&head,item);
				printList(head);
				break;

            case 4://deletting a character

                if(!isEmpty()){
                    printf("Enter a character to be deleted:");
                    scanf("%c",&item);

                    if(delete(&head,item)){
                        printf("%c is deleted",item);
                        printList(head);
                    }else{
                        printf("Character not found:%c !",item);
                    }
                }else{
                    prinf("List is empty !");
                }
                break;

			default:
				printf("invalid choice !\n");

		}

	printf("?\n");
	scanf("%d",&choice);

	}

	printf("End of run.\n");

	return 0;
}

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

void insert(ListNodePtr *head,char value){

ListNodePtr previousPtr;
ListNodePtr currentPtr;
ListNodePtr newPtr;

//First creating the new data field

newptr=malloc(sizeof(node_t));

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
