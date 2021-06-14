#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long nb;

	nb = n;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	receive_char(int signal)
{
	static int	i;
	static char	*str;
	static char	c;

	if (signal == SIGUSR1)
		c |= 128 / ft_power(2, i);
	i++;
	if (i == 8)
	{
		i = 0;
		
	}

}

int main(void)
{
	ft_putstr("Server PID = ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	signal(SIGUSR1, receive_char);
	signal(SIGUSR2, receive_char);
	while (1) ;
	return (0);
}