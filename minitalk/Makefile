CLIENT = client
SERVER = server
LIBFTPRINTF = libftprintf.a

SRC_C = client.c minitalk_utils_client.c 
SRC_S = server.c minitalk_utils_server.c

CC = cc
CFLAGS ?= -Wall -Wextra -Werror

OBJS_C = $(SRC_C:.c=.o)
OBJS_S = $(SRC_S:.c=.o)

all : $(LIBFTPRINTF) $(CLIENT) $(SERVER)

$(LIBFTPRINTF):
	@printf "Compiling ft_printf.\n"
	@cd ./final_printf/ && make
	@cd ./final_printf/ && cp libftprintf.a ..
	@printf "Copied libftprintf.a into minitalk folder.\n"

$(SERVER): $(OBJS_S) $(OBJS_C)
	@printf "Compiling server.\n"
	$(CC) $(CFLAGS) -o $(SERVER) $(O_C) $(LIBFTPRINTF)
	@printf "Sever Executable Ready.\n"

$(CLIENT): $(OBJS_S) $(OBJS_C)
	@printf "Compiling client.\n"
	$(CC) $(CFLAGS) -o $(CLIENT) $(O_S) $(LIBFTPRINTF)
	@printf "Client Executable Ready.\n"

clean :
	@rm -rf $(OBJS_C) $(OBJS_S) $(LIBFTPRINTF)
	cd ./final_printf && make clean
	@printf "Removed .o files for client, server and utils.\n"

fclean : clean
	@rm -rf $(CLIENT) $(SERVER)
	cd ./final_printf && make fclean
	@printf "Removed client & server executables.\n"

re : fclean all

.PHONY: all clean fclean re
