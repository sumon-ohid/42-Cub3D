# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 08:14:24 by msumon            #+#    #+#              #
#    Updated: 2023/11/29 08:50:54 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 			= 	ft_atoi.c ft_bzero.c ft_isalpha.c ft_isalnum.c ft_isascii.c \
					ft_isprint.c ft_isdigit.c ft_strlen.c ft_toupper.c ft_tolower.c \
					ft_memset.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
					ft_strchr.c ft_strrchr.c ft_memchr.c ft_strncmp.c ft_memcmp.c \
					ft_strnstr.c ft_calloc.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c \
					ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c

OBJS			= $(SRCS:.c=.o)

CC				= cc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
.SILENT:
