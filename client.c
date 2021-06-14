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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_power(int nb, int power)
{
	int i;
	int result;

	i = 1;
	result = nb;
	if (power < 0 || (nb == 0 && power != 0))
		return (0);
	else if (power == 0)
		return (1);
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

void	send_char(int pid, char *str)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = ft_strlen(str);
	while (i++ < max)
	{
		j = 0;
		while (j++ < 8)
		{
			if (str[i] & 128 / ft_power(2, j))
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_putstr("Error with Kill function");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_putstr("Error with Kill function");
			}
		}
	}
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
	{
		ft_putstr("Missing argument");
		return (1);
	}
	while (1) ;
	return (0);
}