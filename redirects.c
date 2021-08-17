#include "shell.h"

/*

	redirects.c -> Implements redirection in SO_shell ( 2> , >> , > , < )

*/

void redirects(int num_args, char *args[])
{
	if(num_args < 3)
	{
		return;
	}
	
	int fd;
	
	if(strcmp(args[num_args-2], "2>") == 0)
	{
		fd=creat(args[num_args-1], S_IWUSR | S_IRUSR); if(fd<0) perror("error");
		close(STDERR_FILENO);
		dup(fd);
		close(fd);
		args[num_args-2]=NULL;
		num_args -= 2;	
		if(num_args==1)
		{
			return;
		}
	}
	
	if(strcmp(args[num_args-2], ">>") == 0)
	{
		fd=open(args[num_args-1], O_WRONLY | O_APPEND); if(fd<0) perror("error");
		close(STDOUT_FILENO);
		dup(fd);
		close(fd);
		args[num_args-2]=NULL;
		num_args -=2;	
		if(num_args==1)
		{
			return;
		}
	}
	
	if(strcmp(args[num_args-2], ">") == 0)
	{
		fd=creat(args[num_args-1], S_IWUSR|S_IRUSR); if(fd<0) perror("error");
		close(STDOUT_FILENO);
		dup(fd);
		close(fd);
		args[num_args-2]=NULL;
		num_args -=2;	
		if(num_args==1)
		{
			return;
		}
	}
	
	if(strcmp(args[num_args-2], "<") == 0)
	{
		fd=open(args[num_args-1], O_RDONLY); if(fd<0) perror("error");
		close( STDIN_FILENO );
		dup(fd);
		close(fd);
		args[num_args-2]=NULL;
		num_args -=2;	
		if(num_args==1)
		{
			return;
		}
	}
}
