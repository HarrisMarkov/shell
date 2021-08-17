#include "shell.h"

/*

    warning.c -> startting shell message

*/

void warning (char *mesg, int tempo)
{
    while (tempo > 0)
    {
        fprintf(stderr, MAGENTA "%s: %d\n" RESET ,mesg, tempo);
        sleep(1);
        tempo--;
    }
}