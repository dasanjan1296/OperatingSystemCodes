#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

#define SHMKEY 75
#define K 1024
int shmid;

main()
{
	int i,*pint;
	char *addr1,*addr2;
	//extern char *shmat();
	//extern cleanup();
	
	//for(i=0;i<20;i++)
	//	signal(i,cleanup);

	shmid = shmget(SHMKEY,128*K,0777|IPC_CREAT);
	addr1 = shmat(shmid,0,0);
	addr2 = shmat(shmid,0,0);
	printf("addr1  %x  addr2 %x \n",addr1, addr2);
	pint = (int*) addr1;

	for(i=0;i<256;i++)
	{
		*pint = i;
		pint++;
	}

	pint = (int*)addr1;
	*pint = 256;

	pint = (int*)addr2;
	for(i=0;i<256;i++)
		printf("index %d \t value %d\n",i,*pint++);

	pause();	
}
