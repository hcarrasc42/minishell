/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:56:12 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/28 13:58:09 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

int	ft_lspa(char *str, int i)
{
	if (str[i] == '\0' || str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
		return (1);
	return (0);
}

int	ft_line_len(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] == '"')
				i++;
		}
		if (str[i] == '|' && (!ft_lspa(str, i - 1) && !ft_lspa(str, i + 1)))
			len = len + 2;
		else if (str[i] == '|'
			&& (!ft_lspa(str, i - 1) || !ft_lspa(str, i + 1)))
			len++;
		i++;
		len++;
	}
	return (printf("ft_line_len: %d\n", len), len);
}

void	ft_comillas_pipe(t_split *s, int type)
{
	s->str[s->j] = s->read[s->i];
	s->j++;
	s->i++;
	while (s->read[s->i] != type)
	{
		s->str[s->j] = s->read[s->i];
		s->j++;
		s->i++;
	}
}

void	ft_space_pipe(t_split *s)
{
	s->i = 0;
	s->j = 0;
	s->str = (char *)malloc(sizeof(char) * (ft_line_len(s->read) + 1));
	while (s->read[s->i])
	{
		if (s->read[s->i] == 34)
			ft_comillas_pipe(s, 34);
		if (s->read[s->i] == 39)
			ft_comillas_pipe(s, 39);
		if (s->read[s->i] == '|' && !ft_lspa(s->read, s->i - 1))
		{
			s->str[s->j] = ' ';
			s->j++;
		}
		s->str[s->j] = s->read[s->i];
		s->j++;
		if (s->read[s->i] == '|' && !ft_lspa(s->read, s->i + 1))
		{
			s->str[s->j] = ' ';
			s->j++;
		}
		s->i++;
	}
	free(s->read);
	s->str[s->j] = '\0';
	s->read = s->str;
}
