# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 17:43:26 by pmiceli           #+#    #+#              #
#    Updated: 2018/04/25 21:38:42 by pmiceli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

## color ##
RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
MAG = \033[35m
CYA = \033[36m
EOC = \033[37m

## sources ##
SRCDIR = ./srcs/
SRCNAMES  = draw/draw_image.c \
			\
			init/data_init.c \
			init/img_init.c \
			init/t_mlx_init.c \
			\
			vec/get_normal.c \
			vec/intersect.c \
			vec/shadow_ray.c \
			vec/vec_operations.c \
			vec/vec_operations2.c \
			\
			exit_all.c \
			main.c
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))

## Includes ##
INC = ./includes/
INCS = ./includes/rtv1.h
LIB_INCS = ./lib/libft/includes/get_next_line.h ./lib/libft/includes/libft.h\
		   ./lib/Mlx_macOS/includes/mlx.h

## OBJECTS ##
OBJS_DIR = ./objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCNAMES:.c=.o))

## LIB DIR ##
LIBFT_DIR = ./lib/libft/
MLX_DIR = ./lib/Mlx_macOS/
LIBMYSDL_DIR = ./lib/libmysdl/
LIBPT_DIR = ./lib/libpt/
SDL2_DIR = ./lib/SDL2-2.0.8/

## FLAGS ##
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit
LFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLX_FLAGS) -L$(LIBPT_DIR) -lpt -L$(HOME)/LIBS/SDL2/lib -lSDL2

PRINT = "make[1]: Nothing to be done for 'all'"

all: print_libft LIBFT print_mlx MLX print_libpt PT print_sdl SDL2 print_libmysdl MYSDL print_name $(NAME) print_done

change_cflag:
	$(eval CFLAGS = -fsanitize=address)

MODE_DEBUG: change_cflag all

print_name:
	@echo "\033[033m➼	\033[033mCompiling $(NAME) ... with flag : \033[36m$(CFLAGS)\033[0m"
	@echo "\033[033m➼	\033[033mCreating $(NAME)'s objetcs\033[0m"

print_libft:
	@echo "\033[033m➼	\033[033mCompiling Libft ...\033[0m"

print_libmysdl:
	@echo "\033[033m➼	\033[033mCompiling Libmysdl ...\033[0m"

print_libpt:
	@echo "\033[033m➼	\033[033mCompiling Libpt ...\033[0m"

print_mlx:
	@echo "\033[033m➼	\033[033mCompiling Mlx_macOS ...\033[0m"

print_sdl:
	@echo "\033[033m➼	\033[033mCompiling SDL ...\033[0m"

print_done:
	@echo $(PRINT)
	@echo "\n ========================================\n"

$(NAME): $(OBJS) LIBFT MLX
	@echo "\033[033m➼	\033[033mCreating $(NAME)'s executable\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)
	@$(eval PRINT ="\033[032m✓	\033[032mDONE !\033[0m")

$(OBJS): $(OBJS_DIR)%.o:$(SRCDIR)%.c $(INCS) $(LIB_INCS)
	@echo "\033[038;2;255;153;0m⧖	Creating 	$@\033[0m"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

LIBFT:
	@make -C $(LIBFT_DIR)

MLX:
	@make -C $(MLX_DIR)

MYSDL:
	@make -C $(LIBMYSDL_DIR)

PT:
	@make -C$(LIBPT_DIR)

SDL2:
ifeq ("$(wildcard $(HOME)/LIBS/SDL2/lib/libSDL2.dylib)","")
	@mkdir -p ~/LIBS/SDL2
	@cd $(SDL2_DIR) && ./configure --prefix=$(HOME)/LIBS/SDL2
	@make -C $(SDL2_DIR)
	@make -C $(SDL2_DIR) install
else
	@echo "make[1]: Nothing to be done for 'all'."
endif

rm_obj:
	@rm -rf $(OBJS_DIR)
	@echo "❌	\033[031mRemouve $(NAME)'s objects\033[0m"

clean: rm_obj
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBPT_DIR) clean
	@make -C $(MLX_DIR) clean
	@make -C $(LIBMYSDL_DIR) clean

fclean: rm_obj
	@rm -rf $(NAME)
	@echo "❌	\033[031mRemouve $(NAME)'s executable\033[0m"
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LIBPT_DIR) fclean
	@make -C $(MLX_DIR) fclean
	@make -C $(LIBMYSDL_DIR) fclean

re: fclean all

re_MODE_DEBUG: fclean MODE_DEBUG

ret : clean test

.PHONY: all fclean clean re MLX LIBFT print_name print_mlx print_done print_libft fclean MODE_DEBUG change_cflag rm_obj print_libmysdl print_libpt PT MYSDL
