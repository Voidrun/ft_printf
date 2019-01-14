NAME = libftprintf.a

all: $(NAME)

$(NAME):
	make -C libft re
	gcc -Wall -Wextra -Werror *.c -c
	ar rcs libftprintf.a *.o libft/*.o

test: fclean
	make -C libft
	gcc -Wall -Wextra *.c -L./libft -lft -o test -g

clean:
	make -C libft clean
	rm -f *.o

fclean: clean
	rm -f test
	rm -f libftprintf.a
	rm -f libft/libft.a

re: fclean all
