# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 10:48:39 by msumon            #+#    #+#              #
#    Updated: 2024/05/07 11:51:56 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= main.c
OBJS		= $(SRCS:.c=.o)
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
MCFLAGS 	= -lmlx -framework OpenGL -framework AppKit
#LXFLAGS     = -I -L -lmlx -lXext -lX11 #don't forget to add these flags if you are using linux
NAME		= cub3D
HEADER		= cub3d.h

GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
RESET = \033[0m

define PRINT_LOADING
	@printf "$(GREEN)Compiling... ["
	@for i in $(shell seq 0 10 100); do \
		printf "▓"; \
		sleep 0.1; \
	done
	@printf "] 100%%$(RESET)\n"
endef

%.o : %.c
	@$(PRINT_LOADING)
	@$(CC) $(CFLAGS) -c $< -o $@

libft_gnl:
	@make -C srcs/libft all

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MCFLAGS) $(./libft/libft_gnl) -o $(NAME)
	@echo "$(GREEN)======== ✅ cub3D Compiled! ✅ ========$(RESET)"

clean:	
	@make -C srcs/libft clean
	@rm -f $(OBJS)
	@echo "$(YELLOW)======== Cleaned! ========$(RESET)"
		
fclean: clean
	@make -C srcs/libft fclean
	@rm -f $(NAME)
	@echo "$(YELLOW)======== Super Cleaned! ========$(RESET)"
	
re: fclean libft_gnl all

.PHONY: libft_gnl all clean fclean re loading