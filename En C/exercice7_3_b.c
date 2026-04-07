#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void affiche(int sig)
{
    printf("fils est tue\n");
    exit(0);
}

int main()
{
    int i, choix, n;
    pid_t fils[5];
    for (i = 0; i < 5; i++)
    {
        fils[i] = fork();
        if (fils[i] == 0)
        {
            signal(SIGTERM, affiche);
            while (1) printf ("Fils%d\n",i),sleep(4);
        }
    }

    while (1)
    {
        printf("MENU\n1.encormir un fils\n2.reveiller un fils\n3.terminer un fils\n\n") ;
        scanf ("%d" , &choix) ;
        printf("Numéro fils (0-4) : ");
        scanf("%d", &n);
        if (choix == 1) kill(fils[n], SIGSTOP);
        else if (choix==2) kill(fils[n], SIGCONT);
        else if (choix ==3) kill(fils[n], SIGTERM);
    }
    return(0) ;
}