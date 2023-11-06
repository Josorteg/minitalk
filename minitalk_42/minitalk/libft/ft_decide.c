/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:40:51 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/19 14:22:22 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_decide(unsigned char l, va_list args)
{
	int	res;

	res = 0;
	if (l == 'c')
		return (ft_wchar(va_arg(args, int)));
	else if (l == 's')
		return (ft_wstr(va_arg(args, char *)));
	else if (l == 'd' || l == 'i')
		return (ft_wint(va_arg(args, int)));
	else if (l == 'u')
		return (ft_wuint(va_arg(args, unsigned int)));
	else if (l == 'p')
		return (ft_whep(va_arg(args, unsigned long)));
	else if (l == 'x')
		return (ft_whex(va_arg(args, unsigned long)));
	else if (l == 'X')
		return (ft_whexx(va_arg(args, unsigned long)));
	else if (l == '%')
		return (write(1, "%", 1));
	else
		return (0);
}
