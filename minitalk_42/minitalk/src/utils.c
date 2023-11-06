/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 08:53:51 by josorteg          #+#    #+#             */
/*   Updated: 2023/06/20 12:51:10 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	return (bytes);
}
