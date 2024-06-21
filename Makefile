# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 10:48:39 by msumon            #+#    #+#              #
#    Updated: 2024/06/21 15:16:53 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		=	srcs/main.c \
				srcs/map_validation.c srcs/map_validation1.c \
				srcs/map_validation2.c \
				srcs/map_parser.c srcs/map_parser1.c srcs/map_parser2.c \
				srcs/map_parser3.c \
				srcs/data_init.c srcs/data_init1.c \
				srcs/create_textures.c \
				srcs/moves.c \
				srcs/update_moves.c \
				srcs/rotations.c \
				srcs/mixed.c \
				srcs/raycasting.c \
				srcs/cleanup.c srcs/cleanup1.c\
				srcs/lib/ft_atoi.c \
				srcs/lib/ft_bzero.c \
				srcs/lib/ft_strlen.c \
				srcs/lib/ft_strlcpy.c \
				srcs/lib/ft_strnstr.c \
				srcs/lib/ft_calloc.c \
				srcs/lib/ft_strdup.c \
				srcs/lib/ft_putchar_fd.c \
				srcs/lib/ft_putstr_fd.c \
				srcs/lib/ft_substr.c \
				srcs/lib/ft_strjoin.c \
				srcs/lib/ft_strlcat.c \
				srcs/lib/ft_strncmp.c \
				srcs/lib/ft_split.c \
				srcs/lib/get_next_line.c \

OBJS		= $(SRCS:.c=.o)
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
LXFLAGS     = -I -L -lmlx -lXext -lX11 -lm
NAME		= cub3D
HEADER		= cub3d.h

GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
RESET = \033[0m

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LXFLAGS) -o $(NAME)
	@echo "$(GREEN)> Compilation Complete! ✅✅✅$(RESET)"

clean:	
	@rm -f $(OBJS)
	@echo "$(YELLOW)> Cleaned! 🗑️$(RESET)"
        
fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)> Super Cleaned! 🗑️$(RESET)"
    
re: fclean  all

.PHONY: all clean fclean re