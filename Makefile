
NAME = cub3D
CC = gcc
Src = *.c libft/*.c getNextLine/*.c
Flags = -Wall -Wextra -Werror
Search = -I /usr/local/include
FindLib = -L /usr/local/lib/ -lmlx
FrameWroks = -framework OpenGl -framework AppKit
SegfaultSani = -fsanitize=address -g
m = wallRendered


all: $(NAME)

$(NAME):
	@$(CC) $(Src) $(Search) $(FindLib) $(FrameWroks) $(SegfaultSani)
fclean:
	@rm -rf $(NAME)
re: fclean all
run: re
	@./a.out


push:
	@git add .
	@git commit -m "$(m)"
	@git push origin master