#include<stdio.h>
#include<omp.h>

int main() {
	printf("Open MP running with %d threads\n",omp_get_max_threads());
	
	#pragma omp parallel
	{
		printf("Hello from thread %d \n",omp_get_thread_num());
	}
	0;

}
