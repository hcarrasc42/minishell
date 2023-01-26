/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:40:05 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/26 11:00:58 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.h"

void	ft_readline(t_split *s)
{
	while (1)
	{
		s->read = readline("minishell$> ");
		ft_exit(s);
		add_history(s->read);
		ft_print_msh(ft_split(s, s->read));
	}
}

int	main(void)
{
	t_split	split;

	ft_readline(&split);
	return (0);
}
