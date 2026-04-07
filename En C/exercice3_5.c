#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main ()
{
    char choix , fic[255];
    do
    {  
        printf("entrez un fichier : ");
        scanf ("%s",fic);
        pid_t pid_fils = fork();
        if (pid_fils == 0) execl("/usr/bin/emacs", "emacs", fic , NULL);
        else wait(NULL) ;
        printf(" Entrez Q pour quitter\n");
        scanf (" %c" , &choix) ;  
    }
    while ((choix != 'Q')&&(choix!='q'));
    return(0) ;
}