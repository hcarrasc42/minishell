/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:54:54 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/03/01 14:32:09 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.h"

void	ft_free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
}

void	ft_free_split(t_split *s)
{
	int	i;

	i = 0;
	if (s->str)
		free(s->str);
}

void	ft_free_data(t_data *d)
{
	if (d->infile)
		free(d->infile);
	if (d->out)
		free(d->outfile);
}

void	ft_free_pipex(t_pipex *p)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	i = 0;
	if (p->fd)
	{
		while (i < p->len)
		{
			free(p->fd[i]);
			i++;
		}
		free(p->fd);
	}
	i = 0;
	if (p->spl)
	{
		while (i < p->len + 1)
		{
			j = 0;
			while (p->spl[i][j])
			{
				printf("puto calvo\n");
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
