#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

#define SHMKEY 75

int main()
{

int key = shmget(SHMKEY,1024,0666|IPC_CREAT);
char *addr1;
addr1 = shmat(key,0,0);
int *ptr;
ptr =(int*)addr1;

*ptr = 100;
ptr++;
*ptr = 105;
//printf("%d",*addr1);

}
