#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void affiche(int sig)
{
    FILE *f;
    int n;
    f = fopen("/tmp/entier.txt", "r");
    fscanf(f, "%d", &n);
    printf("Valeur reçue : %d\n", n);
    fclose(f);
}
int main()
{
    signal(SIGUSR1, affiche);
    printf("Mon PID = %d\n", getpid());
    while (1) sleep(1) ;
    return (0);
}