#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int i ;
    pid_t fils1 , fils2 , fils3 , fils4, fils5 , pere=getpid();
    for (i=0 ; i<5 ;i++)
    {
        if (i==0) fils1 = fork() ;
        else if (i==1) fils2= fork() ;
        else if (i==2) fils3= fork() ;
        else if (i==3) fils4= fork() ;
        else if (i==4) fils5= fork() ;
        if (getpid() != pere ) break ;
    }
    if (fils1==0) printf("Je suis le fils 1\n") ;
    else if (fils2==0) printf ("Je suis le fils 2\n") ;
    else if (fils3==0) printf ("Je suis le fils 3\n") ;
    else if (fils4==0) printf ("Je suis le fils 4\n") ;
    else if (fils5==0) printf ("Je suis le fils 5\n") ;
    return(0) ;
}