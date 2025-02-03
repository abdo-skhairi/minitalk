#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H


#include "../ft_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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