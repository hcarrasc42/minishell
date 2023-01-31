/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:02:46 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/31 13:23:34 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.h"

//f->input = openfile(s->tmp[0], IN);

/* void	ft_infile(t_file *f)
{
	return ;
} */

int	ft_len_file(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '<')
		len++;
	return (len);
}

void	ft_init_file(t_data *d)
{
	d->cmd = 0;
	d->input = 0;
	d->output = 0;
	d->file = (char **)malloc(sizeof(char *) * 3);
}

void	ft_infile(t_data *d, t_split *s)
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;

	i = 0;
	j = 0;
	s1 = s->tmp[0];
	s2 = s->tmp[1];
	d->file[0] = (char *)malloc(sizeof(char) * (ft_len_file(s1) + 1));
	d->file[1] = (char *)malloc(sizeof(char) * 2);
	while (s1[i] && s1[i] != '<')
	{
		d->file[0][j] = s1[i];
		j++;
		i++;
	}
	d->file[0][j] = '\0';
	if (s1[i] == '\0')
		d->file[1][0] = s2[0];
	else
		d->file[1][0] = s1[i];
}

int	ft_file(t_split *s, t_data *d)
{
	ft_init_file(d);
	ft_infile(d, s);
	printf("infile: %s\n", d->file[0]);
	printf("sing: %s\n", d->file[1]);
	d->file[3] = 0;
	return (0);
}
