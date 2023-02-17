/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:40:05 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/17 13:56:20 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.h"

void	minishell(t_split *s, t_data *d, char **env)
{
	env = 0;
	ft_exit(s);
	ft_split(d, s, s->read);
	ft_split_pipe(d, s);
	//ft_ejecutar_pro(s, env);
	//ft_print_msh(s->tmp);
}

void	ft_readline(t_split *s, t_data *d, char **env)
{
	while (1)
	{
		s->read = readline("minishell$> ");
		add_history(s->read);
		ft_read_pipe(s);
		ft_error(s);
		minishell(s, d, env);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_split	split;
	t_data	data;

	argc = 0;
	argv = 0;
	ft_readline(&split, &data, env);
	return (0);
}
