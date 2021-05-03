/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertraycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:41:14 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/28 15:41:34 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	checkVertInter(t_r_struct *rays, t_struct *g)
{
	rays->vxintr = floor((g->g_player.x / TILE_SIZE)) * TILE_SIZE;
	if (rays->isRayFacingRight)
		rays->vxintr += TILE_SIZE;
	rays->vyintr = g->g_player.y + (rays->vxintr - g->g_player.x)
		* tan(rays->angle_norm);
	rays->vxstp = TILE_SIZE;
	if (rays->isRayFacingLeft)
		rays->vxstp *= -1;
	else
		rays->vxstp *= 1;
	rays->vystp = TILE_SIZE * tan(rays->angle_norm);
	if (rays->isRayFacingUp && rays->vystp > 0)
		rays->vystp *= -1;
	else
		rays->vystp *= 1;
	if (rays->isRayFacingDown && rays->vystp < 0)
		rays->vystp *= -1;
	else
		rays->vystp *= 1;
	rays->xyintrv[0] = rays->vxintr;
	rays->xyintrv[1] = rays->vyintr;
	checkWallVert(rays, g);
}

void	checkWallVert(t_r_struct *rays, t_struct *g)
{
	float		ytoCheck;
	float		xtoCheck;

	xtoCheck = 0.0;
	ytoCheck = 0.0;
	vinitwall(rays);
	vchecker(rays, xtoCheck, ytoCheck, g);
}

void	vinitwall(t_r_struct *rays)
{
	rays->nextvtx = rays->xyintrv[0];
	rays->nextvty = rays->xyintrv[1];
	rays->foundVertWallHit = 0;
	rays->vertwallHitX = 0;
	rays->vertwallHitY = 0;
}

void	vchecker(t_r_struct *rays, float xtoCheck, float ytoCheck, t_struct *g)
{
	while (rays->nextvtx > 0 && rays->nextvty > 0 && rays->nextvty
		< g->map_conf.numHeight * TILE_SIZE)
	{
		if (rays->isRayFacingLeft)
			xtoCheck = rays->nextvtx - 1;
		else
			xtoCheck = rays->nextvtx;
		ytoCheck = rays->nextvty;
		if (g->map_conf.map[(int)(ytoCheck / TILE_SIZE)]
			[(int)(xtoCheck / TILE_SIZE)] == '1')
		{
			rays->foundVertWallHit = 1;
			rays->vertWallContent = g->map_conf.map[(int)(ytoCheck / TILE_SIZE)]
			[(int)(xtoCheck / TILE_SIZE)];
			rays->vertwallHitX = rays->nextvtx;
			rays->vertwallHitY = rays->nextvty;
			break ;
		}
		else
		{
			rays->nextvtx += rays->vxstp;
			rays->nextvty += rays->vystp;
		}
	}
}
