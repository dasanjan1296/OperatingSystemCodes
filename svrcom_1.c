#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>

#define SYSKEY 1111

#define K 1024

main()
{

	int id;
	char *s,*shmid;
	
	id = shmget(SYSKEY,56*K,0777|IPC_CREAT);
	shmid = shmat(id, NULL, 0);

	s = shmid;

	while(*s!='\0')
		printf("%c \n",*s++);
	
	*s='*';

	while(*s!='!')
		sleep(1);

	printf("\n Server synchronized\n");
	
}
