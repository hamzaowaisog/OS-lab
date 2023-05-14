#include <stdio.h>
#include <time.h>

double seriesSumSerial(int n) {
    double sum = 0.0;

    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }

    return sum;
}

double seriesSumParallel(int n) {
    double sum = 0.0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }

    return sum;
}

int main() {
    int n;
    double sum;
    clock_t start, end;
    double cpu_time_used;
    
    printf("Enter the value for n");
    scanf("%d",&n);
   
    start = clock();
    sum = seriesSumSerial(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sum without OpenMP: %f\n", sum);
    printf("Time without OpenMP: %f seconds\n", cpu_time_used);

    
    start = clock();
    sum = seriesSumParallel(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nSum with OpenMP: %f\n", sum);
    printf("Time with OpenMP: %f seconds\n", cpu_time_used);

    return 0;
}

