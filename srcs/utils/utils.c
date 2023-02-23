/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:42:46 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/23 13:13:21 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/main.h"

int	ft_spaces(char *str, int i)
{
	if (str[i] == '\0' || str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
		return (1);
	return (0);
}

int	ft_find_char(char *str, int i)
{
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_len_split(t_split *s)
{
	int		len;
	char	**str;

	len = 0;
	str = s->tmp;
	while (str[len])
		len++;
	return (len);
}

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
	if (ft_strncmp(s->read, "exit", 4))
	{
		free(s->read);
		exit (0);
	}
}
