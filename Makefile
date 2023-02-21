# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 05:16:13 by acanelas          #+#    #+#              #
#    Updated: 2023/02/21 06:09:50 by acanelas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror  
ARCH = ar rcs
REMOVE = rm -f

SERVER = server
CLIENT = client

SERVER_SRC = server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SERVER_BONUS_SRC = server_bonus.c
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)

CLIENT_BONUS_SRC = client_bonus.c
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)


all: $(SERVER) $(CLIENT)

	$(MAKE) -C ./libft
$(SERVER): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o server
$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o client

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

	$(MAKE) -C ./libft
$(SERVER_BONUS): $(SERVER_BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) $(LIBFT) -o server_bonus
$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) $(LIBFT) -o client_bonus

clean:
	$(MAKE) clean -C ./libft
	$(REMOVE) $(SERVER_OBJ) $(CLIENT_OBJ)
	$(REMOVE) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)
fclean: clean
	$(MAKE) fclean -C ./libft
	$(REMOVE) $(SERVER) $(CLIENT)
	$(REMOVE) $(SERVER_BONUS) $(CLIENT_BONUS)
	
re: fclean all

.PHONY: all clean fclean re