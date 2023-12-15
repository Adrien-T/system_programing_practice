
SRC =	network/socket/create_socket.c	\
		network/socket/create_connection_socket.c	\
		network/socket/destroy_socket.c	\
		network/buffer/create_buff.c	\
		network/buffer/destroy_buffer.c	\
		network/read/read_socket.c	\
		network/write/write_on_socket.c	\
		network/connections/create_connection.c	\
		network/connections/change_status.c	\
		network/connections/close_connection.c	\
		network/connections/handle_connection_ends.c	\
		tcp/select/set_select_timeout.c	\
		tcp/select/add_fd_to_select.c	\
		tcp/select/fill_select_data_with_connections.c	\
		tcp/select/get_select_num.c	\
		tcp/select/setup_select_data.c	\
		tcp/accept/accept_connection.c	\
		tcp/server/server_duties.c	\
		tcp/socket/socket_server_setup.c	\
		main.c


$(eval SRC = $(addprefix src/, $(SRC)))

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -I./include/

NAME	=	my_tcp_server

$(NAME):	$(OBJ)
	@printf "\033[1;36m Compiling\n"
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

clean:
	@printf "\033[1;31m Cleanning\n"
	@rm -f $(OBJ)
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

fclean: clean
	@printf "\033[1;31m Cleanning binaries\n"
	@rm -f $(NAME)
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

re:	fclean	all
	@printf "\033[1;32m REBULDING DONE\n"
	@printf "\033[00m"
