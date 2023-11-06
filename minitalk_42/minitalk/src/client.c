/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:17:12 by josorteg          #+#    #+#             */
/*   Updated: 2023/06/20 15:30:11 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int	ft_is_number(const char *str)
{
	size_t	i;
	int		check;

	check = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			check = 1;
		else
			return (0);
		i++;
	}
	return (check);
}

void	ft_send_char(char c, int pid)
{
	int	current_bit;

	current_bit = 0;
	while (current_bit < 8)
	{
		if (c & (1 << current_bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
		current_bit++;
	}
}

void	ft_send(char *str, int pid)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_send_char(str[i], pid);
		i++;
	}
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

int	main(int argv, char **args)
{
	if (argv == 3 && ft_is_number(args[1]) && args)
	{
		ft_send_integer(ft_int_size(args[2]), ft_atoi(args[1]));
		ft_send(args[2], ft_atoi(args[1]));
	}
	return (0);
}
