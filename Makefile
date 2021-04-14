
NAME = cub3D
CC = gcc
Src = *.c libft/*.c getNextLine/*.c
Flags = -Wall -Wextra -Werror -O3
Search = -I /usr/local/include
FindLib = -L /usr/local/lib/ -lmlx
FrameWroks = -framework OpenGl -framework AppKit
m =parsingSeemsToWorkFine


all: $(NAME)

$(NAME):
	@$(CC) $(Src) $(Search) $(FindLib) $(FrameWroks)
fclean:
	@rm -rf $(NAME)
re: fclean all
run: re
	@./a.out


push:
	@git add .
	@git commit -m "$(m)"
	@git push origin master