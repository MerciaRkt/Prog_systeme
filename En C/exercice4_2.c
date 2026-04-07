#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main()
{
    int p1[2], p2[2];
    pipe(p1); 
    pipe(p2); 

    if (fork() == 0) 
    {
        char mot[255];
        int res;
        printf("Entrez mot : ");
        scanf("%s", mot);
        dup2(p1[1], STDOUT_FILENO);
        dup2(p2[0],  STDIN_FILENO); 
        close(p1[0]); 
        close(p2[1]);
        printf("%s\n", mot); 
        scanf("%d", &res);   
        if (res == 1)printf("Le mot est dans le fichier\n") ;
        else printf ("Le mot n est pas dans le fichier\n") ;
    }
    else 
    {
        FILE *pf;
        char mot[255], motFic[255];
        int trouve = 0;
        dup2(p1[0], STDIN_FILENO);
        dup2(p2[1], STDOUT_FILENO);
        close(p1[1]);
        close(p2[0]);
        scanf("%s", mot);
        pf = fopen("fic.txt", "r");
        while (fscanf(pf, "%s", motFic) == 1)
            if (strcmp(mot, motFic) == 0) { trouve = 1; break; }
        printf("%d\n", trouve);
        wait(NULL);
    }
}