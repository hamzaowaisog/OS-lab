//k21-3247

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd, retval;
    char buffer[512] = {0};

    fd = open("/tmp/myfifo", O_RDONLY);

    for (int i = 0; i < 3; i++)
    {
        retval = read(fd, buffer, sizeof(buffer));
        fflush(stdin);
        write(1, buffer, sizeof(buffer));
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        wait(NULL);
    }
    close(fd);
    return 0;
}
