#include "header.h"

void	checkWallHorz(ray_struct *rays, t_struct *g)
{
	float	xToCheck;
	float	yToCheck;

	xToCheck = 0.0;
	yToCheck = 0.0;
	initwall(rays);
	checker(rays, xToCheck, yToCheck, g);
}

void	initwall(ray_struct *rays)
{
	rays->nexthtx = rays->xyinh[0];
	rays->nexthty = rays->xyinh[1];
	rays->foundHorzWallHit = 0;
	rays->horzwallHitX = 0;
	rays->horzwallHitY = 0;
}

void	checker(ray_struct *rays, float xToCheck, float yToCheck, t_struct *g)
{
	while (rays->nexthtx > 0 && rays->nexthtx < g->g_tmp_width * TILE_SIZE
		&& rays->nexthty > 0 && rays->nexthty < g->map_conf.numHeight * TILE_SIZE)
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
