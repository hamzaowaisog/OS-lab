//k21-3247

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, retval;
    char buffer[] = "Example text for FIFO";

    retval = mkfifo("/tmp/myfifo", 0666);
    fd = open("/tmp/myfifo", O_WRONLY);
    write(fd, buffer, sizeof(buffer));
    close(fd);
    return 0;
}
