#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid1;
    pid_t pid2;

    pid1 =fork();
    pid2 = fork();

    if(pid1 == 0){
        printf("Child process 1 id = %d with parent process id = %d\n",getpid(),getppid());

    }
    else if(pid1 > 0){
        printf("Parent process id = %d of child process 1 \n",getpid());
       
    }
    if(pid2 > 0){
        printf("parent process of id = %d of child process 2 id = %d \n",getppid(),getpid());
	exit(0);
        
    }
    if(pid2 == 0){
	sleep(10);
        printf("Child process 2 id - %d of parent process id = %d\n",getpid(),getppid());
         }
    
}
