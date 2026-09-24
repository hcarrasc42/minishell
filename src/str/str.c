/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:32:43 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/21 09:25:16 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcpy_until_quoted(char *str)
{
	char	*newstr;
	int		i;

	newstr = ft_strdup(str);
	if (!newstr)
		exit_with_memory_error(NULL);
	i = 0;
	while (newstr[i])
	{
		if (is_arg_breaking_char(newstr[i]))
		{
			newstr[i] = '\0';
			break ;
		}
		i++;
	}
	return (newstr);
}

char	*ft_strcpy_until(char *str, char until)
{
	char	*newstr;
	int		i;

	newstr = ft_strdup(str);
	if (!newstr)
		exit_with_memory_error(NULL);
	i = 0;
	while (newstr[i])
	{
		if (newstr[i] == until)
		{
			newstr[i] = '\0';
			break ;
		}
		i++;
	}
	return (newstr);
}

char	*extract_str(char *str)
{
	char	*extract;
	char	*aux;

	if (!str || !*str)
		return (str);
	aux = ft_strdup(str);
	extract = ft_strtrim(aux, " ");
	free(aux);
	if (!extract || !*extract)
		return (extract);
	aux = extract;
	if (is_quote(*extract))
		extract = ft_strcpy_until(extract + 1, *extract);
	else
		extract = ft_strcpy_until_quoted(extract);
	free(aux);
	return (extract);
}

char	*ft_str_tolower(char *str)
{
	char	*aux;

	aux = str;
	while (str && *str)
	{
		*str = ft_tolower(*str);
		str++;
	}
	return (aux);
}
