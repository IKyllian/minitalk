/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:16:39 by kdelport          #+#    #+#             */
/*   Updated: 2021/06/15 16:42:00 by kdelport         ###   ########.fr       */
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
	while (i <= max)
	{
		j = 0;
		while (j < 8)
		{
			if (str[i] & 128 / ft_power(2, j))
			{
				if (kill(pid, SIGUSR2) == -1)
				{
					ft_putstr("Error with Kill function");
					exit(1);
				}
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
				{
					ft_putstr("Error with Kill function");
					exit(1);
				}
			}
			j++;
			usleep(100);
		}
		i++;
	}
}

void	has_receive(int pid)
{
	(void)pid;
	ft_putstr("The message has been receive by the server");
	exit(0);
}

int main(int argc, char **argv)
{
	int		pid;
	int		client_pid;
	char	*pid_to_char;

	signal(SIGUSR2, has_receive);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_char(pid, argv[2]);
		client_pid = getpid();
		pid_to_char = ft_itoa(client_pid);
		send_char(pid, pid_to_char);
		free(pid_to_char);
	}
	else 
	{
		ft_putstr("Missing argument");
		return (1);
	}
	// while (1)
	// 	;
	pause();
	return (0);
}