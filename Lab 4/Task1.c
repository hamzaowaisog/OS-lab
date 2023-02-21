#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    int pid ;
    pid = fork();

    if(pid < 0){
        printf("Child process failed");
        exit(1);
    }
    else if (pid == 0){
        printf("\nChild process is sucessful %d id\n",getpid());
        sleep(5);
        printf("\nChild process after 5 second sleep %d id",getpid());
    }
    else{
        printf("Parent process with id= %d ",getpid());
    }
    return 1;
}