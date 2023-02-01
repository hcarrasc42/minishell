/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:36:33 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/01 15:31:41 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.h"

void	ft_spaces_err(t_split *s)
{
	int		i;
	char	*str;

	i = 0;
	s->val = 0;
	str = s->read;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			return ;
		i++;
	}
	s->val = 1;
}

void	ft_error(t_split *s)
{
	ft_spaces_err(s);
}
