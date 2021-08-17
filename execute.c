#include "shell.h"

/*

  execute.c cria um processo progénito e executa um programa

*/

int containsPipe (int num_args, char **args)
{
  int index;

  for(index=0; index<num_args; index++)
  {
    if(args[index][0] == '|')
    {
      return index;
    }
  }

  return -1;
}

void execute (char **args, int num_args)
{
   int pid, status;

 

         if ((pid = fork()) < 0)                     /* cria um processo progenito */

         {

            perror("fork");   /* NOTE: perror() produz uma pequema mensagem de erro para o stream */

            exit(1);           /* estandardizado de erros que descreve o ultimo erro encontrado */

                                        /* durante uma chamada ao sistema ou funcao duma biblioteca */

         }

         if (pid == 0)

         {

            execvp(*args, args);  /* NOTE: as versoes execv() e execvp() de execl() sao uteis quando */

            perror(*args);         /* o numero de argumentos nao e’ conhecido. Os argumentos de  */

            exit(1);                 /* execv() e execvp() sao o nome do ficheiro a ser executado e um */

         }             /* vector de strings que contem os argumentos. */                                                                                                      
         while (wait(&status) != pid)     /* O progenitor executa a espera */

             /* ciclio vazio repare que o ; é importante */ ;
}