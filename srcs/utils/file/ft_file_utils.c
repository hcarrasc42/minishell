/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:51:47 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/02 12:41:42 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

void	ft_file_0(t_data *d, char *s1)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] == '>')
	{
		d->outfile[1][j] = s1[i];
		i++;
		j++;
	}
	d->outfile[1][j] = '\0';
	j = 0;
	while (s1[i])
	{
		d->outfile[0][j] = s1[i];
		j++;
		i++;
	}
	d->outfile[0][j] = '\0';
}

void	ft_len_util(t_split *s, char c)
{
	int		val;

	val = 0;
	s->i = 0;
	while (s->tmp[s->i] && val == 0)
	{
		s->j = 0;
		while (s->tmp[s->i][s->j])
		{
			if (s->tmp[s->i][s->j] == c)
			{
				val = 1;
				break ;
			}
			s->j++;
		}
		s->i++;
	}
	s->i--;
}

int	ft_len_file(t_split *s)
{
	int	len;
	int	i;
	int	j;

	ft_len_util(s, '<');
	len = 0;
	i = s->i;
	j = s->j;
	if (s->tmp[i][j + 1] == '\0' || s->tmp[i][j + 2] == '\0')
	{
		j = 0;
		i++;
	}
	while (s->tmp[i][j])
	{
		len++;
		j++;
	}
	return (printf("filelen: %d\n", len), len);
}

void	ft_init_file(t_data *d)
{
	d->cmd = 0;
	d->input = 0;
	d->output = 0;
	d->outfile = (char **)malloc(sizeof(char *) * 3);
}
