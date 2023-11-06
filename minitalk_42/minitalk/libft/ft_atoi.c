/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:43:04 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/06 10:44:02 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	sign;
	unsigned int	num;

	sign = 1;
	while ((9 <= *str && 13 >= *str) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	num = 0;
	while (48 <= *str && 57 >= *str)
	{
		num = ((*str) - '0') + num * 10;
		str++;
	}
	return (num * sign);
}
