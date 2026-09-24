/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:15:41 by ruramire          #+#    #+#             */
/*   Updated: 2023/06/20 20:47:18 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux1;
	t_list	*aux2;

	if (!*f && !*del && !lst)
		return (NULL);
	aux1 = NULL;
	while (lst)
	{
		aux2 = ft_lstnew((*f)(lst->content));
		if (aux2 == NULL)
		{
			ft_lstclear(&aux1, del);
			return (NULL);
		}
		ft_lstadd_back(&aux1, aux2);
		lst = lst->next;
	}
	return (aux1);
}
