#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#define N 100
void * fonc1 (void * arg)
{
    int i ;
    while(1)
    {
        for(i=1;i<N-1;i++) tab[i] = (tab[i-1]+tab[i]+tab[i+1])/3 ;
        sleep(rand() % 3+1) ;
    }
}
void * fonc2 (void * arg)
{
    int i;
    while(1)
    {
        for(i=0;i<N;i++) printf("tab[%d] = %d\n" , i , tab[i]) ;
        sleep(4) ;
    }
}

int tab[N] ;
int main()
{
    int i ;
    pthread_t t1 , t2 ;
    srand(time(NULL)) ;
    for(i=1;i<99;i++) tab[i] = rand()%101 ;
    tab[0] = 0 ; 
    tab[99] = 0;
    pthread_create (&t1 , NULL , fonc1 , NULL ) ;
    pthread_create (&t2 , NULL , fonc2 , NULL ) ;
    pthread_join(t1, NULL) ;
    pthread_join(t2, NULL) ;
}
