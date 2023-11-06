/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:17:42 by josorteg          #+#    #+#             */
/*   Updated: 2023/06/21 19:29:17 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	ft_write_b(int sig, t_character *chr, t_int *integer, siginfo_t *info)
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
		if (kill(info->si_pid, SIGUSR1) == -1)
			handler_exit(SIGUSR1);
	}
}

void	handler_msg(int sig, siginfo_t *info, void *data)
{
	static struct s_character	chr;
	static struct s_int			integer;

	(void)data;
	if (integer.boolean != 1)
	{
		if (sig == SIGUSR2)
			integer.malloc_size |= 1 << integer.current_bit;
		integer.current_bit++;
		if (integer.current_bit == 32)
		{
			kill(info->si_pid, SIGUSR2);
			integer.malloc_size = (int)integer.malloc_size;
			chr.character = malloc ((integer.malloc_size + 1) * sizeof(char));
			if (!chr.character)
				exit(0);
			integer.boolean = 1;
		}
	}
	else
		ft_write_b(sig, &chr, &integer, info);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = handler_msg;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		handler_exit(SIGUSR1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		handler_exit(SIGUSR2);
	signal(SIGINT, handler_exit);
	signal(SIGTERM, handler_exit);
	while (1)
		pause();
}
