/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:52:27 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/06 10:42:03 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	ind;

	ind = 0;
	if (n == 0)
		return (0);
	while (((*(s1 + ind) && *(s2 + ind)) != '\0') && ind < (n - 1))
	{
		if (*(s1 + ind) != *(s2 + ind))
			return (((unsigned char *)s1)[ind] - ((unsigned char *)s2)[ind]);
		ind++;
	}
	return (((unsigned char *)s1)[ind] - ((unsigned char *)s2)[ind]);
}
