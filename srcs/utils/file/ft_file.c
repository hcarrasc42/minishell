/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:28:22 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/31 14:43:25 by hcarrasc         ###   ########.fr       */
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
	char	*s1;
	char	*s2;

	i = 0;
	j = 0;
	s1 = s->tmp[0];
	s2 = s->tmp[1];
	d->infile[0] = (char *)malloc(sizeof(char) * (ft_len_file(s1) + 1));
	d->infile[1] = (char *)malloc(sizeof(char) * 2);
	while (s1[i] && s1[i] != '<')
	{
		d->infile[0][j] = s1[i];
		j++;
		i++;
	}
	d->infile[0][j] = '\0';
	if (s1[i] == '\0')
		d->infile[1][0] = s2[0];
	else
		d->infile[1][0] = s1[i];
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
