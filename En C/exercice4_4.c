#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
    int tube[2] ;
    pipe(tube) ;

    pid_t pid_fils = fork() ;
    if (pid_fils == 0)
    {
        char fd[255];
        sprintf(fd, "%d", tube[0]);
        setenv("TUBE", fd, 1); 
        char *arg[] = {"./fils1", NULL};
        execv("./fils1", arg);
    }
    else
    {
        close(tube[0]);
        write(tube[1], "Bonjour", 8);
    }

    return 0;
}