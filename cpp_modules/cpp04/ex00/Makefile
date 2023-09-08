# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 10:56:37 by ysrondy           #+#    #+#              #
#    Updated: 2023/09/08 08:42:23 by ysrondy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILE = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

FILES = main.cpp Dog.cpp Cat.cpp Animal.cpp

OFILES = $(FILES:.cpp=.o)

NAME = main

all: $(NAME)

$(NAME): $(OFILES)
	@$(COMPILE) $(OFILES) -o $@

%.o: %.cpp
	@$(COMPILE) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OFILES)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
