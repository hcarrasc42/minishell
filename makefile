# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 12:26:59 by hcarrasc          #+#    #+#              #
#    Updated: 2023/03/02 14:26:53 by hcarrasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell
DIR_OBJS		=	objs/
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g3 -fsanitize=address

SRCS			=	srcs/main.c											\
					srcs/ft_error.c										\
					srcs/ft_free.c										\
					srcs/ft_struct_init.c								\
					srcs/utils/utils.c									\
					srcs/utils/file/ft_file.c							\
					srcs/utils/file/ft_file_utils.c						\
					srcs/utils/libft/ft_arrlen.c						\
					srcs/utils/libft/ft_strlen.c						\
					srcs/utils/libft/ft_strdup.c						\
					srcs/utils/libft/ft_strncmp.c						\
					srcs/utils/libft/ft_arrsplit.c						\
					srcs/utils/libft/ft_strremove.c						\
					srcs/utils/pipex/ft_get_path.c						\
					srcs/utils/split/ft_split.c							\
					srcs/utils/split/ft_split_pipe.c					\
					srcs/utils/split/ft_space_pipe.c					\
					srcs/utils/split/ft_split_utils.c					\
					srcs/utils/pipex/ft_msh_pipex.c						\
					srcs/utils/pipex/ft_pipex_utils.c					\
					srcs/utils/pipex/ft_pipex_utils2.c					\

OBJS			=	$(SRCS:.c=.o)
PREFIXED	=	$(addprefix $(DIR_OBJS), $(OBJS))

$(DIR_OBJS)%.o : %.c
	@mkdir -p $(DIR_OBJS)/srcs
	@mkdir -p $(DIR_OBJS)/srcs/utils
	@mkdir -p $(DIR_OBJS)/srcs/utils/file
	@mkdir -p $(DIR_OBJS)/srcs/utils/libft
	@mkdir -p $(DIR_OBJS)/srcs/utils/pipex
	@mkdir -p $(DIR_OBJS)/srcs/utils/split
	@echo "${YELLOW}Compiling with >>${RESET} $(CC) $(CFLAGS):\t $<"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(PREFIXED)
	@$(CC) $(CFLAGS)  -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include -o $(NAME) $(PREFIXED)
	@echo "\n${GREEN}Mandatory part compiled!${RESET}\n"

clean:
	@rm -rf $(OBJS) $(DIR_OBJS)
	@echo "\n${BLUE}Cleaned!${RESET}\n"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re print

GREEN			=	"\\x1b[32m"
RED				=	"\\x1b[31m"
YELLOW			=	"\\x1b[33m"
BLUE			=	"\\x1b[34m"
RESET			=	"\\x1b[37m"
ORANGE			=	"\\x1b[38m"
