#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (){
    int pid;
    pid = fork();

    if(pid < 0){
        printf("Process creation failed /n");
    }
    else if (pid == 0){
        printf("Child process ");
    }
    else{
        printf("Parent process ");
    }
}