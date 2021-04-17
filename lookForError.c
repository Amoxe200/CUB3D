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