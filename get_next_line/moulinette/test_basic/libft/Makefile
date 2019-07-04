# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anorman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 16:00:27 by anorman           #+#    #+#              #
#    Updated: 2019/06/21 12:05:34 by anorman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = libft.a
FILES = ft_lstaddend.c ft_memmove.c ft_strdel.c ft_strnstr.c\
	ft_lstcat.c ft_memset.c ft_strdup.c ft_strrchr.c\
	ft_lstdel.c ft_putchar.c ft_strequ.c\
	ft_lstdelmid.c ft_putchar_fd.c ft_striter.c ft_strsplit.c\
	ft_lstdelone.c ft_putendl.c ft_striteri.c ft_strstr.c\
	ft_atoi.c ft_lstiter.c ft_putendl_fd.c ft_strjoin.c ft_strsub.c\
	ft_bzero.c ft_lstmap.c ft_putnbr.c ft_strlcat.c ft_strtrim.c\
	ft_isalnum.c ft_lstnew.c ft_putnbr_fd.c ft_strlen.c ft_tolower.c\
	ft_isalpha.c ft_lstprint.c ft_putstr.c ft_strmap.c ft_toupper.c\
	ft_isascii.c ft_memalloc.c ft_putstr_fd.c ft_strmapi.c\
	ft_isdigit.c ft_memccpy.c ft_strcat.c ft_strncat.c\
	ft_isprint.c ft_memchr.c ft_strchr.c ft_strncmp.c\
	ft_itoa.c ft_memcmp.c ft_strclr.c ft_strncpy.c\
	ft_memcpy.c ft_strcmp.c ft_strnequ.c\
	ft_lstadd.c ft_memdel.c ft_strcpy.c ft_strnew.c\

OBJ = $(FILES:%.c=%.o)

SRCDIR = srcs

HEADER = -I includes

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) -I includes $(FILES:%=$(SRCDIR)/%)
	@echo "gcc -c $(FLAGS) -I includes FILES"
	@ar -rcs $(NAME) $(OBJ)
	@echo "ar -rcs $(NAME) OBJ"

clean:
	@rm -f $(OBJ)
	@echo "rm -f OBJ"

fclean: clean
	@rm -f $(NAME)
	@echo "rm -f $(NAME)"

re: fclean all
