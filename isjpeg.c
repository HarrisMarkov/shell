#include "shell.h"
 
/*
 
   isjpg.c – Verifica se o ficheiro é um jpg
 
*/

int isjpg(int fileDescriptor) //esboço da função
{
  if(fileDescriptor < 0)
  {
    printf(" O Ficheiro não existe!\n");
    return 0;
  }
 
  unsigned char b[4];
  read(fileDescriptor,b,4);
  //voltar ao inicio do ficheiro com lseek
 
  if (b[0]==0xff && b[1]==0xd8 && b[2]==0xff && b[3]==0xe0)
  {
    printf("O ficheiro é um JPG!\n");
    return 1;
  }
 
  printf("O ficheiro não é um JPG!\n");
  return 0;
}