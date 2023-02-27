/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:30:18 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/27 10:19:27 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "struct.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1

					// FILE //
// Srcs/Utils/file
void			ft_init_file(t_data *d);
int				ft_is_space_char(char c);
int				ft_file(t_data *d, t_split *s);
int				ft_len_file(t_split *s, char c);

					// LIBFT //
char			*ft_strdup(char *s1);
int				ft_strlen(char *str);
int				ft_arrlen(char **str);
char			**ft_strremover(char **spl);
char			**ft_arrsplit(char **spl, char c);
int				ft_strncmp(char *str, char *cmp, int len);

					// PIPEX //
// Srcs/Utils/Pipex/ft_pipex.c
int				ft_triplen(char	***spl);
void			ft_print_exit(char *str);
char			*ft_cmd_finder(char **cmd);
int				str_ichr(char *str, char c);
char			*get_path(char *cmd, char **env);
char			**str_split(char *str, char sep);
char			*str_ndup(char *str, unsigned int n);
char			*ft_file_finder(char ***spl, int nb);
int				ft_msh_pipex(t_pipex *p, char **env);
int				ft_pipex(t_split *s, char ***spl, char **env);

					// SPLIT //
// Srcs/Utils/Split/ft_split.c
int				ft_len(char *str);
void			ft_init_split(t_split *s);
int				ft_lens(char *str, t_split *s);
char			**ft_split(t_data *d, t_split *s, char *str);
void			ft_split_pipe(t_data *d, t_split *s, t_pipex *p);
char			*ft_split_core(t_data *d, t_split *s, char *tmp, char *str);

// Srcs/Utils/Split/ft_split_utils.c
int				ft_spaces(char *str, int i);
int				ft_jump_spaces(char *str, int i);
void			ft_len_while(t_split *s, char *str, int n);
char			*ft_no_comillas(t_data *d, t_split *s, char *str);
char			*ft_comillas(t_data *d, t_split *s, char *str, int n);
void			ft_genereal(t_pipex *p, char **env);

					// UTILS //
// Srcs/Utils/utils.c
void			ft_exit(t_split *s);
void			ft_print_msh(char **str);
int				ft_len_split(t_split *s);
int				ft_spaces(char *str, int i);

void			ft_error(t_split *s);
int				ft_find_char(char *str, int i);
int				ft_strncmp1(const char *s1, const char *s2, size_t n);
void			ft_space_pipe(t_split *s);

#endif