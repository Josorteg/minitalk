/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:17:53 by josorteg          #+#    #+#             */
/*   Updated: 2023/06/21 19:29:25 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include"libft.h"
# include<unistd.h>
# include<stdio.h>
# include <signal.h>

typedef struct s_character
{
	char	*character;
	int		current_bit;
	int		current_byte;
}	t_character;

typedef struct s_int
{
	int		malloc_size;
	int		current_bit;
	int		boolean;
}	t_int;

int		ft_int_size(char *str);
void	handler_exit(int sig);
void	ft_send_integer(int n, int pid);

#endif
