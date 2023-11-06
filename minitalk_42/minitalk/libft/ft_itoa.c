/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:31:31 by josorteg          #+#    #+#             */
/*   Updated: 2022/09/30 10:59:03 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_count(int n)
{
	unsigned int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	if (!count)
		count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	mem;

	if (n == -2147483648)
		return (ft_substr("-2147483648", 0, 11));
	mem = ft_count (n);
	res = (char *)malloc((mem + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[mem] = '\0';
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	if (n == 0)
		res[0] = (0 + 48);
	while (n > 0)
	{	
		res[mem - 1] = (n % 10 + 48);
		n = n / 10;
		mem--;
	}
	return (res);
}
