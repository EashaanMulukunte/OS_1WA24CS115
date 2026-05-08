#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t f[N];

void *p(void *a)
{
    int i = *(int *)a;

    while (1)
    {
        printf("P%d Thinking\n", i);
        sleep(1);

        pthread_mutex_lock(&f[i]);
        pthread_mutex_lock(&f[(i + 1) % N]);

        printf("P%d Eating\n", i);
        sleep(1);

        pthread_mutex_unlock(&f[i]);
        pthread_mutex_unlock(&f[(i + 1) % N]);
    }
}

int main()
{
    pthread_t t[N];
    int i, id[N];

    for (i = 0; i < N; i++)
        pthread_mutex_init(&f[i], NULL);

    for (i = 0; i < N; i++)
    {
        id[i] = i;
        pthread_create(&t[i], NULL, p, &id[i]);
    }

    for (i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    return 0;
}
