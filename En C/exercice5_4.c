#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
typedef struct {
    int *tab;
    int n;
} Tableau;
void* fonction1 (void * arg)
{
    Tableau * t = arg ;
    int i ;
    srand(time(NULL)) ;
    for (i=0;i<t->n;i++) t->tab[i]= rand() % 100 ;
}

int main()
{
    srand(time(NULL));
    pthread_t th1, th2;

    int T1[5], T2[10];
    Tableau t1 = {T1, 5};
    Tableau t2 = {T2, 10};
    pthread_create(&th1, NULL, fonction1, &t1);
    pthread_create(&th2, NULL, fonction1, &t2);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return(0) ;
}



