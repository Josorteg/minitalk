/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:49:36 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/06 10:41:01 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	len;
	unsigned int	ind;

	ind = 0;
	start = 0;
	len = ft_strlen(s1);
	if (!len)
		return (ft_strdup(""));
	while (ft_strchr (set, s1[len - 1]) && len - 1 > 0)
		len--;
	while (ft_strchr (set, s1[ind]))
	{
		ind++;
		start++;
		len--;
	}
	if (len <= 0)
		return (ft_strdup(""));
	return (ft_substr (s1, start, len));
}
