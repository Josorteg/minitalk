/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:25:53 by josorteg          #+#    #+#             */
/*   Updated: 2022/09/28 10:29:13 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			j;
	char			*mem;

	mem = s;
	j = '\0';
	i = 0;
	while (i < n)
	{
		mem[i] = j;
		i++;
	}
}
