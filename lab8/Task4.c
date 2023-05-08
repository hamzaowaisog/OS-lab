#include <stdio.h>
#include <pthread.h>

void *thread_function(void *args) {
    int value1 = *((int *)args);  


    printf("Received argument: %d\n", value1);

    return NULL;
}

int main() {
    pthread_t thread;
    int arg = 42;
    pthread_create(&thread, NULL, thread_function, (void *)&arg);
    pthread_join(thread, NULL);

    return 0;
}

