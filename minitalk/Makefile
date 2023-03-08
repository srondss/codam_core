CLIENT = client
SERVER = server

SRC_C = client.c
SRC_S = server.c

CC = cc
CFLAGS ?= -Wall -Wextra -Werror

OBJS_C = $(SRC_C:.c=.o)
OBJS_S = $(SRC_S:.c=.o)

all : $(CLIENT) $(SERVER)

$(SERVER): $(OBJS_C) $(OBJS_S)
	@$(CC) $(CFLAGS) -o $(SERVER) $(SRC_S)
	@printf "Sever Executable Ready.\n"

$(CLIENT): $(OBJS_C) $(OBJS_S)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(SRC_C)
	@printf "Client Executable Ready.\n"

clean :
	@rm -rf $(OBJS_C) $(OBJS_S)
	@printf "Removed client.o & server.o files.\n"

fclean : clean
	@rm -rf $(CLIENT) $(SERVER)
	@printf "Removed client & server executables.\n"

re : fclean all

.PHONY: all clean fclean re
