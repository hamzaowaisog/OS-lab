#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
    pid_t pid ;
    pid = fork();

    if(pid < 0){
        printf("Child process unsuccessful");
    }
    else if(pid == 0){
        printf("\nChild\n");
    }
    else {
        printf("parent");
    }
}