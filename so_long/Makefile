NAME := so_long

SRCS = so_long.c so_long_find_path.c so_long_map_to_string.c so_long_parse_map.c so_long_assets.c so_long_check_2d_map.c so_long_end_game.c so_long_error.c so_long_hooks.c so_long_movement.c printf/ft_printf.c printf/ft_printf_hex.c printf/ft_printf_ints.c printf/ft_printf_misc.c printf/ft_printf_ptr.c printf/ft_printf_str.c c_libft/ft_split.c c_libft/ft_strlen.c c_libft/ft_substr.c c_libft/ft_itoa.c c_libft/ft_strdup.c 

CC = cc
CMAKE = cmake

MLX = MLX42/build/libmlx42.a -Iinclude -lglfw -L "/Users/ysrondy/.brew/opt/glfw/lib/"

FLAGS = -Wall -Wextra -Werror -g

SANITIZE = -fsanitize=address

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@cd ./MLX42/build && make
	$(CC) $(FLAGS) -o $@ $(MLX) $^

clean :
	@printf "Cleaning...\n"
	@rm -rf $(OBJS)
	@printf "Cleaned All Files\n"

fclean : clean
	rm -rf $(NAME)

re : clean all
