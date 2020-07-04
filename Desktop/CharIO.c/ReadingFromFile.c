#include"MyHeader.h"

char ch='\0';
   FILE *fp;

void readingFromFile(){
   if(fp=fopen("CharFile.txt","rw")){


    while(ch!=EOF){
        ch=getc(fp);
        printf("%d",ch);
    }
    fclose(fp);
   }else{
   printf("Not found!");
   }

}
