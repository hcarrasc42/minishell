/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:28:12 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/24 12:12:33 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

char	**ft_strremover(char **spl)
{
	int		i;
	int		j;
	char	**aux;

	i = 0;
	aux = spl;
	while (aux[i])
	{
		if (aux[i][0] == '<' || aux[i][0] == '>')
		{
			j = 0;
			while (aux[i][j])
			{
				aux[i][j] = ' ';
				j++;
			}
		}
		i++;
	}
	return (ft_arrsplit(aux, ' '));
}
