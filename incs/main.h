/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:30:18 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/25 10:25:37 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
//# include <readline/history.h>
# include "struct.h"

// Utils
char	**ft_split_init(char *str);

// Split Utils
int	ft_jump_spaces(char *str, int i);
char	*ft_no_comillas(char *tmp, char *str, t_split *s);
char	*ft_comillas(char *tmp, char *str, t_split *s);

#endif