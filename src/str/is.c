/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:40:03 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/21 09:19:20 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\r' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\n')
		return (1);
	return (0);
}

int	is_quote(char c)
{
	if (c == '\"' || c == '\'')
		return (1);
	return (0);
}

int	is_arg_breaking_char(char c)
{
	if (is_space(c) || is_quote(c) || c == '|' || c == '>'
		|| c == '<' || c == '&')
		return (1);
	return (0);
}
