/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabderra <sabderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:37:49 by sabderra          #+#    #+#             */
/*   Updated: 2025/02/04 12:38:08 by sabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static t_data	g_data = {0, 0, 0, 0, 0, 31, 0, NULL};

void	handle_new_client(siginfo_t *info)
{
	if (g_data.client_pid != info->si_pid)
	{
		cleaner(&g_data.c, &g_data.bit, &g_data.check, &g_data.str);
		cleaner(&g_data.c, &g_data.len, &g_data.index, &g_data.str);
		g_data.j = 31;
		g_data.client_pid = info->si_pid;
	}
}

void	process_signal(int sig)
{
	if (g_data.j >= 0)
		len_handler(sig, &g_data.j, &g_data.len);
	else
	{
		if (g_data.len > 0 && g_data.str == NULL)
		{
			g_data.str = malloc(g_data.len + 1);
			if (!g_data.str)
				exit (EXIT_FAILURE);
		}
		if (g_data.len > 0)
		{
			g_data.c = g_data.c << 1;
			g_data.bit++;
			if (sig == SIGUSR1)
				g_data.c = g_data.c | 1;
			if (g_data.bit == 8)
			{
				g_data.str[g_data.index++] = g_data.c;
				g_data.c = 0;
				g_data.bit = 0;
			}
		}
	}
}

void	finalize_message(void)
{
	if (g_data.index == g_data.len && g_data.len > 0)
	{
		g_data.str[g_data.index] = '\0';
		ft_printf("%s", g_data.str);
		usleep(300);
		kill(g_data.client_pid, SIGUSR1);
		cleaner(NULL, &g_data.check, &g_data.index, &g_data.str);
		cleaner(NULL, &g_data.len, &g_data.j, NULL);
		g_data.j = 31;
	}
}

void	receiver(int sig, siginfo_t *info, void *unused)
{
	(void)unused;
	handle_new_client(info);
	process_signal(sig);
	finalize_message();
}

int	main(void)
{
	struct sigaction	s;

	ft_printf("The PID of the Server is %d\n", getpid());
	s.sa_sigaction = receiver;
	s.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	while (1)
		pause();
}
