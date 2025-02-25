//writer process

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
void main()
{
    char str[100];
    int fd,nbw;
    mknod("myfifo",S_IFIFO|0666,0);
    printf("Writing for writer process\n");
    fd=open("myfifo",O_WRONLY);
    while(gets(str))
    {
      nbw=write(fd,str,strlen(str));
      printf("Writes %d bytes %s\n",nbw,str);
    }
}


//reader process

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
void main()
{
    char arr[100];
    int fd,nbr;
    mknod("myfifo",S_IFIFO|0666,0);
    printf("Reading for reader process\n");
    fd=open("myfifo",O_RDONLY);
    do
    {
      nbr=read(fd,arr,sizeof(arr));
      arr[nbr]='\0';
      printf("Reads %d bytes %s",nbr,arr);
    }while(nbr>0);
}
