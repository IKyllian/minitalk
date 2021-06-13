#include "minitalk.h"

int		ft_atoi(const char *nptr)
{
	int		i;
	long	nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
		nbr = nbr * 10 + (nptr[i++] - 48);
	return (nbr * sign);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}


void	send_char(int pid, char *str)
{
	ft_putstr("CLIENT\n");
	kill(pid, SIGUSR1);
}

int main(int argc, char **argv)
{
	int pid;
	if (argc == 3)
	{
		pid = ft_atoi(argv[0]);
		send_char(pid, argv[2]);
	}
	else 
		ft_putstr("Missing argument");
	return (0);
}