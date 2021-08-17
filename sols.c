#include "shell.h"

/*

    sols -> same as ls command on Linux;

*/

int sols (int argc, char *argv[])
{
    struct stat f1;
    struct dirent **nameList;
    int n;
    
    if (argc < 1)
    {
        return 0;
    }

    else if (argc == 1)
    {
        n = scandir(".",&nameList,NULL,alphasort);
    }

    else
    {
        n = scandir(argv[1],&nameList,NULL,alphasort);
    }

    if(n<0)
    {
        perror("scandir");
        return 0;
    }

    else
    {
        while (n--)
        {
            stat(nameList[n]->d_name, &f1);
            if( S_ISDIR(f1.st_mode) && (strcmp(".",nameList[n]->d_name) != 0) && (strcmp("..",nameList[n]->d_name) != 0))
            {
                printf("%s\n",nameList[n]->d_name);
            }

            else if(S_ISREG(f1.st_mode))
            {
                printf("%s\n", nameList[n]->d_name);
            }

            free(nameList[n]);
        }
        free(nameList);
    }
    return 1;
}