/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:20:56 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/17 14:16:09 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

int	ft_cmd_len(t_split *s, int i)
{
	int	len;
	int	j;

	if (s->tmp[i] != '')
	while (t->tmp[i])
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
	return (printf("pipe_len: %d\n", len + 1), len + 1);
}

void	ft_split_pipe(t_data *d, t_split *s)
{
	char	***spl;
	int		k;
	int		i;
	int		j;

	d->val = 0;
	k = 0;
	i = 0;
	j = 0;
	spl = (char ***)malloc(sizeof(char **) * (ft_pipe_len(s) + 1));
	while (s->tmp[i])
	{
		if (ft_strncmp(s->tmp[i], "|", 1))
			k++;
		spl = (char **)malloc(sizeof(char *) * (ft_cmd_len(s, i)));
	}
	spl[k] = NULL;
}

/* while (s->tmp[i])
	{
		j = 0;
		if (s->tmp[i][j] == '|')
		spl[k] = (char **)malloc(sizeof(char *) * (ft_cmd_len(s, i) + 1));
		while (j < ft_cmd_len(s, i))
		{
			spl[k][j] = ft_strdup(s->tmp[i]);
			j++;
			i++;
		}
		printf("i: %d\n", i);
		spl[k][j] = NULL;
		k++;
	}
	spl[k] = NULL;
	k = 0;
	j = 0;
	while (spl[k])
	{
		while (spl[k][j])
		{
			printf("spl(%d): %s\n", k, spl[k][j]);
			j++;
		}
		k++;
	} */