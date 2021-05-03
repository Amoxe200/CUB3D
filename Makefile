# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 15:40:43 by aaqari            #+#    #+#              #
#    Updated: 2021/04/30 17:29:49 by aaqari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D
CC = gcc
Src = *.c libft/*.c getNextLine/*.c
Flags = -Wall -Wextra -Werror -g
Search = -I /usr/local/include
FindLib = -L /usr/local/lib/ -lmlx
FrameWroks = -framework OpenGl -framework AppKit
m =	before pushing



all: $(NAME)

$(NAME): ${Src}
	@$(CC) $(Src) $(Flags) $(Search) $(FindLib) $(FrameWroks) -o $(NAME)
clean:
	@rm -rf $(NAME)
fclean:
	@rm -rf $(NAME)
re: fclean all

push:
	@git add .
	@git commit -m "$(m)"
	@git push origin master