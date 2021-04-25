#include "header.h"

void	ft_init(t_struct *g)
{
	int	a;

	g->move_player.radius = 3;
	g->move_player.turnDirection = 0;
	g->move_player.walkDirection = 0;
	g->move_player.walkside = 0;
	g->move_player.rotationAngle = 180 * (M_PI / 180.0);
	g->move_player.moveSpeed = 20.0;
	g->move_player.rotationSpeed = 20 * (M_PI / 180.0);
	g->map_conf.startMP = 0;
	g->map_conf.indx = 0;
	g->img.mlx_ptr = mlx_init();
	g->img.win_ptr = mlx_new_window(g->img.mlx_ptr,
			g->map_conf.width, g->map_conf.height, "AMOXE");
	g->img.img = mlx_new_image(g->img.mlx_ptr, g->map_conf.width, g->map_conf.height);
	g->img.addr = (int *)mlx_get_data_addr(g->img.img, &a, &a, &a);
}

void	fill_map(t_struct *g)
{
	int	i;

	i = 0;
	g->map_conf.world = ft_split(g->map_conf.wlrd, '\n');
	g->map_conf.map = my_malloc((g->map_conf.numHeight + 3)
			* sizeof(char *));
	while (i < g->map_conf.numHeight + 2)
	{
		g->map_conf.map[i] = my_malloc((g->g_tmp_width + 3) * sizeof(char));
		g->map_conf.map[i][g->g_tmp_width + 2] = '\0';
		i++;
	}
	g->map_conf.map[i] = NULL;
	fil_space(g->map_conf.map, g);
	fil_themp(g->map_conf.map, g->map_conf.world, g);
	lookError(g);
	if (g->map_conf.player > 1)
		ft_error("Multiple Players in Maps");
	if (g->map_conf.player == 0)
		ft_error("No Players in Maps");
}

void	fil_space(char **map, t_struct *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->map_conf.numHeight + 2)
	{
		j = 0;
		while (j < g->g_tmp_width + 2)
		{
			map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	fil_themp(char **map, char **wrld, t_struct *g)
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
			map[y][h] = g->map_conf.world[i][j];
			if (ft_strchr("NSEW", g->map_conf.map[i][j]))
			{
				init_pl(i, j, g);
				g->map_conf.map[i][j] = '0';
			}
			else if (ft_strchr("2", g->map_conf.map[i][j]))
				g->map_conf.spNumber++;
			h++;
		}
		y++;
	}
}

void	draw_player(t_struct *g)
{
	int	color;

	color = 0x662E9B;
	circle(g);
}
