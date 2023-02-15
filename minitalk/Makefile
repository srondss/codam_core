NAME =
CLIENT = client
SERVER = server

SRC_C = client.c
SRC_S = server.c

CC = cc
FLAGS = -Wall -Wextra -Werror

all : $(CLIENT) $(SERVER)

$(NAME): all

$(SERVER):
	@ $(CC) -o $(SERVER) $(FLAGS) $(SRC_S)
	@printf "Sever Ready.\n"

$(CLIENT):
	@ $(CC) -o $(CLIENT) $(FLAGS) $(SRC_C)
	@printf "Client Ready.\n"

clean :
	rm -rf $(CLIENT) $(SERVER)
	@printf "Removed Client & Server.\n"

fclean : 
	rm -rf $(CLIENT) $(SERVER)
	@printf "Removed Client & Server.\n"

re : fclean all

.PHONY: all clean fclean re
