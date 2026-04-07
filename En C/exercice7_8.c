#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int *tab;
int n , i;
void affiche(int sig)
{
    printf("Erreur, entre i:");
    scanf("%d", &i);
    printf("tab[%d] = %d\n", i, tab[i]);
}

int main()
{
    int j;
    printf("entrz n : ");
    scanf("%d", &n);
    tab = malloc(n * sizeof(int));
    for (j = 0; j< n; j++)
    {
        printf("tab[%d] = ", j);
        scanf("%d", &tab[j]);
    }
    signal(SIGSEGV,affiche);
    printf("\nentrez i: ");
    scanf("%d", &i);
    printf("tab[%d] = %d\n", i, tab[i]);
    return (0);
}