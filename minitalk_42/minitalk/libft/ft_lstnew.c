/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 08:37:16 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/07 08:17:01 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*first;

	first = NULL;
	first = (t_list *) malloc (sizeof(t_list));
	if (!first)
		return (NULL);
	first -> content = content;
	first -> next = NULL;
	return (first);
}
