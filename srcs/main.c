/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:40:05 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/03/02 14:30:06 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.h"

void	ft_void(t_split *s)
{
	if (!ft_find_char(s->read, 0))
		exit(1);
}

void	minishell(t_split *s, t_data *d, t_pipex *p, char **env)
{
	ft_struct_init(s, d, p);
	ft_split(d, s, s->read);
	ft_split_pipe(s, p);
	ft_genereal(p, env);
	ft_free(s, p);
}

void	ft_readline(t_split *s, t_data *d, t_pipex *p, char **env)
{
	while (1)
	{
		s->read = readline("minishell$> ");
		ft_exit(s);
		add_history(s->read);
		if (ft_find_char(s->read, 0))
		{
			ft_space_pipe(s);
			ft_error(s);
			minishell(s, d, p, env);
		}
		else
			free(s->read);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	t_split	split;
	t_pipex	pipex;

	argc = 0;
	argv = 0;
	ft_readline(&split, &data, &pipex, env);
	return (0);
}
