#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main ()
{
    char choix , rep[255];
    do
    {  
        printf("entrez un repertoire : ");
        scanf ("%s",rep);
        pid_t pid_fils = fork();
        if (pid_fils == 0) execl("/bin/cp", "cp", "-r", ".", rep, NULL);
        else wait(NULL) ;
        printf(" Entrez Q pour quitter\n");
        scanf (" %c" , &choix) ;  
    }
    while ((choix != 'Q')&&(choix!='q'));
    return(0) ;
}