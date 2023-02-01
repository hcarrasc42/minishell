/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:40:05 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/01 15:32:19 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.h"

void	minishell(t_split *s, t_data *d)
{
	ft_exit(s);
	add_history(s->read);
	ft_split(s, s->read);
	ft_print_msh(s->tmp);
	ft_valid_file(d, s);
	ft_file(s, d);
}

void	ft_readline(t_split *s, t_data *d)
{
	while (1)
	{
		s->read = readline("minishell$> ");
		ft_error(s);
		minishell(s, d);
	}
}

int	main(void)
{
	t_split	split;
	t_data	data;

	ft_readline(&split, &data);
	return (0);
}
