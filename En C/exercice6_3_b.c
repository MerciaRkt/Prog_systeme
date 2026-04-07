#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("tableau.bin", O_RDONLY);
    int *tab = NULL , val , n = 0;
    while (read(fd, &val, sizeof(int)) == sizeof(int))
    {
        tab = realloc(tab, (n + 1) * sizeof(int));
        tab[n] = val;
        n++;
    }
    close(fd) ;
}
