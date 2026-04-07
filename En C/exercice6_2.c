#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char**argv)
{
    DIR *dir;
    int i;
    for (i=1 ; i<argc ; i++)
    {
        dir = opendir(argv[i]);
        struct dirent *ent;
        struct stat st;
        printf("Répertoire %s\n\n", argv[i]);
        while ((ent=readdir(dir)) != NULL) 
        {
            stat(ent->d_name, &st);
            if (st.st_size >= 1048576) printf("%s : UID = %d\n", ent->d_name , st.st_uid);
        }
    }
    return(0);
}