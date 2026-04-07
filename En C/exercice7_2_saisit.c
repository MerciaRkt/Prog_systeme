#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
int main()
{
    int n;
    pid_t pid;
    FILE *pf = fopen("/tmp/entier.txt", "w");
    printf("Entrez un entier : ");
    scanf("%d", &n);
    fprintf(pf, "%d", n);
    fclose(pf);
    printf("PID de affiche.c : ");
    scanf("%d", &pid);
    kill(pid, SIGUSR1);
    return (0);
}