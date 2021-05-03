/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routingtwo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:41:02 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/28 13:02:50 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	collect_text(char *line, int i, t_struct *g)
{
	textnsw(line, i, g);
	textesf(line, i, g);
	if (line[i] != '\0' && line[i] == 'C'
		&& line[i + 1] == ' ' && (++(g->map_conf).counter))
	{
		fill_ceilling(line, i, g);
		(g->map_conf).c += 670;
	}
}

void	textnsw(char *line, int i, t_struct *g)
{
	if (line[i] != '\0' && line[i] == 'N'
		&& line[i + 1] == 'O' && (++(g->map_conf).counter))
	{
		(g->map_conf).north_texture
			= fill_textures((g->map_conf).north_texture, line, i, g);
		(g->map_conf).no += 200;
	}
	else if (line[i] != '\0' && line[i] == 'S'
		&& line[i + 1] == 'O' && (++(g->map_conf).counter))
	{
		(g->map_conf).south_texture
			= fill_textures((g->map_conf).south_texture, line, i, g);
		(g->map_conf).so += 500;
	}
	else if (line[i] != '\0' && line[i] == 'W'
		&& line[i + 1] == 'E' && (++(g->map_conf).counter))
	{
		(g->map_conf).west_texture
			= fill_textures((g->map_conf).west_texture, line, i, g);
		(g->map_conf).we += 40;
	}
}

void	textesf(char *line, int i, t_struct *g)
{
	if (line[i] != '\0' && line[i] == 'E'
		&& line[i + 1] == 'A' && (++(g->map_conf).counter))
	{
		(g->map_conf).east_texture
			= fill_textures((g->map_conf).east_texture, line, i, g);
		(g->map_conf).ea += 600;
	}
	else if (line[i] != '\0' && line[i] == 'S'
		&& line[i + 1] == ' ' && (++(g->map_conf).counter))
	{
		(g->map_conf).sprite
			= fill_textures((g->map_conf).sprite, line, i, g);
		(g->map_conf).s += 20;
	}
	else if (line[i] != '\0' && line[i] == 'F'
		&& line[i + 1] == ' ' && (++(g->map_conf).counter))
	{
		fill_floor(line, i, g);
		(g->map_conf).f += 350;
	}
}
