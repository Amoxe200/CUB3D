/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horzRaycats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:40:36 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/28 15:18:03 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	checkWallHorz(t_r_struct *rays, t_struct *g)
{
	float	xToCheck;
	float	yToCheck;

	xToCheck = 0.0;
	yToCheck = 0.0;
	initwall(rays);
	checker(rays, xToCheck, yToCheck, g);
}

void	initwall(t_r_struct *rays)
{
	rays->nexthtx = rays->xyinh[0];
	rays->nexthty = rays->xyinh[1];
	rays->foundHorzWallHit = 0;
	rays->horzwallHitX = 0;
	rays->horzwallHitY = 0;
}

void	checker(t_r_struct *rays, float xToCheck, float yToCheck, t_struct *g)
{
	while (rays->nexthtx > 0 && rays->nexthtx < g->tmp_width * TILE_SIZE
		&& rays->nexthty > 0 && rays->nexthty
		< g->map_conf.numHeight * TILE_SIZE)
	{
		xToCheck = rays->nexthtx;
		if (rays->isRayFacingUp)
			yToCheck = rays->nexthty - 1;
		else
			yToCheck = rays->nexthty;
		if (g->map_conf.map[(int)(yToCheck / TILE_SIZE)]
			[(int)(xToCheck / TILE_SIZE)] == '1')
		{
			rays->foundHorzWallHit = 1;
			rays->horzWallContent = g->map_conf.map[(int)(yToCheck / TILE_SIZE)]
			[(int)(xToCheck / TILE_SIZE)];
			rays->horzwallHitX = rays->nexthtx;
			rays->horzwallHitY = rays->nexthty;
			break ;
		}
		else
		{
			rays->nexthtx += rays->hxstp;
			rays->nexthty += rays->hystp;
		}
	}
}
