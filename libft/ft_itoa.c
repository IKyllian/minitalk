/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:38:48 by kdelport          #+#    #+#             */
/*   Updated: 2020/11/25 18:45:48 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbr_length(long nbr)
{
	int length;

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

static void		check_negative(char *str, int *index, long *nbr)
{
	if (*nbr < 0)
	{
		*nbr *= -1;
		str[(*index)++] = '-';
	}
}

char			*ft_itoa(int n)
{
	int		tab[50];
	char	*str;
	int		i;
	int		x;
	long	nbr;

	i = 0;
	x = 0;
	nbr = n;
	if (!(str = (char *)malloc(sizeof(*str) * (nbr_length(n) + 1))))
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
