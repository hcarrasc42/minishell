# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 12:26:59 by hcarrasc          #+#    #+#              #
#    Updated: 2023/06/21 11:34:21 by ruramire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	minishell
SRC 		= 	minishell.c						\
				src/array.c 					\
				src/error.c 					\
				src/ft_read.c 					\
				src/malloc.c 					\
				src/signals.c 					\
				src/built_ins/builtins.c 		\
				src/built_ins/cd.c 				\
				src/built_ins/echo.c 			\
				src/built_ins/env.c 			\
				src/built_ins/exit.c 			\
				src/built_ins/export.c 			\
				src/built_ins/export_is.c 		\
				src/built_ins/pwd.c 			\
				src/built_ins/unset.c 			\
				src/built_ins/util_env.c 		\
				src/built_ins/util_env_expand.c	\
				src/built_ins/path.c 			\
				src/command/command.c 			\
				src/command/add.c 				\
				src/command/exec_child.c 		\
				src/command/exec.c 				\
				src/command/table.c 			\
				src/redirection/redirection.c	\
				src/redirection/apply.c 		\
				src/str/str.c 					\
				src/str/is.c 					\
				src/str/skip.c 					\
				src/token/token.c 				\
				src/token/expand.c 				\
				src/token/free.c 				\
				src/token/type.c 				\
				src/token/validate.c 			\

CC 			= 	gcc
BREW_DIR 	= 	/Users/${USER}/.brew/opt
#BREW_DIR 	= 	/usr/local/opt
INCLUDES	= 	-I lib -I libft -I${BREW_DIR}/readline/include
CFLAGS 		= 	-Wall -Werror -Wextra $(INCLUDES)
OBJECTS		= 	$(SRC:.c=.o)
LDFLAGS 	+= 	-L/Users/$(USER)/.brew/opt/readline/lib #-L/opt/homebrew/opt/readline/lib
CPPFLAGS 	+= 	-I/Users/$(USER)/.brew/opt/readline/include #-I/opt/homebrew/opt/readline/include

.SILENT:

src/%.o: src/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $^

$(NAME): $(OBJECTS)
	@make bonus -C libft
	@$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) $(OBJECTS) libft/libft.a -lreadline -L${BREW_DIR}/readline/lib -o $(NAME)
	@echo "Minishell compilado: ./minishell"

all: $(NAME)

clean:
	@echo "Archivos borrados"
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)
	@rm -rf minishell
	@rm -rf libft.a

re: fclean all

norminette: @norminette $(SRC)

.PHONY: all clean fclean re norminette
