/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:40:25 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/28 15:18:03 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	distanceBpoint(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	check_map(char *line, int i, t_struct *g)
{
	if ((line[i] == '1' || line[i] == ' ') && line[i] != '\0')
	{
		g->map_conf.startMP = 1;
		creatingMap(line, g);
	}
}

int	assigne_sprite(t_sprite sprite, t_r_struct *rays, t_struct *g)
{
	int	*data[2];
	int	dst;

	data[1] = g->sp.addr;
	dst = data[1][64 * sprite.offY + sprite.offX];
	if (sprite.distance < rays[g->spr.x].distance && dst != 0xFF00FF)
		my_mlx_pixel_put(g->spr.x, g->spr.y, dst, g);
	return (dst);
}

void	draw_sprite_in_map(t_sprite *sprite, t_struct *g)
{
	int	k;
	int	i;
	int	j;
	int	colors;

	k = 0;
	while (k < g->map_conf.spNumber)
	{
		i = sprite[k].x / TILE_SIZE;
		j = sprite[k].y / TILE_SIZE;
		if (sprite[k].visibSp == 1)
			colors = 0xEA3546;
		else if (sprite[k].visibSp == 0)
			colors = 0xF9C80E;
		draw_square(i, j, colors, g);
		k++;
	}
}

void	store_the_spData(int i, int j, t_sprite *sprites, int indx)
{
	sprites[indx].x = (i + 0.5) * TILE_SIZE;
	sprites[indx].y = (j + 0.5) * TILE_SIZE;
}
