#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Function to be executed by a thread
void *thread_function(void *arg) {
    printf("Thread ID: %lu\n", pthread_self());
    printf("Process ID: %d\n", getpid());
    return NULL;
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, thread_function, NULL);

    pthread_join(thread, NULL);

    printf("Main Process ID: %d\n", getpid());

    return 0;
}



