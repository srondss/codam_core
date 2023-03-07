NAME := push_swap

SRCS =	push_swap.c \
	push_swap_mandatory_functions.c \
	push_swap_mandatory_functions_2.c \
	push_swap_mandatory_functions_3.c \
	push_swap_misc.c \
	push_swap_algorithm.c \
	push_swap_parsing.c \
	push_swap_quicksort.c \
	push_swap_mandatory_helpers.c \
	push_swap_quicksort_helpers.c \
	push_swap_sort_three_a_helpers.c \
	push_swap_sort_three_b_helpers.c \
	push_swap_quicksort_helpers_2.c \

OBJS = $(SRCS:.c=.o)

CFLAGS ?= -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	@cd ./libft && make
	$(CC) $(CFLAGS) -o $@ $^ libft/libft.a

clean :
	@cd ./libft && make clean
	rm -rf $(OBJS)

fclean :
	@cd ./libft && make fclean
	rm -rf $(OBJS) $(NAME)

re :	clean all

.PHONY: re fclean all
