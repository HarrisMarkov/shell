#include "shell.h"

#define BUFFSIZE 128

void streamCopy (int ent, int saida)
{
    int c;
    char buffer[1];
    while( (c=read(ent,buffer,1))>0 )
    {
        write(saida,buffer,1);
    }
}

int socpy (char *fonte, char *destino)
{
    int fde; //vec[BUFFSIZE];
    int flag;
    fde=open(fonte, O_RDONLY); //file descriptor entrada;
    if(fde==-1)
    {
        fprintf(stderr, BOLD "Erro na abertura do ficheiro %s!\n" RESET ,fonte);
        fprintf(stderr,BOLD "Nome errado ou ficheiro nao existe!\n" RESET);
        return (-1);
    }

    int fds=open(destino,O_WRONLY); //file descriptor saida;
    if(fds==-1)
    {
        fprintf(stderr,"Erro na abertura do ficheiro %s!\n",destino);
        printf("Quer criar o ficheiro %s e depois copiar o coteudo?\n",destino);
        printf("1- sim\n0- nao\t");
        scanf("%d",&flag);
        if(flag==1)
        {
            fde=creat(destino, O_WRONLY);
        }
    }

    streamCopy(fde,fds);
    printf("Ficheiro %s copiado com sucesso para %s!\n",fonte, destino);

    close(fde);
    close(fds);

    return 0;
}

void *SOCPWrapper(void *args)
{
  copiar_t *ptr = (copiar_t *) args;
  socpy(ptr->fonte, ptr->destino);
  free(ptr);
  return NULL;
}