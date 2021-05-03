/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcutilsec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:40:28 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/30 17:27:37 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	g->map_conf.data = ft_split(line + i, ',', g);
	if (count_tab(g->map_conf.data) > 3)
		ft_error("Error\nCheck ceiling");
	if (comma > 2)
		ft_error("Error\n There is more than two commas");
	checkceeling(g);
	g->ceeling = (g->map_conf.ceilingR << 16)
		| (g->map_conf.ceilingG << 8) | g->map_conf.ceilingB;
}

void	checkceeling(t_struct *g)
{
	if (g->map_conf.data[0] == NULL || g->map_conf.data[1] == NULL
		|| g->map_conf.data[2] == NULL)
		ft_error("Error\n Check ceilling");
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
	if (save > g->tmp_width)
		g->tmp_width = save;
	tmp = g->map_conf.wlrd;
	g->map_conf.wlrd = ft_strjoin_(g->map_conf.wlrd, line, g);
	tmp = g->map_conf.wlrd;
	g->map_conf.wlrd = ft_strjoin_(g->map_conf.wlrd, "\n", g);
	free(tmp);
	g->map_conf.numHeight++;
}

void	init_pl(int y, int x, t_struct *g)
{
	char	c;

	c = g->map_conf.map[y][x];
	if (c == 'N')
		g->move_player.rotationAngle = 270 * (M_PI / 180);
	else if (c == 'S')
		g->move_player.rotationAngle = 90 * (M_PI / 180);
	else if (c == 'E')
		g->move_player.rotationAngle = 0;
	else if (c == 'W')
		g->move_player.rotationAngle = M_PI;
	g->g_player.x = x * TILE_SIZE + (TILE_SIZE / 2);
	g->g_player.y = y * TILE_SIZE + (TILE_SIZE / 2);
	g->map_conf.player++;
}
