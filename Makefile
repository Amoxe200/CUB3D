
NAME = cub3D
CC = gcc
Src = *.c libft/*.c getNextLine/*.c
Flags = -Wall -Wextra -Werror -g
Search = -I /usr/local/include
FindLib = -L /usr/local/lib/ -lmlx
FrameWroks = -framework OpenGl -framework AppKit
m =	spritenormed



all: $(NAME)

$(NAME):
	@$(CC) $(Src) $(Flags) $(Search) $(FindLib) $(FrameWroks) -o $(NAME)
fclean:
	@rm -rf $(NAME)
re: fclean all

push:
	@git add .
	@git commit -m "$(m)"
	@git push origin master