/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:54:19 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/14 13:57:33 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

void	ft_init_split(t_split *s)
{
	s->i = 0;
	s->j = 0;
	s->k = 0;
	s->y = 0;
	s->com = 0;
	s->len = 0;
	s->ft_len = ft_len(s->read);
	s->tmp = (char **)malloc(sizeof(char *) * (s->ft_len + 1));
}

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
		if (str[i] == '<' || str[i] == '>')
		{
			while (str[i] == '<' || str[i] == '>')
				i++;
			len++;
		}
		if (str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
			len++;
		i++;
	}
	return (printf("LEN: %d\n", len + 1), len + 1);
}

int	ft_lens(char *str, t_split *s)
{
	s->len = 0;
	s->y = s->i;
	while (str[s->y])
	{
		if (ft_spaces(str, s->y))
			return (printf("len1: %d\n", s->len), s->len);
		if (str[s->y] == 34)
			ft_len_while(s, str, 34);
		if (str[s->y] == 39)
			ft_len_while(s, str, 39);
		s->len++;
		s->y++;
	}
	return (printf("len2: %d\n", s->len), s->len);
}

char	*ft_split_core(t_data *d, t_split *s, char *tmp, char *str)
{
	s->j = 0;
	while (str[s->i])
	{
		if (ft_spaces(str, s->i))
			break ;
		else if (str[s->i] == 39)
			ft_comillas(d, s, str, 39);
		else if (str[s->i] == 34)
			ft_comillas(d, s, str, 34);
		else if (str[s->i] != 34 && str[s->i] != 39)
			ft_no_comillas(d, s, str);
	}
	if (d->val && !d->in)
		s->tmp[s->k][s->j] = '\0';
	d->val = 0;
	return (tmp);
}

char	**ft_split(t_data *d, t_split *s, char *str)
{
	ft_init_split(s);
	while (str[s->i] != '\0' && s->val == 0 && ft_find_char(str, s->i))
	{
		s->i = ft_jump_spaces(str, s->i);
		if (str[s->i] != '<' && str[s->i] != '>')
			s->tmp[s->k] = (char *)malloc(sizeof(char) * (ft_lens(str, s) + 1));
		ft_split_core(d, s, s->tmp[s->k], str);
		if (s->tmp[s->k][0] == 0)
			s->k--;
		s->k++;
	}
	s->tmp[s->k] = 0;
	return (s->tmp);
}
