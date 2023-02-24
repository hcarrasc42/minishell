/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:14:35 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/24 12:02:33 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

int	ft_arrlen(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (printf("arrlen: %d\n", len), len);
}
