#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
void* fonction (void*arg)
{
    srand(time(NULL)) ;
    int i ,*tab = malloc (10 * sizeof(int)) ;

    for (i = 0 ; i<10 ; i++) tab[i] = rand() % 100 ;
    pthread_exit(tab) ;
} 
int main()
{
    pthread_t thread ;
    int * tab ;
    pthread_create(&thread , NULL , fonction , NULL) ;
    pthread_join (thread , (void*)&tab);
    return (0) ;
}
