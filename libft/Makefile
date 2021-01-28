# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktabit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 21:59:52 by ktabit            #+#    #+#              #
#    Updated: 2019/10/21 22:00:46 by ktabit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar
NAME = libft.a
flags = -Wall -Wextra -Werror
SRCS = ft_islower.c ft_isupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_calloc.c

all : $(NAME)
$(NAME):
	@$(CC) $(flags) -c $(SRCS)
	@$(AR) rsc $(NAME) *.o

bonus:
	@echo “Made in china”
clean: 
	@rm -rf *.o

fclean: clean
	@rm -rf *.a

re: fclean all
	@echo "Rebuilding Library."
