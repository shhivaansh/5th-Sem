//writer

#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>

struct msgbuff{
  long mtype;
  char mtext[100];
}mb;

int main(){
  key_t key;
  int msgid,c;
  key=ftok("progfile",'A');
  msgid=msgget(key,0666|IPC_CREAT);
  mb.mtype=1;
  printf("\nEnter a string : ");
  gets(mb.mtext);
  c=msgsnd(msgid,&mb,strlen(mb.mtext),0);
  printf("Sender wrote : \t%s\n",mb.mtext);
  return 0;
}

//reader
#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>

struct msgbuff{
  long mtype;
  char mtext[100];
}mb;

int main(){
  key_t key;
  int msgid,c;
  key=ftok("progfile",'A');
  msgid=msgget(key,0666|IPC_CREAT);
  msgrcv(msgid,&mb,sizeof(mb),1,0);
  printf("Data Received is:\t%s\n",mb.mtext);
  msgctl(msgid,IPC_RMID,NULL);
  return 0;
}
