NAME = push_swap
LIBFT = libft.a

LIBFT_PATH = ./libft/
INCLUDES = push_swap.h


FILES= push_swap.c push_swap_mandatory_functions.c push_swap_mandatory_functions_2.c push_swap_mandatory_functions_3.c push_swap_misc.c push_swap_algorithm.c push_swap_parsing.c push_swap_quicksort.c push_swap_mandatory_helpers.c
OBJECTS= push_swap.o push_swap_mandatory_functions.o push_swap_mandatory_functions_2.o push_swap_mandatory_functions_3.o push_swap_misc.o push_swap_algorithm.o push_swap_parsing.o push_swap_quicksort.o push_swap_mandatory_helpers.o

CC = clang
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_PATH) $(LIBFT) 
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME) $(OBJECTS) -L $(LIBFT_PATH) -lft

$(OBJECTS): $(FILES)
	$(CC) $(CFLAGS) -g -c $(FILES)

test: $(NAME)
	cp ./tools/checker_linux .
	bash ./tools/tester.sh

visual: $(NAME)
	cp ./tools/pyviz.py .
	python3 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`

clean:
	make -C $(LIBFT_PATH) fclean
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)
	$(RM) checker_linux
	$(RM) pyviz.py

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	
re: fclean all 

.PHONY: all clean fclean re 
