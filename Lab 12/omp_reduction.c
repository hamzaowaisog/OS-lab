#include<stdio.h>
#include<omp.h>

int main(){
	int i, a=50, b=0;
	const int N=1000;

	#pragma omp parallel for default(shared) reduction(max:b) 
		for(i=0;i<N;i++){
			b = a + i;
		}

	printf("reduction sum a = %d and b=%d (expeted a=50 b=1049)\n",a,b); 
}
