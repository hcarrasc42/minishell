/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:23:08 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/24 09:32:54 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

int	ft_arrlen_spc(char **spl)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (spl[i])
	{
		if (spl[i][0] == ' ')
			i++;
		i++;
		len++;
	}
	return (printf("arrlen: %d\n", len), len);
}

char	**ft_arrsplit(char **spl, char c)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = (char **)malloc(sizeof(char *) * (ft_arrlen(spl)));
	while (spl[i])
	{
		if (spl[i][0] == c)
			i++;
		if (!spl[i])
			break ;
		tmp[j] = ft_strdup(spl[i]);
		i++;
		j++;
	}
	tmp[j] = NULL;
	printf("tm1: %s\n", tmp[0]);
	printf("tm2: %s\n", tmp[1]);
	return (tmp);
}
