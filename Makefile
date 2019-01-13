all:
	gcc -Wall -Wextra -Werror *.c -c
	ar rcs libftprintf.a *.o libft/*.o

test: fclean
	gcc -Wall -Wextra *.c -L./libft -lft -o test -g

clean:
	rm -f *.o

fclean: clean
	rm -f test
	rm -f libftprintf.a

re: fclean all
