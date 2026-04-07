#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
typedef struct TypeTableau 
{
    int tab[100];  
    int n;     
    int x;   
} TypeTableau;
void* fonction1 (void * arg)
{
    TypeTableau *t = (TypeTableau*) arg;
    int i ;
    srand(time(NULL)) ;
    for (i=0;i<t->n;i++) t->tab[i] = rand() % 100 ;
}

void* fonction2 (void * arg )
{
    TypeTableau *t = (TypeTableau*) arg;
    int i , *trouve = malloc(sizeof(int));
    *trouve = 0;
    for (i=0;i<t->n;i++) if (t->tab[i] == t->x) *trouve = 1;
    pthread_exit(trouve) ;
}

int main(int argc , char*argv[])
{
    TypeTableau t ;
    t.n = atoi(argv[1]) ;
    int i , *trouve ;
    pthread_t thread1 , thread2 ;
    printf("entrez x :") ;
    scanf ("%d", &t.x) ;

    pthread_create(&thread1, NULL , fonction1 ,&t) ;
    pthread_join(thread1,NULL) ;
    pthread_create(&thread2 , NULL , fonction2 ,&t) ;
    pthread_join(thread2,(void**)&trouve) ;

    return(0) ;
}


