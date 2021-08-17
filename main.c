#include "shell.h"

char prompt[100];

int main ()
{
  //clock_t start = clock();

  int len;
  char buf[1024];		/* um comando */
  char *args[64];		/* com um maximo de 64 argumentos */
  int num_args=(int)sizeof(args)/sizeof(args[0]);

  strcpy (prompt, "SO_shell>");

  warning("Starting SO_shell in",3);
  welcomeRocket();

  while (1)
  {
    printf (RED "%s" RESET, prompt);

    if ( fgets(buf,1023,stdin) == NULL)
	  {
	    printf ("\n");
	    exit (0);
	  }
	
    len=strlen(buf);
	  if ( 1==len ) continue;  // string is only a \n
	  
    if ( buf[len-1] == '\n' ) buf[len-1] ='\0';
	    parse (buf, args);	/* particiona a string em argumentos */

    if (!builtin (args))//start))
	    execute (args,num_args);		/* executa o comando */
  }

  return 0;
}

int builtin (char **args) //clock_t start)
{
  //clock_t start = clock();
  int num_args=(int)sizeof(args)/sizeof(args[0]);

  /*Exit shell*/
  if( (strcmp (args[0], "letmeout") == 0) || (strcmp (args[0], "sair") == 0) || strcmp (args[0], "abandonship") == 0)
  {
    warning("Exiting Shell in",3);
    //printf("Time elapsed: %fs\n", ((double)clock() - start) / CLOCKS_PER_SEC);
    exit (0);
    return 1;
  }

  if( strcmp(args[0],"42")==0 )
  {
    printf( YELLOW "42 is the answer to life, the universe and everything!\n" RESET );
    return 1;
  }

  if( strncmp(args[0], "PS1=",4) == 0 && strlen(args[0])>4 )
  {
    strcpy(prompt,args[0]+4);
    strcat(prompt,">");
    return 1;    
  }

  /*anular ultimo argumento caso seja '&'*/
  if ( strcmp(args[num_args-1],"&")==0 )
    {
      args[num_args-1]=NULL ; 
      return 1;
    }
  
  /*get user id*/
  if(strcmp(args[0], "quemsoueu")==0)
  {
    system("id");
    return 1;
  }

  /*displays SO_shell commands*/
  if(strcmp(args[0], "help")==0)
  {
    help();
    printf("\n");
    return 1;
  }

  /*copies contents of file fonte to file destino*/
  if(strcmp(args[0], "socp")==0)
  {
    socpy(args[1],args[2]);
    return 1;
  }

  if( strcmp(args[0], "socpth") == 0)
    {
      /*if(num_args < 3)
      {
        fprintf(stderr, "O número de argumentos é menor que 3!\n");
        return 1;
      }*/

      pthread_t th;
      copiar_t * ptr = (copiar_t *) malloc(sizeof(copiar_t));
      strcpy(ptr->fonte, args[1]);
      strcpy(ptr->destino, args[2]);
      pthread_create(&th, NULL, SOCPWrapper, (void *)ptr);
      return 1;
    }

  /*tells the user if the specified file is jpeg or not*/
  if(strcmp(args[0], "isjpeg")==0)
  {
    int fd=open(args[1],O_RDONLY);
    isjpg(fd);
    return 1;
  }

  /*linux command to change directory*/
  if(strcmp(args[0], "cd")==0)        
  {
    int err;
    if ( args[1] == NULL || strcmp(args[1], "~")==0 )   // If we write only 'cd' or "cd ~" then go to the home directory
    {
		  err=chdir(getenv("HOME"));
      strcpy (prompt, "SO_shell>");
	  }
    else
    {                                                // Else we change to the directory specified by the user
      err=chdir(args[1]);
      if (err<0)
      {
        perror(BOLD "No such directory!\n" RESET);
      }

      if(err==0)
      {
        strcat(args[1],">");
        strcat(prompt,args[1]);
      }
    }
    
    return 1;
  }

  /*normal warning function*/
  if( strcmp(args[0], "aviso")==0 )
  {
    if ( args[1] == NULL || args[2] == NULL )
    {
      printf("O comando \"aviso\" recebe sempre dois argumentos!\n");
      return 1;
    }

    warning(args[1], atoi(args[2]));
    return 1;
  }

  /*warning function with threads*/
  if( strcmp(args[0], "avisot")==0 )
  {
    if ( args[1] == NULL || args[2] == NULL )
    {
      printf("O comando \"avisot\" recebe sempre dois argumentos!\n");
      return 1;
    }

    pthread_t th;
    aviso_t * ptr = (aviso_t *)malloc( sizeof(aviso_t) );
    strcpy(ptr->msg, args[1]);
    ptr->tempo=atoi(args[2]);
    pthread_create(&th, NULL, avisowrapper, (void *)ptr);
    return 1; 
  }

  /*calulator with ( + , - , / , * , ^)*/
  if( strcmp(args[0],"calc")==0 )
  {
    if( args[1]!=NULL && args[2]!=NULL && args[3]!=NULL )
    {
      calc(args[1],args[2],args[3]);
      return 1;
    }

  }

  /*binary calculatior with ( and , inclusive_OR , exclusive_OR )*/
  if( strcmp(args[0],"bits")==0 )
  {
    if(args[1]!=NULL && args[2]!=NULL && args[3]!=NULL )
    {
      bits(args[1],args[2],args[3]);
      return 1;
    }
  }


  if( strcmp(args[0], "sols") ==0 )
  {
    sols(num_args,args);
    return 1;
  }

  return 0;
}