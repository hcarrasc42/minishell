/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:54:54 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/03/02 13:26:40 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.h"

void	ft_free_double(t_pipex *p)
{
	int	i;

	i = 0;
	while (i < p->len)
	{
		free(p->fd[i]);
		i++;
	}
	free(p->fd);
}

void	ft_free_split(t_split *s)
{
	int	i;

	i = 0;
	if (s->str)
		free(s->str);
	if (s->tmp)
	{
		while (s->tmp[i])
		{
			free(s->tmp[i]);
			i++;
		}
		free(s->tmp);
	}
}

void	ft_free_pipex(t_pipex *p)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (p->fd)
		ft_free_double(p);
	if (p->spl)
	{
		while (i < p->len + 1)
		{
			j = 0;
			while (p->spl[i][j])
			{
				free(p->spl[i][j]);
				j++;
			}
			free(p->spl[i]);
			i++;
		}
		free(p->spl);
	}
}

void	ft_free(t_split *s, t_data *d, t_pipex *p)
{
	ft_free_split(s);
	ft_free_pipex(p);
}
