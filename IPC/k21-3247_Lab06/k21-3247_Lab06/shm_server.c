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
    char c;
    int shmid;
    key_t key;
    char *shm, *s;
    char num_str[10];

    printf("Enter a number: ");
    fgets(num_str, 10, stdin);
    key = 2211;

    if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
        die("shmget");
    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1)
        die("shmat");
    s = shm;

    sprintf(s, "%s", num_str);

    while (*s != 'r')
        sleep(1);

    while (*s != '\0')
        putchar(*s++);
    putchar('\0');
    putchar('\n');
    s = shm;

    *s = '*';

    sleep(1);

    for (int i = 0; i < 10; i++)
    {
        while (*s == '*')
            sleep(1);
        printf("%s\n", s);
        *s = '*';
    }
    exit(0);
}
