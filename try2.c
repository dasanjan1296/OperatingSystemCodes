#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

#define SHMKEY 75

int main()
{
	char *addr2;
	int key;
	if((key =shmget(SHMKEY,1024,0666|IPC_CREAT))<0)
		printf("error get\n"); 
	if((addr2 = shmat(key,0,0))<0)
		printf("error attach\n");
	int *ptr,i;
	ptr = (int*)addr2;	
	for(i=0;i<2;i++)
	{	
		printf("%d\n",*ptr);
		ptr++;
	}
}

