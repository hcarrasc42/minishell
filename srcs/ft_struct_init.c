/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:14:10 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/28 12:18:19 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.h"

void	ft_data_init(t_data *d)
{
	d->input = 0;
	d->output = 0;
	d->val = 0;
	d->in = 0;
	d->out = 0;
	d->outfile = 0;
	d->infile = 0;
}

void	ft_split_init(t_split *s)
{
	s->i = 0;
	s->j = 0;
	s->k = 0;
	s->y = 0;
	s->com = 0;
	s->len = 0;
	s->ft_len = ft_len(s->read);
	s->tmp = (char **)malloc(sizeof(char *) * (s->ft_len + 1));
}

void	ft_pipex_init(t_pipex *p)
{
	p->pid = 0;
	p->len = 0;
	p->fd = 0;
	p->fdin = 0;
	p->fdout = 0;
	p->infi = 0;
	p->outfi = 0;
	p->cmd = 0;
	p->spl = 0;
}

void	ft_struct_init(t_split *s, t_data *d, t_pipex *p)
{
	ft_data_init(d);
	ft_split_init(s);
	ft_pipex_init(p);
}
