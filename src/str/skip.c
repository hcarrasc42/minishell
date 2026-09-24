/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:01:08 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/21 09:19:32 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*skip_until_char_quoted(char *str)
{
	while (str && *str)
	{
		if (is_arg_breaking_char(*str))
			break ;
		str++;
	}
	return (str);
}

static char	*skip_until_char(char *str, char c)
{
	while (str && *str && *str != c)
	{
		str++;
	}
	if (*str == c)
		str++;
	return (str);
}

char	*skip_token_str(char *str, t_token_type type)
{
	if (type == TOKEN_GREAT && *str == '>')
		return (str + 1);
	if (type == TOKEN_GREATGREAT && *str == '>')
		return (str + 2);
	if (type == TOKEN_LESS && *str == '<')
		return (str + 1);
	if (type == TOKEN_LESSLESS && *str == '<')
		return (str + 2);
	if (type == TOKEN_PIPE && *str == '|')
		return (str + 1);
	if (type == TOKEN_AMP && *str == '&')
		return (str + 1);
	return (str);
}

char	*skip_enclosed_str(char *str)
{
	if (!str || !*str)
		return (str);
	while (str && *str && is_space(*str))
		str++;
	if (is_quote(*str))
		str = skip_until_char(str + 1, *str);
	else
		str = skip_until_char_quoted(str + 1);
	return (str);
}
