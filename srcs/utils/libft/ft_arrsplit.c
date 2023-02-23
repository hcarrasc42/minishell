/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:23:08 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/23 13:33:16 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

char	**ft_arrsplit(char **spl, char c)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (ft_arrlen(spl) + 1));
	while (spl[i])
	{
		if (spl[i][0] == c)
			i++;
		tmp[i] = ft_strdup(spl[i]);
		i++;
	}
	return (tmp);
}
