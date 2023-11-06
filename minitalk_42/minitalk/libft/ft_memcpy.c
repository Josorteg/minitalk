/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:57:40 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/06 10:39:52 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h" 

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int					i;
	unsigned char		*p;
	unsigned const char	*s;

	p = dst;
	i = 0;
	s = src;
	if (p == s)
		return (dst);
	while (i < (int)n)
	{
		p[i] = s[i];
		i++;
	}
	return (dst);
}
