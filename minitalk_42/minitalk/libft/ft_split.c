/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:44:08 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/04 12:13:56 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_count_char(const char *str, char c)
{
	size_t		i;
	size_t		count;

	count = 0;
	i = 0;
	while (1)
	{
		if (str[i] == c || str[i] == '\0')
		{
			if (i != 0)
				count++;
			if (str[i] == '\0')
				break ;
			while (str[i] == c)
				i++;
			if (str[i] == '\0')
				break ;
		}
		else
			i++;
	}
	return (count);
}

static void	*clean(char **list, size_t len)
{
	while (len--)
		free(list[len]);
	free(list);
	return (NULL);
}

static char const	*ahorro(char const *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	np;
	unsigned int	lp;
	char			**res;

	np = ft_count_char(s, c);
	res = (char **)malloc((np + 1) * sizeof (char **));
	np = 0;
	if (!res)
		return (NULL);
	while (*s)
	{
		s = ahorro(s, c);
		lp = 0;
		while (s[lp] != c && s[lp] != '\0')
			lp++;
		if (lp)
		{
			res[np] = ft_substr(s, 0, lp);
			if (res[np++] == NULL)
				return (clean(res, np));
			s += lp;
		}		
	}
	res[np] = NULL;
	return (res);
}
