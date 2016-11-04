# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bngo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/21 15:14:34 by bngo              #+#    #+#              #
#    Updated: 2016/11/04 14:17:32 by bngo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol 

SRC_NAMES =	main.c \
			draw.c \
			event.c

OBJ_NAMES = $(SRC_NAMES:.c=.o)
	INC_NAMES = libft.h
	LIB_NAMES = libft.a

SRC_PATH = ./src
OBJ_PATH = ./obj
INC_PATH = ./include ./libft ./minilibx
LIB_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAMES))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAMES))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(LIB_PATH)$(LIB_NAMES)

################################################################################

FLAGS = -Wall -Wextra -Werror
LDLIBS = -lft
COM = gcc
MLXLIB = -lm -lmlx -framework OpenGl -framework AppKit

################################################################################

all: $(LIB) $(NAME)

$(NAME): $(MINILIBX) $(LIB) $(OBJ)
	@make -C libft
	$(COM) $^ -o $@ -L $(LIB_PATH) $(MLXLIB) -lft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(COM) $(FLAGS) $(INC) -o $@ -c $<

$(LIB):
	@make -C $(LIB_PATH)

clean:
	@make clean -C libft
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@rmdir $(OBJ_PATH) obj 2> /dev/null || echo  > /dev/null
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: clean fclean all

.PHONY: all clean fclean re
