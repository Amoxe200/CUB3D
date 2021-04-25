#include "header.h"

void	render_wall(ray_struct *rays, int i, t_struct *g)
{
	int	y;

	y = 0;
	initalize(rays, i, g);
	while (y < g->wall.wallTpPixel)
	{
		my_mlx_pixel_put(&(g->img), i, y, g_floor, g);
		y++;
	}
	y = g->wall.wallTpPixel;
	while (y < g->wall.wallBtPixel)
	{
		g->dtx.dist = y + (g->wall.wallStrHeight / 2) - (g->map_conf.height / 2);
		g->dtx.offY = (int)(g->dtx.dist * ((float)64 / g->wall.wallStrHeight));
		my_mlx_pixel_put(&(g->img), i, y, assign_text(i, rays, g), g);
		y++;
	}
	y = g->wall.wallBtPixel;
	while (y < g->map_conf.height)
	{
		my_mlx_pixel_put(&(g->img), i, y, g_ceeling, g);
		y++;
	}
}

void	initalize(ray_struct *rays, int i, t_struct *g)
{
	g->wall.perpDistance = (rays[i].distance
			* cos(rays[i].angle_norm - g->move_player.rotationAngle));
	g->wall.distProjPlan = (g->map_conf.width / 2) / tan(rays->fv_angle / 2);
	g->wall.projWallHeight = (TILE_SIZE / g->wall.perpDistance) * g->wall.distProjPlan;
	g->wall.wallStrHeight = (int)g->wall.projWallHeight;
	g->wall.wallTpPixel = (g->map_conf.height / 2) - (g->wall.wallStrHeight / 2);
	if (g->wall.wallTpPixel < 0)
		g->wall.wallTpPixel = 0;
	else
		g->wall.wallTpPixel = g->wall.wallTpPixel;
	g->wall.wallBtPixel = (g->map_conf.height / 2) + (g->wall.wallStrHeight / 2);
	if (g->wall.wallBtPixel > g->map_conf.height)
		g->wall.wallBtPixel = g->map_conf.height;
	else
		g->wall.wallBtPixel = g->wall.wallBtPixel;
	if (rays[i].wasHitVertical)
		g->dtx.offX = (int)rays[i].wallHitY % TILE_SIZE;
	else
		g->dtx.offX = (int)rays[i].wallHitX % TILE_SIZE;
}
