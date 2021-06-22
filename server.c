/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 09:41:02 by kdelport          #+#    #+#             */
/*   Updated: 2021/06/22 12:30:09 by kdelport         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	free_elems(char **str, char **pid, char *c, int *is_pid)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	if (*pid)
	{
		free(*pid);
		*pid = NULL;
	}
	*c = 0;
	*is_pid = 0;
}

void	print_string(char **str, char **pid, char *c, int *is_pid)
{
	ft_putstr(*str);
	ft_putchar('\n');
	if (kill(ft_atoi(*pid), SIGUSR2) == -1)
		ft_putstr("Error with Kill function");
	free_elems(str, pid, c, is_pid);
}

void	exec_receive(char **str, char **pid, char *c, int *is_pid)
{
	if (!*c && *is_pid)
		print_string(str, pid, c, is_pid);
	else if (!*c && !*is_pid)
		*is_pid = 1;
	else if (*c && !*is_pid)
	{
		if (!join_str(str, *c))
		{
			ft_putstr("Malloc error\n");
			free_elems(str, pid, c, is_pid);
			exit(1);
		}
	}
	else
	{
		if (!join_str(pid, *c))
		{
			ft_putstr("Malloc error\n");
			free_elems(str, pid, c, is_pid);
			exit(1);
		}
	}
}

void	receive_char(int signal)
{
	static int	i;
	static int	is_pid;
	static char	*str;
	static char	*pid;
	static char	c;

	if (signal == SIGUSR2)
		c |= 128 / ft_power(2, i);
	i++;
	if (i == 8)
	{
		i = 0;
		exec_receive(&str, &pid, &c, &is_pid);
		c = 0;
	}
}

int	main(void)
{
	ft_putstr("Server PID = ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	signal(SIGUSR1, receive_char);
	signal(SIGUSR2, receive_char);
	while (1)
		;
	return (0);
}
