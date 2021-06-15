#ifndef MINITALK_H
# define MINITALK_H

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

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

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_power(int nb, int power);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
#endif