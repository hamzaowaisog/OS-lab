#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
    pid_t pid1;
    pid_t pid2;

    (pid1 = fork()) && (pid2 = fork());
    if(pid1 == 0 ){
        printf("Child1 process id =%d  with the parent process id =%d\n",getpid(),getppid());
        exit(0);
    }
    if(pid2 > 0){
        sleep(60);
        printf("Parent process of child2 process with id = %d\n",getppid());
    }
    else if(pid2 == 0){
        printf("Child process 2 id = %d with parent process id = %d \n",getpid(),getppid());
        exit(0);
    }
    return 1;
}
