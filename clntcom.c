#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>

#define SYSKEY 1111

#define K 1024

main()
{
	int id;
	char *shmid,*s;
	
	id = shmget(SYSKEY, 64*K, 0777|IPC_CREAT);
	shmid = shmat(id, NULL, 0);

	s = shmid;
	char c='a';
	while(c!='z')
		*s++ = c++;

	while(*s!='*');
		sleep(1);

	printf("\n client Synchronized\n");

	*s='!';

	shmdt(shmid);
}

