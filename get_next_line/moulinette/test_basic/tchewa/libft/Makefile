# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchewa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 09:51:34 by tchewa            #+#    #+#              #
#    Updated: 2019/07/09 16:13:29 by tchewa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
ARC = ar rc
SRC = ft_memset.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strcpy.c \
	  ft_strjoin.c \
	  ft_strlen.c \
	  ft_strnew.c \
	  ft_strsub.c \
	  ft_bzero.c \


OBJ = *.o

# all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) -c $(SRC)
		$(ARC) $(NAME) $(OBJ)
		ranlib $(NAME)

all: $(NAME)

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all
