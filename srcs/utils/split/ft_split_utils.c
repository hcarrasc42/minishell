/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:50:59 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/03/01 14:19:19 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

int	ft_jump_spaces(char *str, int i)
{
	while (ft_spaces(str, i))
		i++;
	return (printf("jump spaces: %d\n", i), i);
}

int	ft_infile_outfile(t_split *s, char *str)
{
	int	i;

	i = s->i;
	while (str[i] == '<' || str[i] == '>')
		i++;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
			return (0);
		if (str[i] == '<' || str[i] == '>')
		{
			s->k++;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_comillas(t_data *d, t_split *s, char *str, int n)
{
	s->com = 0;
	d->val = 1;
	while (str[s->i])
	{
		if (str[s->i] == n)
		{
			s->tmp[s->k][s->j] = str[s->i];
			s->j++;
			s->i++;
			s->com += 1;
		}
		if (s->com == 2)
			break ;
		while (str[s->i] && str[s->i] != n)
		{
			s->tmp[s->k][s->j] = str[s->i];
			s->i++;
			s->j++;
		}
	}
	return (0);
}

char	*ft_no_comillas(t_data *d, t_split *s, char *str)
{
	while (str[s->i] && str[s->i] != '\n' && str[s->i] != ' '
		&& str[s->i] != '\t' && str[s->i] != 34 && str[s->i] != 39)
	{
		if (str[s->i] == '<' || str[s->i] == '>')
		{
			if (d->val)
			{
				s->tmp[s->k][s->j] = '\0';
				s->k++;
			}
			if (d->in || d->out)
				ft_infile_outfile(s, str);
			ft_file(d, s);
			return (0);
		}
		d->val = 1;
		s->tmp[s->k][s->j] = str[s->i];
		s->i++;
		s->j++;
	}
	return (0);
}

void	ft_len_while(t_split *s, char *str, int n)
{
	s->y++;
	while (str[s->y] != n)
	{
		s->len++;
		s->y++;
	}
	s->len++;
}
