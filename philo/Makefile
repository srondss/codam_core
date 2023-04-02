NAME = philo

SRCS = philo.c \
	utils.c \
	philo_creation.c \
	philo_init_structs.c

OBJS = $(SRCS:.c=.o)

CFLAGS ?= -g -pthread -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@printf "Compiled ./philo executable succesfully.\n"

clean :
	@rm -rf $(OBJS)
	@printf "Removed .o files successfully.\n"

fclean : clean
	@rm -rf $(NAME)
	@printf "Removed ./philo executable successfully.\n"

re : fclean all

.PHONY: all clean fclean re
