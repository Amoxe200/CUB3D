
NAME = cub3D
CC = gcc
Src = main.c functions.c libft/*.c getNextLine/*.c
Flags = -Wall -Wextra -Werror
Search = -I /usr/local/include
FindLib = -L /usr/local/lib/ -lmlx
FrameWroks = -framework OpenGl -framework AppKit
SegfaultSani = -fsanitize=address -g


all: $(NAME)

$(NAME):
	@$(CC) $(Src) $(Search) $(FindLib) $(FrameWroks) $(SegfaultSani)
fclean:
	@rm -rf $(NAME)
re: fclean all
run: re
	@./a.out
