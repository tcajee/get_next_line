#  ************************************************************************** */
#                                                                             */
#                                                         :::      ::::::::   */
#   Makefile                                            :+:      :+:    :+:   */
#                                                     +:+ +:+         +:+     */
#    By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
#                                                 +#+#+#+#+#+   +#+           */
#    Created: 2019/07/05 16:20:06 by lnkambul          #+#    #+#             */
#    Updated: 2019/07/06 21:07:01 by lnkambul         ###   ########.fr       */
#                                                                             */
#  ************************************************************************** */

NAME = test

PATH = /home/emptycee/Desktop/gnl_git/get_next_line/moulinette/test_basic/

SRCS = get_next_line.c main.c

INCLUDES = get_next_line.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	echo "Cleaned..."

fclean: clean
	rm -f $(NAME)
	echo "Cleaned all..."

re: fclean all
	echo "Cleaned and recomplied..."

.PHONY: all, clean, fclean, re

