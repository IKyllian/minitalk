/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:16:39 by kdelport          #+#    #+#             */
/*   Updated: 2021/06/15 10:16:40 by kdelport         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		printf("PID = %i\n", pid);
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