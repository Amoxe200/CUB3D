#include "header.h"

int	keys(void)
{
	render();
	mlx_hook(img.win_ptr, 2, 1L << 0, onClickListner, &img);
	mlx_hook(img.win_ptr, 3, 0, reset_player, (void *)0);
	return (1);
}

void	parse_file(char **file_path)
{
	int		fd;
	char	*line;

	fd = open(*file_path, O_RDONLY);
	if (fd < 0)
		ft_error("Error\n Check You file");
	map_conf.counter = 0;
	check_thefile(file_path);
	read_line(line, fd);
}

void	check_thefile(char **file)
{
	int	index;

	index = ft_strlen(*file);
	if (file[0][index - 1] != 'b' || file[0][index - 2]
			!= 'u' || file[0][index - 3] != 'c')
		ft_error("Error\n Check the file extension");
}

void	read_line(char *line, int fd)
{
	int	i;

	i = 0;
	while (get_next_line(fd, &line) != 0)
	{
		i = 0;
		if (map_conf.counter == 8 && map_conf.startMP == 1 && line[0] == '\0')
			ft_error("Error");
		store_data(line, i);
		free(line);
	}
	if (line != NULL && line[0] != '\0')
	{
		i = 0;
		store_data(line, i);
	}
	else
		ft_error("Error\n map should be the last in the file");
	if (map_conf.result != 2480)
		ft_error("Error\n Duplicate or missing params");
	free(line);
}

int	main(int argc, char **argv)
{
	int	a;

	memory = NULL;
	map_conf.wlrd = "";
	parse_file(&argv[1]);
	fill_map();
	ft_init();
	img.img = mlx_new_image(img.mlx_ptr, map_conf.width, map_conf.height);
	img.addr = (int *)mlx_get_data_addr(img.img, &a, &a, &a);
	mlx_loop_hook(img.mlx_ptr, keys, (void *)0);
	mlx_loop(img.mlx_ptr);
	return (0);
}
