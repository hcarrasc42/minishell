/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:28:22 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/03/02 14:29:11 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

void	ft_outfile(t_split *s)
{
	int		j;
	char	*outfile;

	j = 0;
	outfile = (char *)malloc(sizeof(char) * (ft_len_file(s, '>') + 1));
	while (s->read[s->i] == '>')
	{
		outfile[j] = s->read[s->i];
		s->i++;
		j++;
	}
	while (ft_is_space_char(s->read[s->i]))
		s->i++;
	while (s->read[s->i] && !ft_is_space_char(s->read[s->i])
		&& s->read[s->i] != '<' && s->read[s->i] != '>')
	{
		outfile[j] = s->read[s->i];
		j++;
		s->i++;
	}
	outfile[j] = '\0';
	s->tmp[s->k] = outfile;
}

void	ft_infile(t_split *s)
{
	int		j;
	char	*infile;

	j = 0;
	infile = (char *)malloc(sizeof(char) * (ft_len_file(s, '<') + 1));
	while (s->read[s->i] == '<')
	{
		infile[j] = s->read[s->i];
		s->i++;
		j++;
	}
	while (ft_is_space_char(s->read[s->i]))
		s->i++;
	while (s->read[s->i] && !ft_is_space_char(s->read[s->i])
		&& s->read[s->i] != '<' && s->read[s->i] != '>')
	{
		infile[j] = s->read[s->i];
		j++;
		s->i++;
	}
	infile[j] = '\0';
	s->tmp[s->k] = infile;
}

int	ft_file(t_data *d, t_split *s)
{
	d->infile = 0;
	if (s->read[s->i] == '<')
	{
		d->in = 1;
		ft_infile(s);
	}
	else
	{
		d->out = 1;
		ft_outfile(s);
	}
	return (0);
}
