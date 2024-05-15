# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 22:14:07 by fbiberog          #+#    #+#              #
#    Updated: 2024/02/15 17:28:27 by fbiberog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

sourcefiles = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
				ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
				ft_substr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_striteri.c ft_strmapi.c  \
				ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c get_nextline1.c \
				get_nextline2.c  ft_printf.c extrafunctions.c 

objects =		$(sourcefiles:.c=.o)

NAME =			libft.a

all:			$(NAME)

$(NAME):		$(objects)
	ar rcs libft.a $(objects)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(objects)

fclean:
	rm -f $(objects) $(NAME)

re: 			fclean all