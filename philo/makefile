# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 19:34:49 by gpinchuk          #+#    #+#              #
#    Updated: 2022/08/10 14:36:54 by gpinchuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = src
OBJ = obj
CC = gcc
CFLAGS = -Werror -Wextra -Wall -pthread -fsanitize=thread
SRC_F = $(wildcard $(SRC)/*.c)


GREEN = \033[0;92m
YELLOW = \033[0;93m
DEF_COLOR = \033[0;39m

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRC_F) -o $@
	@echo "$(GREEN)philosophers compiled!$(DEF_COLOR)"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(YELLOW)Evrything was cleaned $(DEF_COLOR)"
re: fclean all