# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 10:48:39 by msumon            #+#    #+#              #
#    Updated: 2024/06/13 13:08:17 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		=	srcs/main.c \
				srcs/map_validation.c \
				srcs/map_parser.c \
				srcs/data_init.c \
				srcs/create_textures.c \
				srcs/moves.c \
				srcs/rotations.c \
				srcs/mixed.c \
				srcs/raycasting.c \
				srcs/cleanup.c \
				srcs/additional.c \

OBJS		= $(SRCS:.c=.o)
CC			= cc
CFLAGS		= -Wall -Werror -Wextra #-g #-fsanitize=address
#MCFLAGS 	= -lmlx -framework OpenGL -framework AppKit
LXFLAGS     = -I -L -lmlx -lXext -lX11 -lm #don't forget to add these flags if you are using linux
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
	@$(CC) $(CFLAGS) $(OBJS) $(LXFLAGS) -Lsrcs/libft -lft_gnl -o $(NAME)
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