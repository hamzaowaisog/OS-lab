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

    int shmid2;
    key_t key2;
    char *shm2, *s2;

    key2 = 1122;
    fflush(stdin);
    if ((shmid2 = shmget(key2, MAXSIZE, IPC_CREAT | 0666)) < 0)
        die("shmget");
    if ((shm2 = shmat(shmid2, NULL, 0)) == (char *)-1)
        die("shmat");

    s2 = shm2;

    int n;
    printf("Enter number of iterations: ");
    scanf("%d", &n);
    int a, b, c;
    a = atoi(s);
    b = atoi(s2);

    printf("%d\n%d\n", a, b);

    for (int i = 0; i < n; i++)
    {
        a = atoi(s);
        b = atoi(s2);
        c = a + b;
        printf("%d\n", c);
        sprintf(s, "%d", b);
        sprintf(s2, "%d", c);
    }

    sprintf(s, "%c", '\0');
    sprintf(s2, "%c", '\0');
    exit(0);
}
