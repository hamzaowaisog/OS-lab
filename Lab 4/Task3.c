#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int i,num;
    printf("Enter the number of times the process should run\n");

    scanf("%d",&num);

    for(i=0 ; i<num ;i++){
        pid_t pid ; 
        pid = fork();
         if (pid == 0){
            printf ("child process id = %d and parent process id = %d \n",getpid(),getppid());
            exit(0);
        }
    }
    for(i=0;i<num;i++){
        wait(NULL);
    }
    return 1;
}