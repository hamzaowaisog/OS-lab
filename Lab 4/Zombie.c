#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main (){
    int i;
    int pid=fork();
    if(pid == 0){
    for(i=0;i<5;i++){
            printf("I am in child process \n");
    }
    }
    else{
        signal(SIGCHLD,SIG_IGN);
        printf("I am in parent process \n");
        
     
    }
}