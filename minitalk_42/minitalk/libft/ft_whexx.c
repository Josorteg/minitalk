/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whexX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:04:12 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/19 14:09:37 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

int	ft_whexx(unsigned int n)
{
	int	res;

	res = 0;
	res += ft_whe(n, "0123456789ABCDEF", 16);
	if (res == -1)
		return (-1);
	return (res);
}
