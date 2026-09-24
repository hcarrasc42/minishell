/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:30:28 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/21 11:17:50 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# define FD_IN 0
# define FD_OUT 1
# define OK	0
# define ERROR 1

unsigned char	g_exec_ret;

typedef enum e_token_type {
	TOKEN_NONE			= 0,
	TOKEN_CMD			= 1,
	TOKEN_ARG			= 2,
	TOKEN_GREAT			= 3,
	TOKEN_GREATGREAT	= 4,
	TOKEN_LESS			= 5,
	TOKEN_LESSLESS		= 6,
	TOKEN_PIPE			= 7,
	TOKEN_AMP			= 8,
}	t_token_type;

typedef struct s_token {
	t_token_type	type;
	char			*str;
	int				double_quote;
	int				single_quote;
	int				ignore;
}	t_token;

typedef enum e_builtin_type {
	BLT_NONE	= 0,
	BLT_ECHO	= 1,
	BLT_CD		= 2,
	BLT_PWD		= 3,
	BLT_EXPORT	= 4,
	BLT_UNSET	= 5,
	BLT_ENV		= 6,
	BLT_EXIT	= 7,
}	t_builtin_type;

typedef struct s_redirection {
	t_token_type	type;
	char			*file;
	int				fd;
}	t_redirection;

typedef struct s_simple_cmd {
	int				argc;
	char			**argv;
	char			**argv_quoted;
	t_builtin_type	builtin_type;
	int				fd_in;
	int				fd_out;
	int				fd_error;
	t_list			*redirections;
	pid_t			pid;
	int				pipe_fds[2];
}	t_simple_cmd;

typedef struct s_cmd {
	int		ncmds;
	t_list	*cmds;
	int		background;
}	t_cmd;

typedef struct s_prompt {
	char	*user;
	char	*prompt;
	char	*pwd;
}	t_prompt;

typedef struct s_mini {
	t_prompt		prompt;
	char			*readline;
	char			**envp;
}	t_mini;

typedef struct s_exp {
	char	*start;
	char	*end;
	char	*name;
	char	*value;
	char	*final;
	char	*aux;
	int		i;
	int		index_dollar;
}	t_exp;

char			*ft_read(t_mini *state);
int				free_prompt(t_prompt *prompt);
void			free_array(char **array);
void			display_array(char **array);
void			free_array(char **array);
int				count_str_in_array(char **array);
char			**add_str_to_array(char **array, char *str);
char			**duplicate_array(char **array);
char			**del_str_from_array(char **array, char *str);
int				run_builtin_cd(t_simple_cmd	*cmd, t_mini *state);
int				run_builtin_echo(t_simple_cmd	*cmd);
int				run_builtin_env(t_mini *state);
int				run_builtin_exit(t_simple_cmd	*cmd, t_mini *state);
int				is_valid_export(char *variables);
int				run_builtin_export(t_simple_cmd	*cmd, t_mini *state);
int				run_builtin_pwd(t_mini *state);
int				run_builtin_unset(t_simple_cmd	*cmd, t_mini *state);
t_builtin_type	get_builtin_type(char *str);
int				is_parent_builtin(t_builtin_type type);
int				run_builtin(t_list *cmds, t_mini *state);
t_list			*add_cmd(t_list *tokens, t_cmd *table);
void			child_pipe(t_list *cmds, t_mini *state);
void			exec_cmd(t_list *cmds, t_mini *state);
void			free_cmd_table(t_cmd *table);
t_cmd			*tokens_to_cmd_table(t_list *tokens);
void			exec_cmd_table(t_cmd *table, t_mini *state);
t_simple_cmd	*get_cmd(t_list *cmd_node);
int				is_builtin(t_simple_cmd *cmd);
char			*expand_env_str(char *str, t_mini *state);
char			*get_env(char **envp, char *key);
char			*get_env_dup(char **envp, char *key);
char			**set_env(char **envp, char *key, char *value);
int				exit_with_error(t_mini *state, char *message_error);
int				exit_with_memory_error(t_mini *state);
int				exit_without_error(t_mini *state);
int				exit_with_error_code(t_mini *state, int exit_code);
char			*ft_strcpy_until(char *str, char until);
char			*ft_strcpy_until_quoted(char *str);
void			*ft_malloc(int size);
char			*path_to_absolute(char *cmd, t_mini *state);
char			*get_last_part_in_path(char *str);
void			apply_redirections(t_list	*redirections, t_mini *state);
t_redirection	*get_redirection(t_list *redirection_node);
void			free_redirections(t_list *redirections);
void			setup_parent_signals(void);
void			setup_sigquit_signal(void);
int				initvar(t_mini *state, char **envp);
int				is_space(char c);
int				is_quote(char c);
int				is_arg_breaking_char(char c);
char			*skip_token_str(char *str, t_token_type type);
char			*skip_enclosed_str(char *str);
char			*join_and_free(char *s1, char *s2);
char			*extract_str(char *str);
char			*ft_str_tolower(char *str);
void			expand_token_strings(t_list *tokens, t_mini *state);
void			free_tokens(t_list *tokens);
void			sanitize_token_strings(t_list *tokens);
t_token_type	get_token_type(char *str);
int				is_token_redirection(t_token_type type);
char			*token_type_to_str(t_token_type type);
int				validate_syntax_tokens(t_list *tokens);
t_list			*prompt_to_tokens(char *str);
t_token			*get_token(t_list *token_node);

#endif
