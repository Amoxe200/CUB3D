#include "header.h"

void	catchThem(int j, int i)
{
	if (ft_strchr("NSWE", map_conf.map[j][i]))
		map_conf.player++;
	if (j == 0 || j == map_conf.numHeight)
	{
		if (map_conf.map[j][i] != '1' && map_conf.map[j][i] != ' ')
			ft_error("Error In map");
	}
	else if (map_conf.map[j][i] == '0' || map_conf.map[j][i] == '2'
			|| map_conf.map[j][i] == 'S' || map_conf.map[j][i] == 'N'
			|| map_conf.map[j][i] == 'W' || map_conf.map[j][i] == 'E')
	{
		if (map_conf.map[j - 1][i] == ' '
			|| map_conf.map[j][i + 1] == ' '
			|| map_conf.map[j + 1][i] == ' ')
			ft_error("Error In map");
	}
	else if (map_conf.map[j][i] != '1' && map_conf.map[j][i] != ' ')
		ft_error("Error\nWrong character in map");
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	if (x < map_conf.width && y < map_conf.height)
		if (x >= 0 && y >= 0)
			data->addr[y * map_conf.width + x] = color;
}

void	checkFloor(void)
{
	checkNum(map_conf.data[0], map_conf.data[1], map_conf.data[2]);
	map_conf.rFloor = ft_atoi(map_conf.data[0]);
	map_conf.gFloor = ft_atoi(map_conf.data[1]);
	map_conf.bFloor = ft_atoi(map_conf.data[2]);
	if (map_conf.rFloor < 0 || map_conf.rFloor > 255)
		ft_error("Error red in floor");
	if (map_conf.gFloor < 0 || map_conf.gFloor > 255)
		ft_error("Error green in floor");
	if (map_conf.bFloor < 0 || map_conf.bFloor > 255)
		ft_error("Error blue in floor");
	g_floor = (map_conf.rFloor << 16)
		| (map_conf.gFloor << 8) | map_conf.bFloor;
}

int	ft_error(char *err)
{
	printf("%s\n", err);
	exit(0);
}
