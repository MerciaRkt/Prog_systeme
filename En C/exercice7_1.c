#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> 
#include <sys/wait.h>

int main()
{
    pid_t fils = fork();
    char choix ;
    if (fils != 0)
    {
        while(1)
        {
            printf ("MENU\n s:stop fils\n r:reprendre fils\n q:tuer fils + quitter\n\n") ;
            scanf (" %c",&choix) ;
            if (choix=='s') kill(fils, SIGSTOP);
            else if (choix=='r') kill(fils, SIGCONT) ; 
            else if (choix=='q') kill(fils, SIGKILL) , exit(0);
        }
    }
    else
    {
        while(1)
        {
            printf("2+3=5\n");
            sleep(1);
        }
    }
    return(0) ;
}