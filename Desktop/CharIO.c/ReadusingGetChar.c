#include"MyHeader.h"

void readingusingGetChar(){
int ch;

while((ch=getchar())!=EOF)
    printf("%c\n",ch);

}//press Ctrl+Z to exit this function

void readingUnGetC(){
char ch=0;

while(isspace(ch=(char)getchar()));
ungetc(ch,stdin); //unget i.e put back the letter for later processing

printf("Character returned to stdin is:%c\n",getchar());

}
