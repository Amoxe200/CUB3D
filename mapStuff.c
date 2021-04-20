#include "header.h"

void	ft_init(void)
{
	int	a;

	move_player.radius = 3;
	move_player.turnDirection = 0;
	move_player.walkDirection = 0;
	move_player.walkside = 0;
	move_player.rotationAngle = 180 * (M_PI / 180.0);
	move_player.moveSpeed = 20.0;
	move_player.rotationSpeed = 20 * (M_PI / 180.0);
	map_conf.startMP = 0;
	map_conf.indx = 0;
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr,
			map_conf.width, map_conf.height, "AMOXE");
	img.img = mlx_new_image(img.mlx_ptr, map_conf.width, map_conf.height);
	img.addr = (int *)mlx_get_data_addr(img.img, &a, &a, &a);
}

void	fill_map(void)
{
	int	i;

	i = 0;
	map_conf.world = ft_split(map_conf.wlrd, '\n');
	map_conf.map = my_malloc((map_conf.numHeight + 3) * sizeof(char *));
	while (i < map_conf.numHeight + 2)
	{
		map_conf.map[i] = my_malloc((g_tmp_width + 3) * sizeof(char));
		map_conf.map[i][g_tmp_width + 2] = '\0';
		i++;
	}
	map_conf.map[i] = NULL;
	fil_space(map_conf.map);
	fil_themp(map_conf.map, map_conf.world);
	lookError();
	if (map_conf.player > 1)
		ft_error("Multiple Players in Maps");
	if (map_conf.player == 0)
		ft_error("No Players in Maps");
}

void	fil_space(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_conf.numHeight + 2)
	{
		j = 0;
		while (j < g_tmp_width + 2)
		{
			map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	fil_themp(char **map, char **wrld)
{
	int	i;
	int	j;
	int	y;
	int	h;

	i = -1;
	y = 0;
	while (wrld[++i])
	{
		j = -1;
		h = 0;
		while (wrld[i][++j])
		{
			map[y][h] = map_conf.world[i][j];
			if (ft_strchr("NSEW", map_conf.map[i][j]))
			{
				init_pl(i, j);
				map_conf.map[i][j] = '0';
			}
			else if (ft_strchr("2", map_conf.map[i][j]))
				map_conf.spNumber++;
			h++;
		}
		y++;
	}
}

void	draw_player(void)
{
	int	color;

	color = 0x662E9B;
	circle();
}
