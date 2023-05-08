#include<stdio.h>
#include<pthread.h>
#include<stdio.h>

void *printMessage(){
	printf("Child Thread Created Process Id = %d and thread id =%d\n",getpid(),pthread_self());
	}
void *makeChildThread(){
	printf("Parent Thread Created Process id =%d and thread id =%d\n",getpid(),pthread_self());
	pthread_t th1;
	pthread_create(&th1,NULL,printMessage,NULL);
	pthread_join(th1,NULL);
	printf("\nTerminating Thread");
	}

int main(){
	pthread_t th1;
	pthread_create(&th1,NULL,makeChildThread,NULL);
	pthread_join(th1,NULL);
	printf("\nTerminating Parent Thread");
	return 0;
	}
	
