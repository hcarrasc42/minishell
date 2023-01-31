/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:42:46 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/31 14:39:45 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/main.h"

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

void	ft_valid_file(t_data *d, t_split *s)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	d->val = 0;
	str = s->tmp;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '<' || str[i][j] == '>')
				d->val += 1;
			j++;
		}
		i++;
	}
}
