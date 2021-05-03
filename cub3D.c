/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:39:55 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/30 16:56:35 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	keys(void *g)
{
	static int	check = 0;
	t_struct	*tmp;

	tmp = g;
	render(g);
	if (tmp->argv && check == 1)
		ft_check_save(tmp->argv, tmp);
	check++;
	return (1);
}

void	parse_file(char **file_path, t_struct *g, int argc)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(*file_path, O_RDONLY);
	if (fd < 0)
		ft_error("Error\n Check You file");
	g->map_conf.counter = 0;
	check_thefile(file_path, argc);
	read_line(line, fd, g);
}

void	check_thefile(char **file, int argc)
{
	int	index;

	if (argc > 3 || argc < 2)
		ft_error("Error\n on arguments");
	index = ft_strlen(*file);
	if (file[0][index - 1] != 'b' || file[0][index - 2]
			!= 'u' || file[0][index - 3] != 'c')
		ft_error("Error\n Check the file extension");
}

void	read_line(char *line, int fd, t_struct *g)
{
	int	i;
	int	ret;

	i = 0;
	while (1)
	{
		ret = get_next_line(fd, &line, g);
		i = 0;
		if (g->map_conf.counter == 8
			&& g->map_conf.startMP == 1 && line[0] == '\0')
			ft_error("Error");
		store_data(line, i, g);
		if (ret == 0)
			break ;
	}
	if (line != NULL && line[0] != '\0')
	{
		i = 0;
		store_data(line, i, g);
	}
	else
		ft_error("Error\n map should be the last in the file");
	if (g->map_conf.result != 2480)
		ft_error("Error\n Duplicate or missing params");
	free(line);
}

int	main(int argc, char **argv)
{
	int			a;
	t_struct	g;

	(void)argc;
	setbuf(stdout, NULL);
	g.memory = NULL;
	g.argv = argv[2];
	g.map_conf.wlrd = "";
	init_all(&g);
	parse_file(&argv[1], &g, argc);
	fill_map(&g);
	ft_init(&g);
	g.img.img = mlx_new_image(g.img.mlx_ptr,
			g.map_conf.width, g.map_conf.height);
	g.img.addr = (int *)mlx_get_data_addr(g.img.img, &a, &a, &a);
	mlx_loop_hook(g.img.mlx_ptr, keys, (void *)(&g));
	mlx_hook(g.img.win_ptr, 2, 1L << 0, onClickListner, (void *)(&g));
	mlx_hook(g.img.win_ptr, 3, 1L << 1, reset_player, (void *)(&g));
	mlx_hook(g.img.win_ptr, 17, 0L, destroy, (void *)(&g));
	mlx_loop(g.img.mlx_ptr);
	return (0);
}
