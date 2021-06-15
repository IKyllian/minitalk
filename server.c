/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 09:41:02 by kdelport          #+#    #+#             */
/*   Updated: 2021/06/15 10:22:33 by kdelport         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	join_str(char **str, char c)
{
	int i;
	int size;
	char *new_str;

	size = ft_strlen(*str);
	i = -1;
	new_str = malloc(sizeof(char) * (size + 2));
	if (!new_str)
		return (0);
	while (str[++i])
		new_str[i] = *str[i];
	new_str[i++] = c;
	new_str[i] = 0;
	if (str)
		free(str);
	*str = new_str;
	return (1);
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
		if (!c)
			ft_putstr(str);
		else
		{
			if (!join_str(&str, c))
			{
				ft_putstr("Malloc error\n");
				exit(1);
			}
		}	
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