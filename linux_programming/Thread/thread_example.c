#include <stdio.h>
#include <pthread.h>

void *thread_a (void *ctx)
{
    printf("Thread a is runnning \n");
}

void *thread_b (void *ctx)
{
    printf("Thread b is runnning \n");
}

int main()
{
    pthread_t tid;
    if (pthread_create(&tid, NULL, thread_a, NULL) )
    {
        printf("Failed to create threead \n");
    }

    pthread_join(tid, NULL);

    return 0;
}