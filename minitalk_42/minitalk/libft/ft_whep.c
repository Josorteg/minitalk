/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:54:11 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/19 14:10:28 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_whep(unsigned long n)
{
	int	res;

	res = 0;
	res += write(1, "0x", 2);
	if (res != 2)
		return (-1);
	res += ft_whe(n, "0123456789abcdef", 16);
	if (res == 1)
		return (-1);
	return (res);
}
