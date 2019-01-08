# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fratke <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 18:20:15 by fratke            #+#    #+#              #
#    Updated: 2018/12/21 03:27:16 by mbennis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c *.c
	ar rcs libft.a *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
