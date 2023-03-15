CLIENT = client
SERVER = server

SRC_C = client.c minitalk_utils_client.c
SRC_S = server.c minitalk_utils_server.c

CC = cc
CFLAGS ?= -Wall -Wextra -Werror

OBJS_C = $(SRC_C:.c=.o)
OBJS_S = $(SRC_S:.c=.o)
OBJS_U = $(SRC_U:.c=.o)

all : $(CLIENT) $(SERVER)

$(SERVER): $(OBJS_C) $(OBJS_S) 
	$(CC) $(CFLAGS) -o $(SERVER) $(SRC_S)
	@printf "Sever Executable Ready.\n"

$(CLIENT): $(OBJS_C) $(OBJS_S) 
	$(CC) $(CFLAGS) -o $(CLIENT) $(SRC_C)
	@printf "Client Executable Ready.\n"

clean :
	@rm -rf $(OBJS_C) $(OBJS_S)
	@printf "Removed .o files for client, server and utils.\n"

fclean : clean
	@rm -rf $(CLIENT) $(SERVER) 
	@printf "Removed client & server executables.\n"

re : fclean all

.PHONY: all clean fclean re
