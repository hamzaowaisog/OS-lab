#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *printpro(){
	printf("\nHello\n my process id is %d and thread id is %ld\n",getpid(), pthread_self());
	}
int main()
{
	pthread_t thread1,thread2;
	printpro();
	pthread_create(&thread1,NULL,printpro,NULL);
	pthread_create(&thread2,NULL,printpro,NULL);
	
	pthread_join(thread1,NULL);
	printf("\nthread1 is terminating");

	pthread_join(thread2,NULL);
	printf("\nthread2 is terminating");
	printf("\n Main process is terminating with thread id %d\n",pthread_self());
	return 0;
}
