# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 10:48:39 by msumon            #+#    #+#              #
#    Updated: 2024/09/10 14:14:51 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		=	srcs/main.c \
				srcs/map_validation.c \
				srcs/map_validation_extra.c \
				srcs/map_border_check.c \
				srcs/map_parser.c \
				srcs/map_validation_empty.c \
				srcs/map_validation_space.c \
				srcs/color_parser.c \
				srcs/only_map.c \
				srcs/texture_parser.c \
				srcs/data_init.c \
				srcs/map_init.c \
				srcs/create_textures.c \
				srcs/moves.c \
				srcs/update_moves.c \
				srcs/rotations.c \
				srcs/set_env.c \
				srcs/raycasting.c \
				srcs/draw_lines.c \
				srcs/cleanup.c \
				srcs/close_game.c \
				srcs/lib/ft_atoi.c \
				srcs/lib/ft_isdigit.c \
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
CFLAGS		= -Wall -Werror -Wextra -g
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