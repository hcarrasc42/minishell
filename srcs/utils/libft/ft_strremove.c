/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:28:12 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/23 13:32:16 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

char	**ft_strremover(char **spl)
{
	int		i;
	int		j;

	i = 0;
	while (spl[i])
	{
		if (spl[i][0] == '<' || spl[i][0] == '>')
		{
			j = 0;
			while (spl[i][j])
			{
				spl[i][j] = ' ';
				j++;
			}
		}
		i++;
	}
	return (ft_arrsplit(spl, ' '));
}
