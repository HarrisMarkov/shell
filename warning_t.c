#include "shell.h"

void * avisowrapper(void *args)
{
    aviso_t * ptr = (aviso_t *)args;
    warning( ptr->msg, ptr->tempo );
    free(ptr);
    return NULL;
}