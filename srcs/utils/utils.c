/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:42:46 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/26 10:48:07 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/main.h"

void	ft_print_msh(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("msh: %s\n", str[i]);
		i++;
	}
}

void	ft_exit(t_split *s)
{
	if (!strncmp(s->read, "exit", 4))
	{
		free(s->tmp);
		free(s->read);
		exit (0);
	}
	else
		return ;
}
