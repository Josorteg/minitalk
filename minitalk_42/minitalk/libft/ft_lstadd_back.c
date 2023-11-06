/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:38:44 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/07 08:07:42 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{	
	t_list	*m;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	m = ft_lstlast(*lst);
	m -> next = new;
}
