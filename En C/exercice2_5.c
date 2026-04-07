#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main()
{
    int n ;
    time_t debut = time(NULL) ;
    pid_t fils1 = fork() , fils2 ;
    if (fils1 == 0)
    {
        srand (getpid ());
        n = rand()%10 +1 ;
        sleep(n) ;
        exit(0) ;
    }
    fils2 = fork() ;
    if (fils2 == 0)
    {
        srand (getpid ());
        n = rand()%10 +1 ;
        sleep(n) ;
        exit(0) ;
    }
    wait(NULL);
    wait(NULL);
    printf ("Duree totale = %ld secondes\n" , time(NULL) - debut ) ;
    return(0) ;
}

