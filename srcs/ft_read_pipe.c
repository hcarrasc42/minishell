/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:56:12 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/17 13:44:28 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.h"

int	ft_lspa(char *str, int i)
{
	if (str[i] == '\0' || str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
		return (1);
	return (0);
}

int	ft_line_len(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] == '"')
				i++;
		}
		if (str[i] == '|' && (!ft_lspa(str, i - 1) && !ft_lspa(str, i + 1)))
			len = len + 2;
		else if (str[i] == '|'
			&& (!ft_lspa(str, i - 1) || !ft_lspa(str, i + 1)))
			len++;
		i++;
		len++;
	}
	return (len);
}

void	ft_read_pipe(t_split *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_line_len(s->read) + 1));
	while (s->read[i])
	{
		if (s->read[i] == 34)
		{
			str[j] = s->read[i];
			j++;
			i++;
			while (s->read[i] != 34)
			{
				str[j] = s->read[i];
				j++;
				i++;
			}
		}
		if (s->read[i] == 39)
		{
			str[j] = s->read[i];
			j++;
			i++;
			while (s->read[i] != 39)
			{
				str[j] = s->read[i];
				j++;
				i++;
			}
		}
		if (s->read[i] == '|' && !ft_lspa(s->read, i - 1))
		{
			str[j] = ' ';
			j++;
		}
		str[j] = s->read[i];
		j++;
		if (s->read[i] == '|' && !ft_lspa(s->read, i + 1))
		{
			str[j] = ' ';
			j++;
		}
		i++;
	}
	str[j] = '\0';
	s->read = str;
}
