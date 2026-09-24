/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:55:41 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/20 18:09:41 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_node_content(void *content)
{
	t_redirection	*redirection;

	redirection = content;
	if (!redirection)
		return ;
	if (redirection->file != NULL)
		free(redirection->file);
	free(redirection);
}

void	free_redirections(t_list *redirections)
{
	if (!redirections)
		return ;
	ft_lstclear(&redirections, free_node_content);
}

t_redirection	*get_redirection(t_list *redirection_node)
{
	if (redirection_node && redirection_node->content)
		return ((t_redirection *)redirection_node->content);
	return (NULL);
}
