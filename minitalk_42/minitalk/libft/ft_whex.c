/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:58:05 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/19 14:09:05 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_whex(unsigned int n)
{
	int	res;

	res = 0;
	res += ft_whe(n, "0123456789abcdef", 16);
	if (res == -1)
		return (-1);
	return (res);
}
