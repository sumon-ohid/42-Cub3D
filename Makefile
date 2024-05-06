# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 10:48:39 by msumon            #+#    #+#              #
#    Updated: 2024/05/06 11:35:24 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= srcs/main.c
OBJS		= $(SRCS:.c=.o)
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
MCFLAGS 	= -lmlx -framework OpenGL -framework AppKit
#LXFLAGS     = -I -L -lmlx -lXext -lX11 #don't forget to add these flags if you are using linux
NAME		= cub3D

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MCFLAGS) -o $(NAME)
	@echo ${GREEN}======== cub3D Compiled! ========

clean:	
	@rm -f $(OBJS)
	@echo ======== Cleaned! ========
		
fclean: clean
	@rm -f $(NAME)
	@echo ======== Super Cleaned! ========
	
re: fclean all

.PHONY: all clean fclean re