#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
    pid_t pid_fils1 = fork() ;
    if (pid_fils1 == 0) 
    {
        printf ("Je suis le fils 1\n") ;
        exit(0) ;
    }
    pid_t pid_fils2 = fork() ;
    if (pid_fils2 == 0 ) printf ("Je suis le fils 2\n") ;
    if ((pid_fils1 != 0) && (pid_fils2 != 0)) printf ("Je suis le pere\n") ;
    return(0) ;
}