#include "header.h"

double	angleSanitizer(float angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

void	calculDistance(ray_struct *rays, int i, t_struct *g)
{
	float	horzHitDistance;
	float	vertHitDistance;

	if (rays->foundHorzWallHit)
		horzHitDistance = distanceBpoint(g->g_player.x, g->g_player.y,
				rays->horzwallHitX, rays->horzwallHitY);
	else
		horzHitDistance = INT_MAX;
	if (rays->foundVertWallHit)
		vertHitDistance = distanceBpoint(g->g_player.x, g->g_player.y,
				rays->vertwallHitX, rays->vertwallHitY);
	else
		vertHitDistance = INT_MAX;
	compDist(horzHitDistance, vertHitDistance, rays, i);
	store_array(rays, i);
}

void	compDist(float h_hdist, float v_hdist, ray_struct *rays, int i)
{
	if (v_hdist < h_hdist)
	{
		rays[i].distance = v_hdist;
		rays[i].wallHitX = rays->vertwallHitX;
		rays[i].wallHitY = rays->vertwallHitY;
		rays[i].wallHitContent = rays->vertWallContent;
		rays[i].wasHitVertical = 1;
	}
	else
	{
		rays[i].distance = h_hdist;
		rays[i].wallHitX = rays->horzwallHitX;
		rays[i].wallHitY = rays->horzwallHitY;
		rays[i].wallHitContent = rays->horzWallContent;
		rays[i].wasHitVertical = 0;
	}
}

void	store_array(ray_struct *rays, int i)
{
	rays[i].angle_norm = rays->angle_norm;
	rays[i].isRayFacingDown = rays->isRayFacingDown;
	rays[i].isRayFacingUp = rays->isRayFacingUp;
	rays[i].isRayFacingLeft = rays->isRayFacingLeft;
	rays[i].isRayFacingRight = rays->isRayFacingRight;
}
