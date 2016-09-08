# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchicote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 21:18:25 by cchicote          #+#    #+#              #
#    Updated: 2016/02/26 21:20:23 by cchicote         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INCLUDES = -I./libft/ -I./minilibx/

CFLAGS = -Wall -Werror -Wextra $(INCLUDES) #-Werror

MLXOSX = -lmlx -framework OpenGL -framework AppKit

LXLIBMLX = -L ./minilibxLinux/ -lmlx

MLXLINUX = -L/usr/X11/lib -lXext -lX11 -lm

LIBFT = -L ./libft/ -lft

PATH_SRC = src/

SRC = main.c \
		read_file.c \
		draw_grid.c \
		trace.c \
		oct_1_2.c \
		oct_3_4.c \
		oct_5_6.c \
		oct_7_8.c \
		keycode.c \
		keycode_2.c \
		input_color.c \

SRCO = $(patsubst %.c, %.o,$(addprefix $(PATH_SRC), $(SRC)))

all: osx

libft:
	@make -C libft

minilibx_linux:
	@make -C minilibxLinux/

gcc: libft minilibx_linux $(SRCO)
	@clang $(CFLAGS) -o $(NAME) $(SRCO) $(LIBFT) $(LXLIBMLX) $(MLXLINUX) -lm
	@echo "\033[32;40mCOMPILATION : OK\033[0;0m"

osx: libft $(SRCO)
	@gcc $(CFLAGS) -o $(NAME) $(SRCO) $(LIBFT) $(MLXOSX)
	@echo "\033[32;40m\ncompilation OK\n\033[0;0m"

.PHONY: clean fclean minilibx_linux libft

clean:
	@make -C libft/ clean
	@/bin/rm -f $(SRCO)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all
