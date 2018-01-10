#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>
#define MSGKEY 79

struct message
{
	int mtype;
	char mtext[256];
}msg;

int main()
{
	int key;
	if((key=msgget(MSGKEY,0777|IPC_CREAT))<0)
		printf("error get\n");
	
	if(msgrcv(key,&msg,512,0,0)<0)
		printf("error receive\n");

	printf("message received is %s\n",msg.mtext);
	struct message msg2;
	msg2.mtype = 100;
	
	int length = sizeof(msg.mtext)+1;
	strcpy(msg2.mtext,msg.mtext);

	if(msgsnd(key,&msg2,length,0)<0)
		printf("error send\n");
	printf("message sent");
}
	
