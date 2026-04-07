#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>
int compt , limite ;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void * maFonction1 (void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        if (compt >= limite)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
        compt ++;
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 5 +1) ;
    }
}

void * maFonction2 ( void * arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        printf("Compt = %d\n" , compt) ;
        if (compt >= limite)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
        pthread_mutex_unlock(&mutex);
        sleep(2) ;
    }
}
int main (int argc , char*argv[])
{
    pthread_t thread1 , thread2 ;
    limite = atoi(argv[1]) ;
    srand(time(NULL)) ;
    pthread_create (&thread1 , NULL , maFonction1 , NULL ) ;
    pthread_create (&thread2 , NULL , maFonction2 , NULL) ;
    pthread_join(thread1, NULL);
    pthread_join(thread2 , NULL);
    return(0) ;
}


