/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:28:22 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/03 15:25:29 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

int	ft_is_spaces(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

void	ft_outfile_while(t_data *d, t_split *s, int y)
{
	while (s->tmp[s->i][s->j])
	{
		d->outfile[y] = s->tmp[s->i][s->j];
		printf("ou: %c\n", d->outfile[y]);
		y++;
		s->j++;
	}
	d->infile[y] = '\0';
}

void	ft_outfile(t_data *d, t_split *s)
{
	int	y;

	y = 0;
	d->outfile = (char *)malloc(sizeof(char) * (ft_len_file(s, '>') + 1));
	if (s->tmp[s->i][s->j + 1] == '\0')
	{
		d->outfile[y] = s->tmp[s->i][s->j];
		y++;
		s->j = 0;
		s->i++;
	}
	else if (s->tmp[s->i][s->j + 1] == '>' && s->tmp[s->i][s->j + 2] == '\0')
	{
		while (s->tmp[s->i][s->j])
		{
			d->outfile[y] = s->tmp[s->i][s->j];
			y++;
			s->j++;
		}
		s->j = 0;
		s->i++;
	}
	ft_outfile_while(d, s, y);
}

void	ft_infile(t_data *d, t_split *s)
{
	int		j;

	j = 0;
	d->infile = (char *)malloc(sizeof(char) * (ft_len_file(s, '<') + 1));
	if (ft_is_spaces(s->read[s->i + 1])
		|| (s->read[s->i + 1] == '<' && ft_is_spaces(s->read[s->i + 2])))
	{
		if (s->read[s->i + 1] == '<' && ft_is_spaces(s->read[s->i + 2]))
		{
			d->infile[j] = s->read[s->i];
			s->i = s->i + 1;
			j++;
		}
		d->infile[j] = s->read[s->i];
		s->i = s->i + 2;
		j++;
	}
	while (s->read[s->i] && !ft_is_spaces(s->read[s->i]))
	{
		d->infile[j] = s->read[s->i];
		j++;
		s->i++;
	}
	d->infile[j] = '\0';
	s->tmp[s->k] = d->infile;
}

int	ft_file(t_data *d, t_split *s)
{
	ft_init_file(d);
	ft_infile(d, s);
	return (0);
}
		/* if (d->val > 1)
		{
			ft_outfile(d, s);
			printf("outfile: %s\n", d->outfile);
		}
 */