#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){

	int num;
	int i;
	printf("Table [PROMP] Enter your number:");
	scanf("%d",&num);
	
	#pragma omp parallel num_threads(10)
	#pragma omp for
	for(i=0;i<1000;i++){
		printf("Table [INFO] thread ID: %d | %d x %d = %d \n",omp_get_thread_num(),i,num,i*num);
	
	}
	
	return 0;
}
