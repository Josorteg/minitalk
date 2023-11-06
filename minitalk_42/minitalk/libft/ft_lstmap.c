/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:01:15 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/07 08:38:53 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*temp;
	t_list	*new;
	t_list	*res;

	if (!lst)
		return (NULL);
	res = NULL;
	while (lst)
	{
		temp = f(lst -> content);
		new = ft_lstnew(temp);
		if (!new)
		{
			ft_lstclear(&res, del);
			del (temp);
			return (NULL);
		}
		ft_lstadd_back(&res, new);
		lst = lst -> next;
	}
	return (res);
}
