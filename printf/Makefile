CC=cc
NAME=libftprintf.a
CFLAGS=-Wall -Wextra -Werror
OPTIONS=-c -I.
SRC=ft_printf.c ../libft/*.c
OBJ=*.o

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(OPTIONS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re
