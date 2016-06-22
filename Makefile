# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoulous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/17 21:56:41 by atoulous          #+#    #+#              #
#    Updated: 2016/06/22 19:19:23 by atoulous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = Sources/fils_de_fer.c Sources/fils_lines.c Sources/draw_lines.c \
		Sources/parse_fils.c

OBJ = $(SRC:.c=.o)

CF = gcc -Wall -Werror -Wextra

LIBS = -LLibs/libft/ -LLibs/minilibx_macos/

$(NAME): $(OBJ)
	@echo
	@echo "@@@@@  @@@    @@@@@"
	@echo "@      @  @   @    "
	@echo "@@@    @   @  @@@  "
	@echo "@      @  @   @    "
	@echo "@      @@@    @    "
	@echo
	@make -C Libs/libft
	@make -C Libs/minilibx_macos
	@$(CF) $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit -o $@ $^
#   @"\033[32m[OK]\033[0m"#
	@echo fdf well compiled

all: $(NAME)

%.o: %.c
	@$(CF) -o $@ -c $<

clean:
	@make clean -C Libs/libft
	@make clean -C Libs/minilibx_macos
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C Libs/libft
	@rm -f $(NAME)

re: fclean all
