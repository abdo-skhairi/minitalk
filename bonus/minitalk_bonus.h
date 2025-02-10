/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabderra <sabderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:37:36 by sabderra          #+#    #+#             */
/*   Updated: 2025/02/10 16:35:35 by sabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../ft_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		client_pid;
	char	c;
	int		bit;
	int		check;
	int		len;
	int		j;
	int		index;
	char	*str;
}t_data;

int		ft_atoi(const char *str);
void	cleaner(char *c, int *bit, int *check, char **str);
void	len_handler(int sig, int *j, int *len);

#endif