#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void parent_process (int cvar);
void child_process (int pvar);

int y=10;
int main(){
    int x=0;
    printf("Before Forking \n");
    printf("creating child process \n");

    int i = fork();
    if(i == 0){
        child_process(x);
    }
    else{
        parent_process(x);
    }
    printf("After forking \n");
    return 0;
}
void child_process (int a){
    y+=2;
    a=3;
    printf("The value of child process variable= %d\n",a);
    printf("In child process: y=%d \n",y);
}
void parent_process (int b){
    b=2;
    y+=5;
    printf("The value of parent process variable= %d\n",b);
    printf("In parent process: y=%d \n",y);
}