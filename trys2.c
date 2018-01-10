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

int main()
{
	int key;
	if((key=msgget(MSGKEY,0777|IPC_CREAT))<0)
		printf("error get");

	if(msgrcv(key,&msg,512,0,0)<0)
		printf("error receive");

	printf("received message is \n %s\n",msg.mtext);

}
