/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:40:05 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/25 10:19:27 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.h"

int	main(void)
{
	t_input	input;
	char	**tmp;

	while (1)
	{
		input.read = readline("minishell$> ");
		tmp = ft_split_init(input.read);
		printf("split1:%s\n", tmp[0]);
		printf("split2:%s\n", tmp[1]);
		printf("split3:%s\n", tmp[2]);
		break ;
	}
	return (0);
}
