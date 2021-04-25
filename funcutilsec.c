#include "header.h"

void	fill_ceilling(char *line, int i, t_struct *g)
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
	g->map_conf.data = ft_split(line + i, ',');
	if (count_tab(g->map_conf.data) > 3)
		ft_error("Error\nCheck ceiling");
	if (comma > 2)
		ft_error("Error\n There is more than two commas");
	checkceeling(g);
	g_ceeling = (g->map_conf.ceilingR << 16)
		| (g->map_conf.ceilingG << 8) | g->map_conf.ceilingB;
}

void	checkceeling(t_struct *g)
{
	checkNum(g->map_conf.data[0], g->map_conf.data[1], g->map_conf.data[2]);
	g->map_conf.ceilingR = ft_atoi(g->map_conf.data[0]);
	g->map_conf.ceilingG = ft_atoi(g->map_conf.data[1]);
	g->map_conf.ceilingB = ft_atoi(g->map_conf.data[2]);
	if (g->map_conf.ceilingR < 0 || g->map_conf.ceilingR > 255)
		ft_error("Error\n red ceeling");
	if (g->map_conf.ceilingG < 0 || g->map_conf.ceilingG > 255)
		ft_error("Error\n green ceeling");
	if (g->map_conf.ceilingB < 0 || g->map_conf.ceilingB > 255)
		ft_error("Error\n blue ceeling");
}

void	creatingMap(char *line, t_struct *g)
{
	int		save;
	char	*tmp;

	save = ft_strlen(line);
	if (save > g->g_tmp_width)
		g->g_tmp_width = save;
	tmp = g->map_conf.wlrd;
	g->map_conf.wlrd = ft_strjoin_(g->map_conf.wlrd, line);
	tmp = g->map_conf.wlrd;
	g->map_conf.wlrd = ft_strjoin_(g->map_conf.wlrd, "\n");
	g->map_conf.numHeight++;
}

void	init_pl(int y, int x, t_struct *g)
{
	g->g_player.x = x * TILE_SIZE + (TILE_SIZE / 2);
	g->g_player.y = y * TILE_SIZE + (TILE_SIZE / 2);
	g->map_conf.player++;
}
