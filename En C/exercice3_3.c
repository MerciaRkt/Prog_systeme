#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    char fichier[255] ;
    printf ("entrez un nom de fichier : ") ;
    scanf ("%s", fichier ) ;
    execl ("/usr/bin/emacs", "emacs" , fichier , NULL) ;
    return(0);
}