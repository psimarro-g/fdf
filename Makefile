# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psimarro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 18:49:00 by psimarro          #+#    #+#              #
#    Updated: 2023/04/20 13:35:57 by psimarro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   PROGRAM                                    #
# **************************************************************************** #

INC_DIR	= includes/
HEADER	= includes/fdf.h
NAME	= fdf

# **************************************************************************** #
#                                   COMPILER                                   #
# **************************************************************************** #

CC 		= gcc

CFLAGS	= -Wall -Wextra -Werror
LDFLAGS = -framework OpenGL -framework AppKit Libft/libft.a libmlx.a

RM		= rm -f

# **************************************************************************** #
#                                    PATHS                                     #
# **************************************************************************** #

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRC_DIR				=	src/
SRC =	main.c \
		color.c \
		draw_fdf.c \
		draw_line.c \
		draw.c \
		hooks.c \
		mlx.c \
		add_line.c \
		check.c \
		parse.c \
		proj.c \
		fdf_utils.c

OBJ_DIR				=	obj/
OBJ					= 	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): libft $(OBJ)
	$(CC) -o $(NAME) $(LDFLAGS) $(OBJ)
	@echo "\n\033[32mCompiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

libft:
	@$(MAKE) -C Libft

clean:
	@$(RM) -rf $(OBJ_DIR)
	@$(MAKE) -C Libft clean

fclean:				clean
	@$(RM) $(NAME)
	@$(MAKE) -C Libft fclean
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\033[37m\n"

re:			fclean all

bonus:		re

.PHONY:		all libft clean fclean re bonus
