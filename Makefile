# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 10:48:39 by msumon            #+#    #+#              #
#    Updated: 2024/05/08 20:31:03 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		=	main.c \
				srcs/cub3d/map_validation.c

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
	@printf "$(BLUE)> Compiling... ["
	@for i in $(shell seq 0 10 100); do \
        printf "▓"; \
        sleep 0.1; \
    done
	@printf "] 100%%$(RESET)\n"
endef

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: libft_gnl $(NAME)

libft_gnl:
	@make -C srcs/libft

$(NAME): $(OBJS)
	@$(PRINT_LOADING)
	@$(CC) $(CFLAGS) $(OBJS) $(MCFLAGS) -Lsrcs/libft -lft_gnl -o $(NAME)
	@echo "$(GREEN)> Compilation Complete! ✅✅✅$(RESET)"

clean:	
	@make -C srcs/libft clean
	@rm -f $(OBJS)
	@echo "$(YELLOW)> Cleaned! 🗑️$(RESET)"
        
fclean: clean
	@make -C srcs/libft fclean
	@rm -f $(NAME)
	@echo "$(YELLOW)> Super Cleaned! 🗑️$(RESET)"
    
re: fclean libft_gnl all

.PHONY: libft_gnl all clean fclean re loading