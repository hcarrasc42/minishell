/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:40:05 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/23 14:57:18 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.h"

int	main(void)
{
	t_input	input;

	while (1)
	{
		input.read = readline("minishell$> ");
		break ;
	}
	return (0);
}
