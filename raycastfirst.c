/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:40:53 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/28 15:18:03 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rays_init(t_r_struct *rays, t_struct *g)
{
	rays->angle_norm = g->move_player.rotationAngle - (rays->fv_angle / 2);
	rays->num_rays = g->map_conf.width;
	rays->fv_angle = 60 * (M_PI / 180);
}

void	castAllRays(t_r_struct *rays, t_struct *g)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	rays_init(rays, g);
	text_init(g);
	while (i < rays->num_rays)
	{
		cast(rays, i, g);
		render_wall(rays, i, g);
		rays->angle_norm += (rays->fv_angle / rays->num_rays);
		i++;
	}
}

void	checkTheRayDir(t_r_struct *rays)
{	
	if (rays->angle_norm > 0 && rays->angle_norm < M_PI)
		rays->isRayFacingDown = 1;
	else
		rays->isRayFacingDown = 0;
	rays->isRayFacingUp = !rays->isRayFacingDown;
	if (rays->angle_norm < 0.5 * M_PI || rays->angle_norm > 1.5 * M_PI)
		rays->isRayFacingRight = 1;
	else
		rays->isRayFacingRight = 0;
	rays->isRayFacingLeft = !rays->isRayFacingRight;
}

void	cast(t_r_struct *rays, int i, t_struct *g)
{
	rays->angle_norm = angleSanitizer(rays->angle_norm);
	checkTheRayDir(rays);
	checkHorzInter(rays, g);
	checkVertInter(rays, g);
	calculDistance(rays, i, g);
}

void	checkHorzInter(t_r_struct *rays, t_struct *g)
{
	rays->hyintr = floor((g->g_player.y / TILE_SIZE)) * TILE_SIZE;
	if (rays->isRayFacingDown)
		rays->hyintr += TILE_SIZE;
	else
		rays->hyintr += 0;
	rays->hxintr = g->g_player.x + (rays->hyintr - g->g_player.y)
		/ tan(rays->angle_norm);
	rays->hystp = TILE_SIZE;
	if (rays->isRayFacingUp)
		rays->hystp *= -1;
	else
		rays->hystp *= 1;
	rays->hxstp = TILE_SIZE / tan(rays->angle_norm);
	if (rays->isRayFacingLeft && rays->hxstp > 0)
		rays->hxstp *= -1;
	else
		rays->hxstp *= 1;
	if (rays->isRayFacingRight && rays->hxstp < 0)
		rays->hxstp *= -1;
	else
		rays->hxstp *= 1;
	rays->xyinh[0] = rays->hxintr;
	rays->xyinh[1] = rays->hyintr;
	checkWallHorz(rays, g);
}
