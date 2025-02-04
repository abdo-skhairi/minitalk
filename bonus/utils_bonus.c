/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabderra <sabderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:38:02 by sabderra          #+#    #+#             */
/*   Updated: 2025/02/04 12:38:06 by sabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
		if (total > 9223372036854775807 && sign == -1)
			return (0);
		else if (total > 9223372036854775807 && sign == 1)
			return (-1);
		str++;
	}
	return (total * sign);
}

void	cleaner(char *c, int *bit, int *check, char **str)
{
	if (c)
		*c = 0;
	if (bit) 
		*bit = 0;
	if (check) 
		*check = 0;
	if (str)
	{
		free (*str);
		*str = NULL;
	}
}

void	len_handler(int sig, int *j, int *len)
{
	if (*j >= 0)
	{
		*len = *len << 1;
		if (sig == SIGUSR1)
			*len = *len | 1;
		(*j)--; 
	}
}
