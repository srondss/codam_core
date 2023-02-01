NAME := so_long

SRCS = so_long.c so_long_parse_map.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

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
