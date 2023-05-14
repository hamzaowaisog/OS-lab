#include<stdio.h>
#include<omp.h>

int main(){
	int i, a=50, b=0;
	const int N=1000;

	#pragma omp parallel for default(shared)
		for(i=0;i<N;i++){
			b = a + i;
		printf("a = %d and i=%d  and b=%d  number of threads =%d \n",a,i,b,omp_get_thread_num());
	
		}

	printf("a = %d and b=%d (expeted a=50 b=1049)\n",a,b); 
}
