/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 08:53:51 by josorteg          #+#    #+#             */
/*   Updated: 2023/06/21 19:26:33 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_exit(int sig)
{
	(void)sig;
	exit(0);
}

void	ft_send_integer(int n, int pid)
{
	int	current_bit;

	current_bit = 0;
	while (current_bit < 32)
	{
		if (n & (1 << current_bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
		current_bit++;
	}
}

int	ft_int_size(char *str)
{
	int	bsize;
	int	i;
	int	bytes;

	i = 0;
	bsize = 0;
	while (str[i])
	{
		if (str[i] | (1 << bsize))
			bsize += 1;
		if (bsize % 8 == 0)
			i++;
	}
	bytes = bsize / 8;
	ft_printf("%d bytes\n", bytes);
	return (bytes);
}
