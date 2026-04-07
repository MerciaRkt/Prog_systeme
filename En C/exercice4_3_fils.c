#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd = atoi(argv[1]);
    char chaine[255];
    read(fd, chaine, 255);
    printf("Message reçu : %s\n", chaine);
    return (0);
}