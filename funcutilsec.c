#include "header.h"

void	fill_ceilling(char *line, int i)
{
	int	comma;
	int	j;

	comma = 0;
	i += 2;
	j = i;
	while (line[i] == ' ')
		i++;
	while (line[j])
	{
		if (line[j] == ',')
			comma++;
		j++;
	}
	if (!ft_isdigit(line[ft_strlen(line) - 1]))
		ft_error("Error\nCheck Ceiling");
	map_conf.data = ft_split(line + i, ',');
	if (count_tab(map_conf.data) > 3)
		ft_error("Error\nCheck ceiling");
	if (comma > 2)
		ft_error("Error\n There is more than two commas");
	checkceeling();
	g_ceeling = (map_conf.ceilingR << 16)
		| (map_conf.ceilingG << 8) | map_conf.ceilingB;
}

void	checkceeling(void)
{
	checkNum(map_conf.data[0], map_conf.data[1], map_conf.data[2]);
	map_conf.ceilingR = ft_atoi(map_conf.data[0]);
	map_conf.ceilingG = ft_atoi(map_conf.data[1]);
	map_conf.ceilingB = ft_atoi(map_conf.data[2]);
	if (map_conf.ceilingR < 0 || map_conf.ceilingR > 255)
		ft_error("Error\n red ceeling");
	if (map_conf.ceilingG < 0 || map_conf.ceilingG > 255)
		ft_error("Error\n green ceeling");
	if (map_conf.ceilingB < 0 || map_conf.ceilingB > 255)
		ft_error("Error\n blue ceeling");
}

void	creatingMap(char *line)
{
	int		save;
	char	*tmp;

	save = ft_strlen(line);
	if (save > g_tmp_width)
		g_tmp_width = save;
	tmp = map_conf.wlrd;
	map_conf.wlrd = ft_strjoin_(map_conf.wlrd, line);
	tmp = map_conf.wlrd;
	map_conf.wlrd = ft_strjoin_(map_conf.wlrd, "\n");
	map_conf.numHeight++;
}

void	init_pl(int y, int x)
{
	g_player.x = x * TILE_SIZE + (TILE_SIZE / 2);
	g_player.y = y * TILE_SIZE + (TILE_SIZE / 2);
	map_conf.player++;
}
