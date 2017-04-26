#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/stat.h>

int main(){


struct stat st;
stat("alphabet.txt", &st);	//get the size of alphabet text
int size = (st.st_size-1);

unsigned char buffer[size];	//declare char array with alphabet text size

FILE *write_ptr;			//create file
write_ptr = fopen("test.bin","wb"); 	//create file

FILE *file;
file = fopen("alphabet.txt","r");

if(write_ptr == NULL)			
{
    printf("Error opening file!\n");
    exit(1);
}

if (file == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}

fread(buffer,sizeof(buffer),1,file); 	//read file alphabet and store it in buffer char array

for(int i=0;i<size;i++)			
	printf("%c",buffer[i]);		//check buffer element


fwrite(buffer,sizeof(buffer), 1, write_ptr );	//create file test in binary 

fclose(write_ptr);
fclose(file);


}


