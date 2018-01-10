/* read input from client and print on screen on server*/

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

	printf("enter the message\n");
	scanf("%[^\n]",msg.mtext);

	int length = sizeof(msg.mtext)+1;
	msg.mtype = 1;
	if(msgsnd(key,&msg,length,0)<0)
		printf("error send");

}
