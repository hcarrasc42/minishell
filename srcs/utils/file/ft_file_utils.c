/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:51:47 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/01 17:41:37 by hcarrasc         ###   ########.fr       */
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

int	ft_len_file(t_split *s)
{
	int		len;
	int		i;
	int		j;
	int		val;
	int		k;
	char	*str;

	len = 0;
	i = 0;
	str = s->tmp;
	val = 0;
	while (str[i] && val == 0)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '<')
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
	while (str[i] && val == 1 && k - i > 1)
	{
		while (str[i][j])
		{
			if (str[i][j] == ' ' || str[i][j] == '\n' || str[i][j] == '\t')
			{
				val = 0;
				break ;
			}
			len++;
			j++;
		}
		j = 0;
		i++;
	}
	return (len);
}

void	ft_init_file(t_data *d)
{
	d->cmd = 0;
	d->input = 0;
	d->output = 0;
	d->infile = (char **)malloc(sizeof(char *) * 3);
	d->outfile = (char **)malloc(sizeof(char *) * 3);
}
