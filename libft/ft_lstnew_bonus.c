/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:35:27 by ruramire          #+#    #+#             */
/*   Updated: 2023/06/20 20:47:23 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnodo;

	newnodo = malloc(sizeof(t_list));
	if (!newnodo)
		return (NULL);
	newnodo->content = content;
	newnodo->next = NULL;
	return (newnodo);
}
