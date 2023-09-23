# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 10:02:31 by ysrondy           #+#    #+#              #
#    Updated: 2023/09/23 18:51:52 by ysrondy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3d

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address,undefined

#Directories
LIBFT_DIR = ./lib/libft
MLX_DIR = ./lib/MLX42
OBJ_DIR = obj

#Lib
LIB_LIBFT = $(LIBFT_DIR)/libft.a
LIB_MLX = $(MLX_DIR)/build/libmlx42.a

#MLX
MLX_FLAGS_LINKING = -ldl -lglfw -pthread -lm -L"/opt/homebrew/opt/glfw/lib"

#Includes
HEADERS := -I ./include -I $(LIBFT_DIR) -I ./include -I $(MLX_DIR)/include

#Sources
SRCS = src/main.c src/get_next_line.c src/get_next_line_utils.c

#Objects
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all : $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf "All object files are in obj directories.\n"

$(NAME): $(LIB_LIBFT) $(LIB_MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(HEADERS) $(LIB_LIBFT) $(LIB_MLX) $(MLX_FLAGS_LINKING) $(OBJS)  -o $(NAME)
	@printf "Compiled ./cub3d executable succesfully.\n"

$(LIB_LIBFT):
	@make -sC $(LIBFT_DIR)
	@printf "Compiled libft succesfully.\n"

$(LIB_MLX):
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4
	@printf "Compiled libmlx succesfully.\n"

clean :
	@printf "Cleaning...\n"
	@rm -rf $(OBJ_DIR)
	@make clean -sC $(LIBFT_DIR)
	@rm -rf $(MLX_DIR)/build
	@printf "Removed .o files succesfully\n"

fclean : clean
	@make fclean -sC $(LIBFT_DIR)
	@rm -rf $(NAME)
	@printf "Removed ./cub3d executable succesfully\n"

re : fclean all

.PHONY: all clean fclean re
