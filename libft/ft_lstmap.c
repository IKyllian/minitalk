/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:04:36 by kdelport          #+#    #+#             */
/*   Updated: 2020/11/27 16:21:40 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*elmt;

	if (!lst)
		return (NULL);
	if (!(elmt = ft_lstnew((*f)(lst->content))))
	{
		ft_lstclear(&list, del);
		return (NULL);
	}
	list = elmt;
	while (lst->next)
	{
		lst = lst->next;
		if (!(elmt = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, elmt);
	}
	return (list);
}
