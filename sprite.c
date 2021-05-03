/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:41:08 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/30 13:15:28 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	renderSpProj(t_sprite *sp, t_r_struct *rays, t_struct *g)
{
	int			vbns;
	int			i;

	g->vbs = my_malloc(sizeof(t_sprite) * (g->map_conf.spNumber + 1), g);
	vbns = 0;
	i = 0;
	while (i < g->map_conf.spNumber)
	{
		sp->angleSpPlayer = g->move_player.rotationAngle
			- atan2(sp[i].y - g->g_player.y, sp[i].x - g->g_player.x);
		if (sp->angleSpPlayer > M_PI)
			sp->angleSpPlayer -= (2 * M_PI);
		if (sp->angleSpPlayer < -M_PI)
			sp->angleSpPlayer += (2 * M_PI);
		sp->angleSpPlayer = fabs(sp->angleSpPlayer);
		if (sp->angleSpPlayer < (FOV / 2) + EPSILON)
			calcsp(g, sp, i, &vbns);
		else
			sp[i].visibSp = 0;
		sortSprite(vbns, g);
		renderSprite(vbns, rays, g);
		i++;
	}
}

void	calcsp(t_struct *g, t_sprite *sp, int i, int *vbns)
{
	sp[i].visibSp = 1;
	sp[i].angle = sp->angleSpPlayer;
	sp[i].distance = distanceBpoint(sp[i].x,
			sp[i].y, g->g_player.x, g->g_player.y);
	g->vbs[*vbns] = sp[i];
	(*vbns)++;
}

void	sortSprite(int vbNumber, t_struct *g)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	while (i < vbNumber - 1)
	{
		j = i + 1;
		while (j < vbNumber)
		{
			if (g->vbs[i].distance < g->vbs[j].distance)
			{
				temp = g->vbs[i];
				g->vbs[i] = g->vbs[j];
				g->vbs[j] = temp;
			}
			j++;
		}
		i++;
	}
}
