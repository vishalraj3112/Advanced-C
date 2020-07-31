#include "LinkedList.h"

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
				insertn(&head,item);
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

            case 4://deleting a character

                if(!isEmpty(head)){
                    printf("Enter a character to be deleted:");
                    scanf("%c",&item);

                    if(delete(&head,item)){
                        printf("%c is deleted",item);
                        printList(head);
                    }else{
                        printf("Character not found:%c !",item);
                    }
                }else{
                    printf("List is empty !");
                }
                break;

			default:
				printf("invalid choice !\n");
				break;

		}

	printf("?\n");
	scanf("%d",&choice);

	}

	printf("End of run.\n");

	return 0;
}

