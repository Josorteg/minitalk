/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:27:52 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/07 09:16:10 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	ind;

	res = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ind = 0;
	while (ind < ft_strlen(s))
	{
		res[ind] = f(ind, s[ind]);
		ind++;
	}
	res[ind] = '\0';
	return (res);
}
