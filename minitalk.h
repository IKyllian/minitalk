#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_power(int nb, int power);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		join_str(char **str, char c);

#endif