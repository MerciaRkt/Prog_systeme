#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main()
{
    int p1[2], p2[2]; 
    pipe(p1); 
    pipe(p2); 
    pid_t pid = fork();

    if (pid == 0)
    {
        char mot[255];
        int resultat; 
        close(p1[0]);
        close(p2[1]); 
        printf("entrez un mot: ");
        scanf("%s", mot);
        write(p1[1], mot, 255);
        read(p2[0], &resultat,sizeof(int));
        if (resultat == 1)printf("Le mot est dans le fichier\n") ;
        else printf ("Le mot n est pas dans le fichier\n") ;
    }
    else 
    {
        FILE *pf;
        char mot[255], motFic[255];
        int r = 0;
        close(p1[1]); 
        close(p2[0]); 
        read(p1[0], mot, 255);
        pf = fopen("fic.txt", "r");
        while (fscanf(pf, "%s", motFic) == 1)
            if(strcmp (mot , motFic) == 0) { r = 1 ; break ;}
        fclose(pf);
        write(p2[1], &r, sizeof(int));
        wait(NULL);
    }
    return 0;
}