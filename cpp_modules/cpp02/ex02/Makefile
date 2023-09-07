# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 10:56:37 by ysrondy           #+#    #+#              #
#    Updated: 2023/08/06 14:15:03 by ysrondy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILE = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

FILES = main.cpp Fixed.cpp

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
