/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:54:19 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/25 11:10:13 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/main.h"

int	ft_len(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] && (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
			len++;
		i++;
	}
	return (len + 1);
}

int	ft_len_spaces(char *str, int i)
{
	int	len;

	len = 0;
	if (str[i] == 34)
	{
		i++;
		while (str[i] && str[i] != 34)
		{
			len++;
			i++;
		}
		return (len);
	}
	while (str[i])
	{
		if (str[i] == '\0' || str[i] == '\n' || str[i] == ' ' || str[i] == '\t'
			|| str[i] == 34)
			return (len);
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(char *str, t_split *s)
{
	int		i;
	char	**tmp;

	i = 0;
	s->k = 0;
	s->len = ft_len(str);
	tmp = (char **)malloc(sizeof(char *) * (s->len + 1));
	while (str[i])
	{
		i = ft_jump_spaces(str, i);
		tmp[s->k] = (char *)malloc(sizeof(char) * (ft_len_spaces(str, i) + 1));
		s->i = i;
		if (str[i] == 34)
			tmp[s->k] = ft_comillas(tmp[s->k], str, s);
		else
			tmp[s->k] = ft_no_comillas(tmp[s->k], str, s);
		i = s->i;
		s->k++;
	}
	tmp[s->k] = NULL;
	free(tmp);
	return (tmp);
}

char	**ft_split_init(char *str)
{
	char	**aux;
	t_split	s;

	aux = ft_split(str, &s);
	return (aux);
}
