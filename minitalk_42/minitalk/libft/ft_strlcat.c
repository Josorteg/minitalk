/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:57:59 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/06 10:43:00 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	ldst;
	unsigned int	i;

	ldst = ft_strlen(dst);
	i = 0;
	if (dstsize <= ldst)
		return (dstsize + ft_strlen(src));
	while (src[i] && (ldst + 1 < dstsize))
	{
		dst[ldst] = src[i];
		i++;
		ldst++;
	}
	dst[ldst] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
