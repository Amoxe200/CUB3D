#include "header.h"

void	catchThem(int j, int i, t_struct *g)
{
	if (ft_strchr("NSWE", g->map_conf.map[j][i]))
		g->map_conf.player++;
	if (j == 0 || j == g->map_conf.numHeight)
	{
		if (g->map_conf.map[j][i] != '1' && g->map_conf.map[j][i] != ' ')
			ft_error("Error In map");
	}
	else if (g->map_conf.map[j][i] == '0' || g->map_conf.map[j][i] == '2'
			|| g->map_conf.map[j][i] == 'S' || g->map_conf.map[j][i] == 'N'
			|| g->map_conf.map[j][i] == 'W' || g->map_conf.map[j][i] == 'E')
	{
		if (g->map_conf.map[j - 1][i] == ' '
			|| g->map_conf.map[j][i + 1] == ' '
			|| g->map_conf.map[j + 1][i] == ' ')
			ft_error("Error In map");
	}
	else if (g->map_conf.map[j][i] != '1' && g->map_conf.map[j][i] != ' ')
		ft_error("Error\nWrong character in map");
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color, t_struct *g)
{
	if (x < g->map_conf.width && y < g->map_conf.height)
		if (x >= 0 && y >= 0)
			data->addr[y * g->map_conf.width + x] = color;
}

void	checkFloor(t_struct *g)
{
	checkNum(g->map_conf.data[0], g->map_conf.data[1], g->map_conf.data[2]);
	g->map_conf.rFloor = ft_atoi(g->map_conf.data[0]);
	g->map_conf.gFloor = ft_atoi(g->map_conf.data[1]);
	g->map_conf.bFloor = ft_atoi(g->map_conf.data[2]);
	if (g->map_conf.rFloor < 0 || g->map_conf.rFloor > 255)
		ft_error("Error red in floor");
	if (g->map_conf.gFloor < 0 || g->map_conf.gFloor > 255)
		ft_error("Error green in floor");
	if (g->map_conf.bFloor < 0 || g->map_conf.bFloor > 255)
		ft_error("Error blue in floor");
	g_floor = (g->map_conf.rFloor << 16)
		| (g->map_conf.gFloor << 8) | g->map_conf.bFloor;
}
