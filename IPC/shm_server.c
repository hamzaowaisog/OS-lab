#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 27


int main(void) {
	char c;
	int shmid;
	key_t key;
	char *shm, *s;

	key = 2211;
	
	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
		exit(0);
	if((shm = shmat(shmid, NULL, 0)) == (char*) -1)
		exit(0);
	s = shm;
	for(c = 'a'; c <= 'z'; c++) 
		*s++ = c;

	while(*shm != '\0')
		sleep(1);

	exit(0);
}

