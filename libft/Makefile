# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bngo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 14:39:24 by bngo              #+#    #+#              #
#    Updated: 2016/10/22 18:14:59 by bngo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_NAME = ft_atoi.c \
		   ft_isalpha.c \
		   ft_isdigit.c \
		   ft_isalnum.c \
		   ft_isascii.c \
		   ft_isprint.c \
		   ft_toupper.c \
		   ft_tolower.c \
		   ft_strlen.c \
		   ft_strdup.c \
		   ft_strcpy.c \
		   ft_strncpy.c \
		   ft_strcat.c \
		   ft_strncat.c \
		   ft_strlcat.c \
		   ft_strchr.c \
		   ft_strrchr.c \
		   ft_strstr.c \
		   ft_strnstr.c \
		   ft_strcmp.c \
		   ft_strncmp.c \
		   ft_memset.c \
		   ft_bzero.c \
		   ft_memcpy.c \
		   ft_memccpy.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_putchar.c \
		   ft_putstr.c \
		   ft_strclr.c \
		   ft_putnbr.c \
		   ft_strnew.c \
		   ft_strdel.c \
		   ft_putendl.c \
		   ft_putchar_fd.c \
		   ft_putstr_fd.c \
		   ft_putendl_fd.c \
		   ft_putnbr_fd.c \
		   ft_strmap.c \
		   ft_strmapi.c \
		   ft_striter.c \
		   ft_striteri.c \
		   ft_strequ.c \
		   ft_strnequ.c \
		   ft_strjoin.c \
		   ft_strsub.c \
		   ft_memalloc.c \
		   ft_memdel.c \
		   ft_memmove.c \
		   ft_itoa.c \
		   ft_strtrim.c \
		   ft_strjoin.c \
		   ft_strsplit.c \
		   ft_lstnew.c \
		   ft_lstdelone.c \
		   ft_lstdel.c \
		   ft_lstadd.c \
		   ft_lstiter.c \
		   ft_lstmap.c \
		   get_next_line.c

OBJ_NAME = $(SRC_NAME:.c=.o)

all:$(NAME)

$(NAME):
	@echo "Conversion des sources en objet"
	@gcc -c $(SRC_NAME)
	@echo "Link des objets"
	@ar rc $(NAME) $(OBJ_NAME)
	@echo "Indexation de la librairie"
	@ranlib $(NAME)

clean:
	@echo "Supression des objets"
	@rm -rf $(OBJ_NAME)

fclean: clean
	@echo "Supression du fichier de sortie"
	@rm -rf $(NAME)

re: fclean all
