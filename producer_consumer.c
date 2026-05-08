#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int x = 0;

sem_t e, f;
pthread_mutex_t m;

void *pro(void *a)
{
    while (1)
    {
        sem_wait(&e);
        pthread_mutex_lock(&m);

        x++;
        printf("Produced %d\n", x);

        pthread_mutex_unlock(&m);
        sem_post(&f);

        sleep(1);
    }
}

void *con(void *a)
{
    while (1)
    {
        sem_wait(&f);
        pthread_mutex_lock(&m);

        printf("Consumed %d\n", x);
        x--;

        pthread_mutex_unlock(&m);
        sem_post(&e);

        sleep(1);
    }
}

int main()
{
    pthread_t p, c;

    sem_init(&e, 0, 5);
    sem_init(&f, 0, 0);

    pthread_mutex_init(&m, NULL);

    pthread_create(&p, NULL, pro, NULL);
    pthread_create(&c, NULL, con, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}
