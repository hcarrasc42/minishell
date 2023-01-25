/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:50:59 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/25 11:04:33 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/main.h"

int	ft_jump_spaces(char *str, int i)
{
	while (str[i] && (str[i] == '\n' || str[i] == ' '
			|| str[i] == '\t'))
		i++;
	return (i);
}

/* 			i++;
			while (str[i] && str[i] != 34)
			{
				tmp[k][j] = str[i];
				i++;
				j++;
			}
			i++; */

char	*ft_comillas(char *tmp, char *str, t_split *s)
{
	int	j;
	int	i;

	j = 0;
	i = s->i + 1;
	while (str[i] && str[i] != 34)
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	s->i = i + 1;
	tmp[j] = '\0';
	return (tmp);
}

/* 			while (str[i] && str[i] != '\n' && str[i] != ' '
				&& str[i] != '\t' && str[i] != 34)
			{
				tmp[k][j] = str[i];
				i++;
				j++;
			}
			tmp[k][j] = '\0'; */

char	*ft_no_comillas(char *tmp, char *str, t_split *s)
{
	int	j;
	int	i;

	j = 0;
	i = s->i;
	while (str[i] && str[i] != '\n' && str[i] != ' '
		&& str[i] != '\t' && str[i] != 34)
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	s->i = i;
	tmp[j] = '\0';
	return (tmp);
}
