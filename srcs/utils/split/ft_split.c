/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:54:19 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/26 14:09:59 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

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
	/* if (str[i] == 34)
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
	} */

int	ft_len_spa(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i])
	{
		if (str[i] == '\0' || str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
			return (len);
		if (str[i] == 34)
		{
			i++;
			while (str[i] != 34)
			{
				len++;
				i++;
			}
			len--;
		}
		if (str[i] == 39)
		{
			i++;
			while (str[i] != 39)
			{
				len++;
				i++;
			}
			len--;
		}
		len++;
		i++;
	}
	return (len);
}

void	ft_init_split(t_split *s)
{
	s->k = 0;
	s->len = ft_len(s->read);
	s->tmp = (char **)malloc(sizeof(char *) * (s->len + 1));
}

char	**ft_split(t_split *s, char *str)
{
	int		i;

	i = 0;
	ft_init_split(s);
	while (str[i])
	{
		i = ft_jump_spaces(str, i);
		s->tmp[s->k] = (char *)malloc(sizeof(char) * (ft_len_spa(str, i) + 1));
		s->i = i;
		ft_split_core(s->tmp[s->k], s);
		i = s->i;
		s->k++;
	}
	s->tmp[s->k] = 0;
	free(s->tmp);
	return (s->tmp);
}
