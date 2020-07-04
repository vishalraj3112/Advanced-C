#include"MyHeader.h"

void writeUsingPutC(){

char ch='v';

putc(ch,stdout);


}

void writeUsingPutChar(){

char string[]="Hello Vishal,\n NewLine";

int i=0;

while(string[i]!='\0'){

    if(string[i]!='\n')
        putchar(string[i]);//printing on console

    ++i;
}

}

void writeUsingFputc(){

FILE *pFile =NULL;
char c='\0';

pFile=fopen("myFile.txt","w");

if(pFile!=NULL){
    for(c='A';c<='Z';c++)
    fputc(c,pFile); //or fputc(c,stdout);


    fclose(pFile);
    }

}
