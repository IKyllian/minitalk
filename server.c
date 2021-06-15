/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 09:41:02 by kdelport          #+#    #+#             */
/*   Updated: 2021/06/15 16:45:12 by kdelport         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	join_str(char **str, char c)
{
	int i;
	int size;
	char *new_str;

	if (!*str)
	{
		new_str = malloc(sizeof(char) * 2);
		if (!new_str)
			return (0);
		new_str[0] = c;
		new_str[1] = '\0';
		*str = new_str;
		return (1);
	}
	else
	{
		size = ft_strlen(*str);
		i = 0;
		new_str = malloc(sizeof(char) * (size + 2));
		if (!new_str)
			return (0);
		while ((*str)[i])
		{
			new_str[i] = (*str)[i];
			i++;
		}
		new_str[i++] = c;
		new_str[i] = 0;
		if (*str)
			free(*str);
		*str = new_str;
		return (1);
	}
}

void	receive_char(int signal)
{
	static int	i;
	static char	*str;
	static char	*pid;
	static char	c;
	static int	is_pid;

	if (signal == SIGUSR2)
		c |= 128 / ft_power(2, i);
	i++;
	if (i == 8)
	{
		i = 0;
		if (!c && is_pid)
		{
			ft_putstr(str);
			ft_putchar('\n');
			if (kill(ft_atoi(pid), SIGUSR2) == -1)
				ft_putstr("Error with Kill function");
			free(str);
			free(pid);
		}
		else if (!c && !is_pid)
			is_pid = 1;
		else if (c && !is_pid)
		{
			if (!join_str(&str, c))
			{
				ft_putstr("Malloc error\n");
				exit(1);
			}
		}
		else
		{
			if (!join_str(&pid, c))
			{
				ft_putstr("Malloc error\n");
				if (str)
					free(str);
				if (pid)
					free(pid);
				exit(1);
			}
		}
		c = 0;
	}
}

int main(void)
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