/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:50:59 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/26 10:57:02 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

int	ft_jump_spaces(char *str, int i)
{
	while (str[i] && (str[i] == '\n' || str[i] == ' '
			|| str[i] == '\t'))
		i++;
	return (i);
}

char	*ft_comillas(char *tmp, t_split *s)
{
	char	*str;
	int		j;
	int		i;

	j = 0;
	i = s->i + 1;
	str = s->read;
	while (str[i] && str[i] != 34)
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	s->i = i + 1;
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_no_comillas(char *tmp, t_split *s)
{
	char	*str;
	int		j;
	int		i;

	j = 0;
	i = s->i;
	str = s->read;
	while (str[i] && str[i] != '\n' && str[i] != ' '
		&& str[i] != '\t' && str[i] != 34)
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	s->i = i;
	tmp[j] = '\0';
	return (tmp);
}

/* char	*ft_split_core(char *tmp, char *str, t_split *s)
{
	
} */
