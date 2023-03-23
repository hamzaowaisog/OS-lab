//k21-3247

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXSIZE 27

void die(char *str)
{
    perror(str);
    exit(1);
}

int main(void)
{
    int shmid;
    key_t key;
    char *shm, *s;

    key = 2211;
    fflush(stdin);
    if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
        die("shmget");
    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1)
        die("shmat");

    s = shm;
    int num = atoi(s);

    for (char *p = ready; *p != '\0'; p++)
    {
        *s++ = *p;
    }
    *s = '\0';
    s = shm;
    while (*s != '*')
        sleep(1);

    for (int i = 1; i <= 10; i++)
    {
        while (*s != '*')
            sleep(1);
        sprintf(s, "%d", i * num);
    }
    // printf("\n");
    exit(0);
}
