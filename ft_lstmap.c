/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:21:21 by fassier-          #+#    #+#             */
/*   Updated: 2021/12/08 14:51:56 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*begin;
	t_list	*work;

	if (!lst)
		return (NULL);
	begin = ft_lstnew(f(lst->content));
	work = begin;
	while (lst->next)
	{
		lst = lst->next;
		work->next = ft_lstnew(f(lst->content));
		if (work->next == NULL)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		work = work->next;
	}
	return (begin);
}
