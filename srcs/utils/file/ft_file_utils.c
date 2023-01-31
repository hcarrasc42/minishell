/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:51:47 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/31 14:45:40 by hcarrasc         ###   ########.fr       */
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

int	ft_len_file(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '<')
		len++;
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
