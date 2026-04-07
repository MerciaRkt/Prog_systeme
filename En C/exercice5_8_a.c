#include<stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include<unistd.h>
#include<time.h>
sem_t s1, s2;
void * T1 (void*arg)
{
    int i ;
    for ( i = 0 ;i<10;i++) 
    {
        sem_wait(&s1) ;
        printf("T1\n");
        sleep(2) ;
        sem_post(&s2) ;
    }
}
void * T2 (void*arg)
{
    int i;
    for (i = 0 ;i<10;i++) 
    {
        sem_wait(&s2);
        printf("T2\n ");
        sleep(rand() % 6 + 4);
        sem_post(&s1);
    }
}
int main()
{
    pthread_t t1 ,t2;
    sem_init(&s1, 0, 1); 
    sem_init(&s2, 0, 0);
    pthread_create (&t1 , NULL , T1 , NULL) ;
    pthread_create (&t2 , NULL , T2, NULL) ;
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return(0) ;
}
