/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:40:05 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/30 12:05:34 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.h"

void	minishell(t_split *s)
{
	add_history(s->read);
	ft_split(s, s->read);
	ft_pipex(s);
	ft_print_msh(s->tmp);
}

void	ft_readline(t_split *s)
{
	while (1)
	{
		s->read = readline("minishell$> ");
		ft_exit(s);
		minishell(s);
	}
}

int	main(void)
{
	t_split	split;

	ft_readline(&split);
	return (0);
}
