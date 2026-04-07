#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int compt ;
double u ;
void * T1 (void * arg)
{
    while(1)
    {
        compt ++ ;
        u = ((u-1)*(u-1))/4 ;
        printf("u= %f\n", u ) ;
        sleep(rand()%5+1) ;
    }
}
void * T2 (void * arg)
{
    while(1)
    {
        compt ++ ;
        u = (u-2)*(u-2)/6 ;
        printf("u= %f\n", u ) ;
        sleep(rand()%5+1) ;
    }
}
int main()
{
    u = 1 ;
    pthread_t t1 , t2 ;
    pthread_create (&t1 , NULL , T1 , NULL) ;
    pthread_create (&t2 , NULL , T2 , NULL) ;
    pthread_join(t1, NULL) ;
    pthread_join(t2, NULL) ;
    return(0) ;
}
