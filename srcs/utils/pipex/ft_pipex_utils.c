/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:56:40 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/22 11:06:41 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

char	*ft_file_strdup(char *s1)
{
	char	*tmp;
	int		i;
	int		j;

	i = 1;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1)));
	while (s1[i])
	{
		tmp[j] = s1[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_file_finder(char ***spl, int nb)
{
	char	c[2];
	int		j;
	int		k;

	c[0] = '<';
	c[1] = '>';
	k = 0;
	while (spl[k])
	{
		j = 0;
		while (spl[k][j])
		{
			if (spl[k][j][0] == c[nb])
				return (ft_file_strdup(spl[k][j]));
			j++;
		}
		k++;
	}
	return (0);
}
