/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabderra <sabderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:58:19 by hbaddrul          #+#    #+#             */
/*   Updated: 2025/02/10 16:37:12 by sabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	total;

	total = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		total = total * 10 + (*str - '0');
		str++;
	}
	return (total * sign);
}

void	bit_sender(char c, int server_pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
		{
			kill(server_pid, SIGUSR1);
		}
		else
			kill(server_pid, SIGUSR2);
		usleep(1000);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	char	*str;
	int		i;

	if (ac != 3)
	{
		write(1, "try next time : ", 16);
		write(1, " <server_pid> <message>\n", 24);
		return (1);
	}
	server_pid = ft_atoi(av[1]);
	str = av[2];
	if (server_pid <= 0)
	{
		write(1, "Error: Invalid PID\n", 19);
		return (1);
	}
	i = 0;
	while (str[i])
	{
		bit_sender(str[i], server_pid);
		i++;
	}
}
