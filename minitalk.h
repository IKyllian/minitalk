#ifndef MINITALK_H
# define MINITALK_H

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef struct s_client
{
	pid_t pid;
	char *str;	
}				t_client;

typedef struct s_server
{
	pid_t pid;
	char **tab;	
}				t_server;

void	ft_putstr(char *str);


#endif