/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:20:56 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/03/02 14:29:55 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

void	ft_print_split_pipe(char ***spl)
{
	int	k;
	int	j;

	k = 0;
	while (spl[k])
	{
		j = 0;
		while (spl[k][j])
		{
			printf("spl(%d): %s\n", k, spl[k][j]);
			j++;
		}
		k++;
	}
}

int	ft_cmd_len(t_split *s, int i)
{
	int	len;

	len = 0;
	if (ft_strncmp(s->tmp[i], "|", 1))
		i++;
	while (s->tmp[i] && !ft_strncmp(s->tmp[i], "|", 1))
	{
		i++;
		len++;
	}
	return (len);
}

int	ft_pipe_len(t_split *s)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s->tmp[i])
	{
		if (ft_strncmp(s->tmp[i], "|", 1))
			len++;
		i++;
	}
	return (len + 1);
}

void	ft_split_pipe(t_split *s, t_pipex *p)
{
	int		k;
	int		i;
	int		j;
	int		len;

	k = 0;
	i = 0;
	len = 0;
	p->spl = (char ***)malloc(sizeof(char **) * (ft_pipe_len(s) + 1));
	p->spl[ft_pipe_len(s)] = NULL;
	while (s->tmp[i])
	{
		j = 0;
		if (ft_strncmp(s->tmp[i], "|", 1) && i++)
			k++;
		len = ft_cmd_len(s, i);
		p->spl[k] = (char **)malloc(sizeof(char *) * (len + 1));
		p->spl[k][len] = NULL;
		while (len-- > 0)
		{
			p->spl[k][j] = ft_strdup(s->tmp[i]);
			j++;
			i++;
		}
	}
}
