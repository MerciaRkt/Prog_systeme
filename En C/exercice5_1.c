#include <stdio.h>
#include <pthread.h>
void* fonction (void* arg)
{
    int i , * tab = (int*)arg ;
    for (i = 0; i<3;i++) printf ("%d\n", tab[i]) ;
}
int main()
{
    pthread_t thread ;
    int tab[] = {1 , 2 ,3} ;
    pthread_create (&thread , NULL , fonction , tab ) ;
    pthread_join(thread , NULL) ;
} 
