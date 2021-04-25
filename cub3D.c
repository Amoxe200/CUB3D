#include "header.h"

int	keys(void *g)
{
	render(g);
	return (1);
}

void	parse_file(char **file_path, t_struct *g)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(*file_path, O_RDONLY);
	if (fd < 0)
		ft_error("Error\n Check You file");
	g->map_conf.counter = 0;
	check_thefile(file_path);
	read_line(line, fd, g);
}

void	check_thefile(char **file)
{
	int	index;

	index = ft_strlen(*file);
	if (file[0][index - 1] != 'b' || file[0][index - 2]
			!= 'u' || file[0][index - 3] != 'c')
		ft_error("Error\n Check the file extension");
}

void	read_line(char *line, int fd, t_struct *g)
{
	int	i;

	i = 0;
	while (get_next_line(fd, &line) != 0)
	{
		i = 0;
		if (g->map_conf.counter == 8 && g->map_conf.startMP == 1 && line[0] == '\0')
			ft_error("Error");
		store_data(line, i, g);
		free(line);
	}
	if (line != NULL && line[0] != '\0')
	{
		i = 0;
		store_data(line, i, g);
	}
	else
		ft_error("Error\n map should be the last in the file");
		printf("result = %d\n", g->map_conf.result);
	if (g->map_conf.result != 2480)
		ft_error("Error\n Duplicate or missing params");
	free(line);
}
void	init_all(t_struct *g)
{
	g->map_conf.player = 0;
	g->map_conf.result = 0;
	g->map_conf.res = 0;
	g->map_conf.no = 0;
	g->map_conf.so = 0;
	g->map_conf.we = 0;
	g->map_conf.ea = 0;
	g->map_conf.s = 0;
	g->map_conf.f = 0;
	g->map_conf.c = 0;
}

int	main(int argc, char **argv)
{
	int	a;
	t_struct g;

	(void)argc;
	setbuf(stdout, NULL);
	memory = NULL;
	g.map_conf.wlrd = "";
	init_all(&g);
	parse_file(&argv[1], &g);
	fill_map(&g);
	ft_init(&g);
	g.img.img = mlx_new_image(g.img.mlx_ptr, g.map_conf.width, g.map_conf.height);
	g.img.addr = (int *)mlx_get_data_addr(g.img.img, &a, &a, &a);
	render(&g);
	mlx_loop_hook(g.img.mlx_ptr, keys, (void *)(&g));
	mlx_hook(g.img.win_ptr, 2, 1L << 0, onClickListner, (void *)(&g));
	mlx_hook(g.img.win_ptr, 3, 1L << 1, reset_player, (void *)(&g));
	mlx_hook(g.img.win_ptr, 17, 0L, destroy, (void *)(&g));
	mlx_loop(g.img.mlx_ptr);
	return (0);
}
