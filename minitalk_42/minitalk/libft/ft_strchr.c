/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:56:01 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/03 12:38:41 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		large;

	large = ft_strlen(s);
	i = 0;
	while (i <= large)
	{
		if (s[i] == (char) c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
