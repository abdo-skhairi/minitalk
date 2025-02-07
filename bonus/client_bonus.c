/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabderra <sabderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:26:18 by sabderra          #+#    #+#             */
/*   Updated: 2025/02/06 16:24:21 by sabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	reaciver(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "Message received OK\n", 20);
	}
}

void	bit_sender(char c, int server_pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(400);
		i--;
	}
}

void	len_sender(int len, int server_pid)
{
	int	i;

	i = 31;
	if (len < 0)
		return ;
	while (i >= 0)
	{
		if (len & (1 << i))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	char	*str;
	int		len;
	int		i;

	if (ac != 3)
	{
		write (1, "try next time : ", 16);
		write (1, " <server_pid> <message>\n", 24);
		return (1);
	}
	signal(SIGUSR1, reaciver);
	str = av[2];
	len = 0;
	i = 0;
	server_pid = ft_atoi(av[1]);
	while (av[2][len])
		len++;
	len_sender(len, server_pid);
	while (str[i])
	{
		bit_sender(str[i], server_pid);
		i++;
	}
}
