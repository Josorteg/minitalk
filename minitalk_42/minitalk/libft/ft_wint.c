/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:50:41 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/19 14:10:11 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_wint(int n)
{
	int	res;

	res = 0;
	if (n == -2147483648)
	{
		res = write (1, "-2147483648", 11);
		if (res != 11)
			return (-1);
		return (res);
	}
	if (n < 0)
	{
		res += ft_wchar('-');
		if (res != 1)
			return (-1);
		n = -n;
	}
	return (res += ft_whe(n, "0123456789", 10));
}
