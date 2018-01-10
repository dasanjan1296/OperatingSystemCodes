/*Read a value from client, send it to server
Server will receive and return back the value to client*/

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>

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

	printf("enter the message\n");
	scanf("%[^\n]",msg.mtext);
	int length = sizeof(msg.mtext)+1;
	msg.mtype=1;
	
	if(msgsnd(key,&msg,length,0)<0)
		printf("error send\n");
	printf("message sent");

	if(msgrcv(key,&msg,512,100,0)<0)
		printf("error receive\n");

	printf("received message is %s\n",msg.mtext);
}
	
