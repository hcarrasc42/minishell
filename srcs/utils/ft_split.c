/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:54:19 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/24 14:08:57 by hcarrasc         ###   ########.fr       */
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

char	**ft_split(char *str)
{
	int		j;
	int		i;
	int		k;
	int		len;
	char	**tmp;

	len = ft_len(str);
	tmp = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'))
			i++;
		tmp[k] = (char *)malloc(sizeof(char) * (ft_len_spaces(str, i) + 1));
		if (str[i] == 34)
		{
			i++;
			while (str[i] && str[i] != 34)
			{
				tmp[k][j] = str[i];
				i++;
				j++;
			}
			i++;
		}
		else
		{
			while (str[i] && str[i] != '\n' && str[i] != ' '
				&& str[i] != '\t' && str[i] != 34)
			{
				tmp[k][j] = str[i];
				i++;
				j++;
			}
		}
		tmp[k][j] = '\0';
		k++;
	}
	tmp[k] = NULL;
	return (tmp);
}

char	**ft_split_init(char *str)
{
	char	**aux;

	aux = ft_split(str);
	return (aux);
}
