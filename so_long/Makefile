NAME := so_long

SRCS = so_long.c

CC = cc

MLX = MLX42/libmlx42.a -lglfw -L /opt/homebrew/Cellar/glfw/3.3.8/lib/

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $(MLX) $^

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : clean all
