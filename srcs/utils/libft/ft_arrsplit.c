/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:23:08 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/28 12:25:45 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

int	ft_arrlen_spc(char **aux)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (aux[i])
	{
		if (aux[i][0] == ' ')
			i++;
		i++;
		len++;
	}
	return (len);
}

char	**ft_arrsplit(char **aux, char c)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = (char **)malloc(sizeof(char *) * (ft_arrlen(aux) + 1));
	while (aux[i])
	{
		if (aux[i][0] == c)
			i++;
		if (!aux[i])
			break ;
		tmp[j] = ft_strdup(aux[i]);
		i++;
		j++;
	}
	tmp[j] = NULL;
	return (tmp);
}
