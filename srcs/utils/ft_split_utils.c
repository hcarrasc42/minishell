/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:50:59 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/24 13:19:12 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/main.h"

void	ft_jump_spaces(char *str, t_split s)
{
	while (str[s.i] && (str[s.i] == '\n' || str[s.i] == ' '
			|| str[s.i] == '\t'))
		s.i++;
	return ;
}

char	*ft_comillas(char *tmp, char *str, t_split *s)
{
	int	j;

	j = 0;
	s->i++;
	while (str[s->i] && str[s->i] != 34)
	{
		tmp[j] = str[s->i];
		s->i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_no_comillas(char *tmp, char *str, t_split *s)
{
	int	j;

	j = 0;
	while (str[s->i] && str[s->i] != '\n'
		&& str[s->i] != ' ' && str[s->i] != '\t')
	{
		tmp[j] = str[s->i];
		s->i++;
		j++;
		printf("entra\n");
	}
	tmp[j] = '\0';
	return (tmp);
}
