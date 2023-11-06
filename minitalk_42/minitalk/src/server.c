/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:17:42 by josorteg          #+#    #+#             */
/*   Updated: 2023/06/20 12:50:44 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	ft_write_bits(int sig, t_character *chr, t_int *integer)
{
	if (sig == SIGUSR2 && integer->boolean == 1)
		chr->character[chr->current_byte] |= 1 << chr->current_bit;
	if (integer->boolean == 1)
		chr->current_bit++;
	if (chr->current_bit == 8 && integer->boolean == 1)
	{
		chr->current_byte += 1;
		chr->current_bit = 0;
	}
	if (integer->boolean == 1 && (chr->current_byte == integer->malloc_size))
	{
		chr->character[chr->current_byte] = '\0';
		write(1, chr->character, integer->malloc_size);
		free(chr->character);
		integer->boolean = 0;
		integer->malloc_size = 0;
		integer->current_bit = 0;
		chr->current_bit = 0;
		chr->current_byte = 0;
	}
}

void	handler_msg(int sig)
{
	static struct s_character	chr;
	static struct s_int			integer;

	if (integer.boolean != 1)
	{
		if (sig == SIGUSR2)
			integer.malloc_size |= 1 << integer.current_bit;
		integer.current_bit++;
		if (integer.current_bit == 32)
		{
			integer.malloc_size = (int)integer.malloc_size;
			chr.character = malloc ((integer.malloc_size + 1) * sizeof(char));
			if (!chr.character)
				exit(0);
			integer.boolean = 1;
		}
	}
	else
		ft_write_bits(sig, &chr, &integer);
}

void	handler_exit(int sig)
{
	(void)sig;
	exit(0);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal(SIGUSR1, handler_msg);
	signal(SIGUSR2, handler_msg);
	signal(SIGINT, handler_exit);
	signal(SIGTERM, handler_exit);
	while (1)
		pause();
}
