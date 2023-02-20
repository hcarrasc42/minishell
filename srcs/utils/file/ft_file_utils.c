/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:51:47 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/20 12:40:40 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

void	ft_init_file(t_data *d)
{
	d->input = 0;
	d->output = 0;
	d->val = 0;
	d->in = 0;
	d->out = 0;
	d->outfile = 0;
	d->infile = 0;
}

int	ft_is_space_char(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	ft_len_file(t_split *s, char c)
{
	int	len;
	int	i;

	len = 0;
	i = s->i;
	while (s->read[i] == c)
	{
		i++;
		len++;
	}
	while (ft_is_space_char(s->read[i]))
		i++;
	while (s->read[i] && !ft_is_space_char(s->read[i]) && s->read[i] != c)
	{
		i++;
		len++;
	}
	return (printf("filelen: %d\n", len), len);
}
