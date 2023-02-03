/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:51:47 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/03 15:27:47 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

int	ft_is_space(char c)
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
	if (ft_is_space(s->read[i + 1])
		|| (s->read[i + 1] == c && ft_is_space(s->read[i + 2])))
	{
		if (s->read[i + 1] == c && ft_is_space(s->read[i + 2]))
		{
			i = i + 1;
			len++;
		}
		i = i + 2;
		len++;
	}
	while (s->read[i] && !ft_is_space(s->read[i]))
	{
		i++;
		len++;
	}
	return (printf("filelen: %d\n", len), len);
}

void	ft_init_file(t_data *d)
{
	d->cmd = 0;
	d->input = 0;
	d->output = 0;
}
