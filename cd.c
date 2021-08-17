#include "shell.h"

/*

    cd.c -> linux command to change directory

*/

int cd (char *args)
{                       
	if (chdir(&args[1]) == -1)
    {
		printf("\t\tNo such directory\n");
        return -1;
	}
	return 0;
}