/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:30:18 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/01 17:17:58 by hcarrasc         ###   ########.fr       */
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

# define IN 0
# define OUT 1

// Srcs/ft_file.c
int				ft_file(t_split *s, t_data *d);
void			ft_file_0(t_data *d, char *s1);
void			ft_init_file(t_data *d);
int				ft_len_file(t_split *s);

// Srcs/Utils/utils.c
void			ft_exit(t_split *s);
void			ft_print_msh(char **str);
int				ft_len_split(t_split *s);

// Srcs/Utils/Split/ft_split.c
int				ft_len(char *str);
void			ft_init_split(t_split *s);
int				ft_len_spa(char *str, t_split *s);
char			**ft_split(t_split *s, char *str);
char			*ft_split_core(t_split *s, char *tmp, char *str);

// Srcs/Utils/Split/ft_split_utils.c
int				ft_spaces(char *str, int i);
int				ft_jump_spaces(char *str, int i);
void			ft_len_while(t_split *s, char *str, int n);
char			*ft_no_comillas(t_split *s, char *tmp, char *str);
char			*ft_comillas(t_split *s, char *tmp, char *str, int n);

// Srcs/Utils/Pipex/ft_pipex.c
void			ft_pipex(t_split *s);

// Srcs/Utils/libft
int				ft_strncmp(char *str, char *cmp, int len);
int				ft_strlen(char *str);

void			ft_error(t_split *s);
void			ft_valid_file(t_data *d, t_split *s);

#endif