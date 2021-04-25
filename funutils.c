#include "header.h"

int	has_wall(float x, float y, t_struct *g)
{
	int	ughx;
	int	ughy;

	if (x < 0 || x > (g->map_conf.width * TILE_SIZE)
		|| y < 0 || y > (g->map_conf.height * TILE_SIZE))
		return (1);
	ughx = floor(x / TILE_SIZE);
	ughy = floor(y / TILE_SIZE);
	if (g->map_conf.map[ughy][ughx] == '1')
		return (1);
	else
		return (0);
}

int	count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	*fill_textures(char *texture, char *line, int i)
{
	i += 2;
	while (line[i] == ' ')
		i++;
	texture = ft_strdup_(line + i);
	return (texture);
}

void	fill_floor(char *line, int i, t_struct *g)
{
	int	j;
	int	comma;

	j = i;
	comma = 0;
	i += 2;
	while (line[i] == ' ')
		i++;
	while (line[j])
	{
		if (line[j] == ',')
			comma++;
		j++;
	}
	if (!ft_isdigit(line[ft_strlen(line) - 1]))
		ft_error("Error\nCheck floor");
	g->map_conf.data = ft_split(line + i, ',');
	if (count_tab(g->map_conf.data) > 3)
		ft_error("Error\nCheck floor");
	if (comma > 2)
		ft_error("Error\n There is more than two commas");
	checkFloor(g);
}

void	checkNum(char *str, char *str2, char *str3)
{
	int	i;

	i = 0;
	while (str[i] && str2[i] && str3[i])
	{
		if (ft_isdigit(str[i]) == 0 || ft_isdigit(str2[i]) == 0
			|| ft_isdigit(str3[i]) == 0)
			ft_error("Error\n Check your ceiling or floor");
		i++;
	}
}
