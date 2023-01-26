/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:30:18 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/26 11:00:49 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "struct.h"

// Srcs/Utils/utils.c
void			ft_exit(t_split *s);
void			ft_print_msh(char **str);

// Srcs/Utils/Split/ft_split.c
char			**ft_split(t_split *s, char *str);

// Srcs/Utils/Split/ft_split_utils.c
int				ft_jump_spaces(char *str, int i);
char			*ft_comillas(char *tmp, t_split *s);
char			*ft_no_comillas(char *tmp, t_split *s);

#endif