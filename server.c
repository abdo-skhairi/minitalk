/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdo <abdo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:25:13 by sabderra          #+#    #+#             */
/*   Updated: 2025/02/03 21:08:52 by abdo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "./ft_printf/ft_printf.h"

void	cleaner(char *c, int *bit, int *check)
{
	*c = 0;
	*bit = 0;
	*check = 0;
}

void	receiver(int sig, siginfo_t *information, void *unused)
{
	static int		client_pid;
	static char		c;
	static int		bit;
	static int		check;

	(void)unused;
	if (check == 0)
	{
		check = 1;
		client_pid = information->si_pid;
	}
	if (client_pid == information->si_pid && check == 1)
		client_pid = information->si_pid;
	else
		cleaner(&c, &bit, &check);
	c = c << 1;
	bit++;
	if (sig == SIGUSR1)
		c = c | 1;
	if (bit == 8)
	{
		write(1, &c, 1);
		cleaner(&c, &bit, &check);
	}
}

int	main(void)
{
	struct sigaction	s;

	ft_printf("The Pid Of The Server is %d\n", getpid());
	s.sa_sigaction = receiver;
	s.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	while (1337)
	{
		pause();
	}
}
