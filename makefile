# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 12:26:59 by hcarrasc          #+#    #+#              #
#    Updated: 2023/01/25 10:21:56 by hcarrasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell
DIR_OBJS		=	objs/
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g#3 -fsanitize=address

SRCS			=	srcs/main.c								\
					srcs/utils/ft_split.c					\
					srcs/utils/ft_split_utils.c				\

OBJS			=	$(SRCS:.c=.o)
PREFIXED	=	$(addprefix $(DIR_OBJS), $(OBJS))

$(DIR_OBJS)%.o : %.c
	@mkdir -p $(DIR_OBJS)/srcs
	@mkdir -p $(DIR_OBJS)/srcs/utils
	@echo "${YELLOW}Compiling with >>${RESET} $(CC) $(CFLAGS):\t $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(PREFIXED)
	@$(CC) $(CFLAGS)  -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include -o $(NAME) $(PREFIXED)
	@echo "\n${GREEN}Mandatory part compiled!${RESET}\n"


all: $(NAME)

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
