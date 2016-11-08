# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/24 12:41:09 by lvalenti          #+#    #+#              #
#    Updated: 2016/11/08 20:11:32 by bngo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIB_NAME = libft/libft.a
INC_DIR = includes
SRC_DIR = srcs
OBJ_DIR = obj

SRCS = $(shell find $(SRC_DIR) -type f)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.d)

IFLAGS = -I $(INC_DIR) -I libft/includes
FLAGS = -Wall -Werror -Wextra -O2 -O3

CC = gcc -g $(FLAGS)
LIBFLAGS = -L libft -lft -lmlx -framework OpenGL -framework AppKit
RM = /bin/rm -f

all: $(LIB_NAME) $(NAME)

$(LIB_NAME) :
		make -C libft re

$(NAME) : $(OBJS)
		echo "Make Objects :\033[1;32m DONE !\033[m"
			$(CC) -o $@ $^ $(LIBFLAGS)
				echo "Make $(NAME) :\033[1;32m DONE !\033[m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		mkdir -p $(OBJ_DIR)
		$(CC) -MMD $(IFLAGS) -o $@ -c $<

$(OBJ_DIR)/%.d: $(SRC_DIR)/%.c

clean:
		$(RM) $(OBJS)
			make -C libft clean
				echo "Make clean :\033[1;31m DONE !\033[m"

fclean : clean
		$(RM) -rf $(OBJ_DIR)
		$(RM) $(NAME)
			make -C libft fclean
				echo "Make fclean :\033[1;31m DONE !\033[m"

re: fclean all

.PHONY: all clean fclean re
