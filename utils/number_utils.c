/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:46:56 by kdelport          #+#    #+#             */
/*   Updated: 2021/06/16 13:08:52 by kdelport         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_atoi(const char *nptr)
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

int	ft_power(int nb, int power)
{
	int	i;
	int	result;

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

static	int	nbr_length(long nbr)
{
	int	length;

	length = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		length++;
	}
	while (nbr > 10)
	{
		nbr /= 10;
		length++;
	}
	return (++length);
}

static	void	check_negative(char *str, int *index, long *nbr)
{
	if (*nbr < 0)
	{
		*nbr *= -1;
		str[(*index)++] = '-';
	}
}

char	*ft_itoa(int n)
{
	int		tab[50];
	char	*str;
	int		i;
	int		x;
	long	nbr;

	i = 0;
	x = 0;
	nbr = n;
	str = (char *)malloc(sizeof(*str) * (nbr_length(n) + 1));
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[x++] = '0';
	check_negative(str, &x, &nbr);
	while (nbr)
	{
		tab[i++] = nbr % 10 + 48;
		nbr /= 10;
	}
	while (--i >= 0)
		str[x++] = tab[i];
	str[x] = '\0';
	return (str);
}
