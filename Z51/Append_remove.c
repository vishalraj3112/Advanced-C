#include<stdio.h>
#include<stdlib.h>
//#include<string.h>

#define MAX_TRIP_COND 7
#define MAX_TRIP_LNT 4

char charArray[MAX_TRIP_COND][MAX_TRIP_LNT]={"R.tc","OC","UC","LC","OV","UV","PHL"};
char messageString[30]={"This is the trip status:"};
char stringArray[MAX_TRIP_LNT]={0};//temp string

int tripPos = 0; //current trip status

int main(){

printf("%s\n",messageString);

//By using String concat function
// for(int i=0; i < 2; i++)
// stringArray[i] = charArray[1][i];
// strcat(messageString,stringArray);

 int size_of_messageString = (int)(sizeof(messageString)-6);

//for (int i = 0; i < MAX_TRIP_COND; i++){ //For printing out all trip conditions
	for(int j=0; j < MAX_TRIP_LNT; j++){	
		messageString[size_of_messageString+j] = charArray[/*i*/tripPos][j];
	}
	printf("%s\n",messageString);
//}

return 0;
}