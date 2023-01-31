/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:14:41 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/30 13:31:39 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

int	ft_strncmp(char *str, char *cmp, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] != cmp[i])
			return (0);
		i++;
	}
	return (1);
}
