#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>

#define SHMKEY 1234
#define K 1024
main()
{
	int id;
	char *c, *shmid;
	char s;
	id = shmget(SHMKEY,64*K,0777|IPC_CREAT);
	shmid = shmat(id,NULL,0);

	c=shmid;
	
	for(s='a';s<'z';s++)
		*c++ = s;
	
}	
