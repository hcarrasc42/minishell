/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:28:22 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/01 17:48:10 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

void	ft_outfile(t_data *d, t_split *s)
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

void	ft_infile(t_data *d, t_split *s)
{
	int		i;
	int		j;
	int		k;
	int		y;
	int		val;
	char	*s1;
	char	*s2;

	i = 0;
	val = 0;
	s1 = s->tmp[0];
	s2 = s->tmp[1];
	d->infile[0] = (char *)malloc(sizeof(char) * (ft_len_file(s) + 1));
	d->infile[1] = (char *)malloc(sizeof(char) * 2);
	while (s->tmp[i] && val == 0)
	{
		j = 0;
		while (s->tmp[i][j])
		{
			if (s->tmp[i][j] == '<')
			{
				val = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	i--;
	k = i;
	while (s->tmp[i] && val == 1 && k - i > 1)
	{
		y = 0;
		while (s->tmp[i][j])
		{
			if (s->tmp[i][j] == ' ' || s->tmp[i][j] == '\n' || s->tmp[i][j] == '\t')
			{
				val = 0;
				break ;
			}
			d->infile[0][y] = s->tmp[i][j];
			y++;
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_file(t_split *s, t_data *d)
{
	if (d->val)
	{
		ft_init_file(d);
		ft_infile(d, s);
		printf("infile: %s\n", d->infile[0]);
		printf("sing1: %s\n", d->infile[1]);
		if (d->val > 1)
		{
			ft_outfile(d, s);
			printf("outfile: %s\n", d->outfile[0]);
			printf("sing2: %s\n", d->outfile[1]);
		}
		d->infile[3] = 0;
		d->outfile[3] = 0;
	}
	return (0);
}
