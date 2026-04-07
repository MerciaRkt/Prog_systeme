#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
    pid_t pid_fils = fork() ;
    if (pid_fils == 0) printf ("Je suis le fils\n") ;
    else printf ("Je suis le pere\n") ;
    return(0) ;
}