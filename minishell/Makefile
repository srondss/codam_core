NAME = minishell

SRCS = main.c parsing_tokens.c parsing_commands.c utils.c

OBJS = $(SRCS:.c=.o)

CFLAGS ?= -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lreadline
	@printf "Compiled ./minishell executable succesfully.\n"

clean :
	@rm -rf $(OBJS)
	@printf "Removed .o files successfully.\n"

fclean : clean
	@rm -rf $(NAME)
	@printf "Removed ./minishell executable successfully.\n"

re : fclean all

.PHONY: all clean fclean re
