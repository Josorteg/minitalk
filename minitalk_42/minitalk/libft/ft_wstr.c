/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:41:31 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/18 12:15:12 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_wstr(char *str)
{
	int	res;
	int	car;

	if (!str)
		str = "(null)";
	car = 0;
	res = 0;
	while (*str)
	{
		car = write(1, str++, 1);
		if (car != 1)
			return (-1);
		res += car;
	}
	return (res);
}
