/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:28:22 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/28 14:33:43 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

void	ft_outfile(t_data *d, t_split *s)
{
	int		j;

	j = 0;
	d->outfile = (char *)malloc(sizeof(char) * (ft_len_file(s, '>') + 1));
	while (s->read[s->i] == '>')
	{
		d->outfile[j] = s->read[s->i];
		s->i++;
		j++;
	}
	while (ft_is_space_char(s->read[s->i]))
		s->i++;
	while (s->read[s->i] && !ft_is_space_char(s->read[s->i])
		&& s->read[s->i] != '<' && s->read[s->i] != '>')
	{
		d->outfile[j] = s->read[s->i];
		j++;
		s->i++;
	}
	d->outfile[j] = '\0';
	s->tmp[s->k] = d->outfile;
	free(d->outfile);
}

void	ft_infile(t_data *d, t_split *s)
{
	int		j;

	j = 0;
	s->tmp[s->k] = (char *)malloc(sizeof(char) * (ft_len_file(s, '<')));
	while (s->read[s->i] == '<')
	{
		s->tmp[s->k][j] = s->read[s->i];
		s->i++;
		j++;
	}
	while (ft_is_space_char(s->read[s->i]))
		s->i++;
	while (s->read[s->i] && !ft_is_space_char(s->read[s->i])
		&& s->read[s->i] != '<' && s->read[s->i] != '>')
	{
		s->tmp[s->k][j] = s->read[s->i];
		j++;
		s->i++;
	}
	s->tmp[s->k][j] = '\0';
}

int	ft_file(t_data *d, t_split *s)
{
	if (s->read[s->i] == '<')
	{
		d->in = 1;
		ft_infile(d, s);
	}
	else
	{
		d->out = 1;
		ft_outfile(d, s);
	}
	return (0);
}
