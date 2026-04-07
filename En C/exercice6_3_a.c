#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int tab[5] , fd ;
    for (int i = 0; i < 5; i++)
    {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
    fd = open("tableau.bin", O_WRONLY | O_CREAT | O_TRUNC, 0624);
    write(fd, tab, 5 * sizeof(int));
    close(fd);
    return(0) ;
}
