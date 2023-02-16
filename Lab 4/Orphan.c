#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int i , pid;
    pid = fork();
    if (pid == 0){
        for(i=0;i<5;i++){
        sleep(5);
        printf("I am in child process \n");
        }
    }
    else{
        sleep(1);
        printf("I am in parent process \n");
    }
}