#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>

#define SHMKEY 1234

#define K 1024

main()
{

	int id;
	char *c,*shmid;
	
	id = shmget(SHMKEY,64*K,0777|IPC_CREAT);
	shmid = shmat(id,NULL,0);

	c= shmid;
	
	while(*c!='\0')	
	{
		printf("%c\n",*c++);
	}
}
