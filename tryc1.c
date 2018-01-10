#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>

struct message
{
	int mtype;
	char mtext[256];
}msg;

#define MSGKEY 77

int key;

int main()
{
	if((key = msgget(77,0777|IPC_CREAT))<0)
		printf("error get\n");
	//struct message msg;
	msg.mtype = 1;
	*msg.mtext = 100;
	//int *ptr;
	//ptr = (int*)msg.mesg;
	//*ptr = 100;
	if(msgsnd(key,&msg,sizeof(int),0)<0)
		printf("error send\n");
	printf("%d \t %d\t",msg.mtype,*msg.mtext);
}

