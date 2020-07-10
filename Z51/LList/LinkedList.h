#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdio.h>
#include <malloc.h>

typedef struct node{
	char data;//The date val of the list
	struct node *nextPtr;//self pointer of the node pointing to the next node
}node_t;

typedef node_t *ListNodePtr;

void insertn(ListNodePtr *head,char val);
void insertAtEnd(ListNodePtr *head,char val);
void insertAtBeginning(ListNodePtr *head,char val);
char delete(ListNodePtr *head,char val);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPtr);

#endif // _LINKED_LIST_H_
