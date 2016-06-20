# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoulous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/17 21:56:41 by atoulous          #+#    #+#              #
#    Updated: 2016/06/20 20:55:46 by atoulous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = Sources/fils_de_fer.c Sources/fils_lines.c Sources/draw_lines.c \
		Sources/parse_fils.c

OBJ = $(SRC:.c=.o)

CF = gcc -Wall -Werror -Wextra

$(NAME): $(OBJ)
	@echo
	@echo "@@@@@  @@@    @@@@@"
	@echo "@      @  @   @    "
	@echo "@@@    @   @  @@@  "
	@echo "@      @  @   @    "
	@echo "@      @@@    @    "
	@echo
	@make -C Libs/libft
	@$(CF) -LLibs/libft/ -lft -lmlx -framework OpenGL -framework AppKit -o $@ $^
#   @"\033[32m[OK]\033[0m"#
	@echo fdf well compiled

all: $(NAME)

%.o: %.c
	@$(CF) -o $@ -c $<

clean:
	@make clean -C Libs/libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C Libs/libft
	@rm -f $(NAME)

re: fclean all
