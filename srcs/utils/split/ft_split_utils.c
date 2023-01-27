/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:50:59 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/27 15:02:47 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

int	ft_spaces(char *str, int i)
{
	if (str[i] == '\0' || str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
		return (1);
	return (0);
}

int	ft_jump_spaces(char *str, int i)
{
	while (ft_spaces(str, i))
		i++;
	return (i);
}

char	*ft_comillas(t_split *s, char *tmp, char *str, int n)
{
	s->i++;
	s->com = 1;
	while (str[s->i])
	{
		if (str[s->i] == n)
			s->com += 1;
		if (s->com == 2)
			break ;
		while (str[s->i] && str[s->i] != n)
		{
			tmp[s->j] = str[s->i];
			s->i++;
			s->j++;
		}
	}
	s->i++;
	return (tmp);
}

char	*ft_no_comillas(t_split *s, char *tmp, char *str)
{
	while (str[s->i] && str[s->i] != '\n' && str[s->i] != ' '
		&& str[s->i] != '\t' && str[s->i] != 34 && str[s->i] != 39)
	{
		tmp[s->j] = str[s->i];
		s->i++;
		s->j++;
	}
	return (tmp);
}

void	ft_len_while(t_split *s, char *str, int n)
{
	s->y++;
	while (str[s->y] != n)
	{
		s->len++;
		s->y++;
	}
	s->len--;
}
