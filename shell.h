#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <dirent.h>

typedef struct
{
    char msg[100];
    int tempo;
} aviso_t;

typedef struct
{
  char fonte[100];
  char destino[100];
} copiar_t;

void parse(char *buf, char **args);
void execute(char **args, int num_args);
int builtin (char **args);
int help (); /*displays SO_shell commands*/
int socpy (char *fonte, char *destino); /*copies contents of file fonte to file destino*/
void * SOCPWrapper(void *args); /*same as socpy but with threads*/
void warning (char *mesg, int tempo); /*startting shell message*/
int welcomeRocket(); /*starting shell rocket animation*/
int isjpg (int fileDescriptor); /*tells the user if the specified file is jpeg or not*/
int cd (char *args); /*linux command to change directory*/
void * avisowrapper(void *args); /*waring com threads*/
void calc (char *value1, char *op, char *value2); /*calulator with ( + , - , / , * , ^)*/
void bits (char *value1, char *op, char *value2); /*binary calculatior with ( and , inclusive_OR , exclusive_OR )*/
int ultimo ( int numargs, char **args );
void redirects(int numargs, char *args[]); /*Implements redirection in SO_shell ( 2> , >> , > , < )*/
int sols (int argc, char *argv[]);


/* constantes que podem tornar uteis*/

#define BG 0
#define FG 1
#define BUFFSIZE 128
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

// CHARACTERS CHANGES
#define NORMAL  "\x1B[0m"
#define BOLD "\x1B[1m"
 
// COLOR VALUES
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE  "\x1B[37m"
#define RESET  "\x1B[0m"