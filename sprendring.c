/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprendring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:41:05 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/28 15:18:03 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	initonesp(t_struct *g, t_sprite sprite)
{
	g->spr.perdistance = sprite.distance * cos(sprite.angle);
	g->spr.spHeight = (TILE_SIZE / g->spr.perdistance)
		* g->spr.distProjPlan;
	g->spr.spWidth = g->spr.spHeight;
	g->spr.spTpY = (g->map_conf.height / 2) - (g->spr.spHeight / 2);
	if (g->spr.spTpY < 0)
		g->spr.spTpY = 0;
	else
		g->spr.spTpY = g->spr.spTpY;
	g->spr.spBtY = (g->map_conf.height / 2) + (g->spr.spHeight / 2);
	if (g->spr.spBtY > g->map_conf.height)
		g->spr.spBtY = g->map_conf.height;
	else
		g->spr.spBtY = g->spr.spBtY;
	g->spr.spriteAngle = atan2(sprite.y - g->g_player.y,
			sprite.x - g->g_player.x) - g->move_player.rotationAngle;
	g->spr.spritePosX = tan(g->spr.spriteAngle) * g->spr.distProjPlan;
	g->spr.spriteLeftX = (g->map_conf.width / 2)
		+ g->spr.spritePosX - (g->spr.spWidth / 2);
	g->spr.spriteRightX = g->spr.spriteLeftX + g->spr.spWidth;
	return (g->spr.spriteLeftX);
}

void	inititwosp(t_struct *g, t_sprite sprite, t_r_struct *rays)
{
	float	texelWidth;
	int		distFtop;

	while (g->spr.x < g->spr.spriteRightX)
	{
		texelWidth = (64 / g->spr.spWidth);
		if ((g->spr.x - g->spr.spriteLeftX) * texelWidth < 0)
			sprite.offX = 0;
		else
			sprite.offX = (g->spr.x - g->spr.spriteLeftX) * texelWidth;
		g->spr.y = g->spr.spTpY;
		while (g->spr.y < g->spr.spBtY)
		{
			if (g->spr.x > 0 && g->spr.x < g->map_conf.width
				&& g->spr.y > 0 && g->spr.y < g->map_conf.height)
			{
				distFtop = g->spr.y + (g->spr.spHeight / 2)
					- (g->map_conf.height / 2);
				sprite.offY = distFtop * (64 / g->spr.spHeight);
				assigne_sprite(sprite, rays, g);
			}
			(g->spr.y)++;
		}
		(g->spr.x)++;
	}
}

void	renderSprite(int vbNumber, t_r_struct *rays, t_struct *g)
{
	int			i;
	t_sprite	sprite;

	i = 0;
	g->spr.distProjPlan = ((g->map_conf.width / 2) / tan(FOV / 2));
	while (i < vbNumber)
	{
		sprite = g->vbs[i];
		g->spr.x = initonesp(g, sprite);
		inititwosp(g, sprite, rays);
		i++;
	}
}
