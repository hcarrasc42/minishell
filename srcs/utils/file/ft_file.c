/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:28:22 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/02 12:31:50 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

/* void	ft_outfile(t_data *d, t_split *s)
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;

	j = 0;
	i = ft_len_split(s) - 1;
	s1 = s->tmp[i];
	s2 = s->tmp[i - 1];
	d->outfile[0] = (char *)malloc(sizeof(char) * (ft_len_file(s1) + 1));
	d->outfile[1] = (char *)malloc(sizeof(char) * 2);
	ft_file_0(d, s1);
}
 */
void	ft_infile_while(t_data *d, t_split *s, int y)
{
	while (s->tmp[s->i][s->j])
	{
		d->infile[y] = s->tmp[s->i][s->j];
		printf("in: %c\n", d->infile[y]);
		y++;
		s->j++;
	}
	d->infile[y] = '\0';
}

void	ft_infile(t_data *d, t_split *s)
{
	int		y;

	y = 0;
	d->infile = (char *)malloc(sizeof(char) * (ft_len_file(s) + 1));
	if (s->tmp[s->i][s->j + 1] == '\0')
	{
		d->infile[y] = s->tmp[s->i][s->j];
		y++;
		s->j = 0;
		s->i++;
	}
	else if (s->tmp[s->i][s->j + 1] == '<' && s->tmp[s->i][s->j + 2] == '\0')
	{
		while (s->tmp[s->i][s->j])
		{
			d->infile[y] = s->tmp[s->i][s->j];
			y++;
			s->j++;
		}
		s->j = 0;
		s->i++;
	}
	ft_infile_while(d, s, y);
}

int	ft_file(t_split *s, t_data *d)
{
	if (d->val)
	{
		ft_init_file(d);
		ft_infile(d, s);
		printf("infile: %s\n", d->infile);
		//printf("sing1: %s\n", d->infile[1]);
		/* if (d->val > 1)
		{
			ft_outfile(d, s);
			printf("outfile: %s\n", d->outfile[0]);
			printf("sing2: %s\n", d->outfile[1]);
		} */
		//d->outfile[3] = 0;
	}
	return (0);
}
