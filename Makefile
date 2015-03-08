# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/02 11:46:50 by ccervant          #+#    #+#              #
#    Updated: 2015/02/27 18:13:05 by ccervant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVEUR			= serveur

CLIENT			= client

LIB				= libft/

SERVER_SRCS		= src_serveur/main.c \
				  src_serveur/utils.c \
				  src_serveur/cmd.c
				  

CLIENT_SRCS		= src_client/main.c \
				  src_client/utils.c \
				  src_client/cmd.c 	
				  
SERVER_OBJS		= $(SERVER_SRCS:.c=.o)
CLIENT_OBJS		= $(CLIENT_SRCS:.c=.o)

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror -I$(I)
LFLAG			= -L libft/ -lft

I				= ./includes/

all: $(SERVEUR) $(CLIENT)
	@make -C $(LIB)

$(SERVEUR): $(SERVER_OBJS)
	@echo "\033[1;33m"
	@make -C $(LIB)
	@echo "\033[1;37m"
	$(CC) $(CFLAGS) $(LFLAG) -o $(SERVEUR) $(SERVER_SRCS)

$(CLIENT): $(CLIENT_OBJS)
	@make -C $(LIB)
	$(CC) $(CFLAGS) $(LFLAG) -o $(CLIENT) $(CLIENT_SRCS)

clean:

	@make -C $(LIB) clean
	@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	@echo  "\033[1;34m"
	@echo "Clean...\033[1;32m done"


fclean:		clean

	@make -C $(LIB) fclean
	@$(RM) $(SERVEUR) $(CLIENT)
	@echo  "\033[1;34m"
	@echo "Fclean...\033[1;32m done"

re: fclean all

.PHONY : fclean clean all