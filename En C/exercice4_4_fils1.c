#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char chaine[100] , * tube = getenv("TUBE");
    int fd = atoi(tube);
    read(fd, chaine, 100);
    printf("Message : %s\n", chaine);
    return (0);
}