#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>

#define MSGKEY 77

struct message
{
	int mtype;
	char mtext[256];
}msg;

int key;

int main()
{

	//struct message msg;
	if((key = msgget(77, 0777|IPC_CREAT))<0)
		printf("error get\n");
	if (msgrcv(key,&msg,256,0,0)<0)
		printf("error receive\n");
	printf("%d",*msg.mtext);
}

