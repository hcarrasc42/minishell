/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:40:05 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/24 10:27:47 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.h"

void	minishell(t_split *s, t_data *d, t_pipex *p, char **env)
{
	ft_exit(s);
	ft_split(d, s, s->read);
	//ft_print_msh(s->tmp);
	ft_split_pipe(d, s, p);
	ft_genereal(p, env);
	free(s->tmp);
	free(p->spl);
	free(s->read);
}

void	ft_readline(t_split *s, t_data *d, t_pipex *p, char **env)
{
	while (1)
	{
		s->read = readline("minishell$> ");
		add_history(s->read);
		ft_space_pipe(s);
		ft_error(s);
		minishell(s, d, p, env);
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
