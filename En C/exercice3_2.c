#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main (int argc , char**argv)
{
    execl("/bin/cp", "cp", "-r", ".", argv[1], NULL);
    return(0) ;
}