# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psimarro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 18:49:00 by psimarro          #+#    #+#              #
#    Updated: 2023/04/03 20:46:14 by psimarro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   PROGRAM                                    #
# **************************************************************************** #
INC_DIR				=	includes/
HEADER				= 	includes/fdf.h
NAME = fdf

# **************************************************************************** #
#                                   COMPILER                                   #
# **************************************************************************** #

CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror
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

all:		$(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME):			Libft/libft.a $(OBJ) 
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) Libft/libft.a

Libft/libft.a:
	$(MAKE) -C Libft

.PHONY:		all clean fclean re bonus

clean:
	$(RM) -rf $(OBJ_DIR)
	$(MAKE) -C Libft clean

fclean:				clean
	$(RM) $(NAME)
	$(MAKE) -C Libft fclean

re:			fclean all

bonus:		re
