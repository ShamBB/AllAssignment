#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
int main(){

struct stat st;
stat("alphabet.txt", &st);
int size = (st.st_size-1);

unsigned char buffer[size];
FILE *ptr;
ptr = fopen("test.bin","rb");  // r for read, b for binary

FILE *file;
file = fopen("reverse.txt","w");
if(file == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}

if (ptr == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}

fread(buffer,sizeof(buffer),1,ptr); 


for(int i = size-1; i>=0; i--){
    fprintf(file,"%c",buffer[i]);
    
}

fclose(ptr);

}

