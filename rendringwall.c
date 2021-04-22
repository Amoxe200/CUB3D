#include "header.h"

void	render_wall(ray_struct *rays, int i)
{
	int	y;

	y = 0;
	initalize(rays, i);
	while (y < wall.wallTpPixel)
	{
		my_mlx_pixel_put(&img, i, y, g_floor);
		y++;
	}
	y = wall.wallTpPixel;
	while (y < wall.wallBtPixel)
	{
		dtx.dist = y + (wall.wallStrHeight / 2) - (map_conf.height / 2);
		dtx.offY = (int)(dtx.dist * ((float)64 / wall.wallStrHeight));
		my_mlx_pixel_put(&img, i, y, assign_text(i, rays));
		y++;
	}
	y = wall.wallBtPixel;
	while (y < map_conf.height)
	{
		my_mlx_pixel_put(&img, i, y, g_ceeling);
		y++;
	}
}

void	initalize(ray_struct *rays, int i)
{
	wall.perpDistance = (rays[i].distance
			* cos(rays[i].angle_norm - move_player.rotationAngle));
	wall.distProjPlan = (map_conf.width / 2) / tan(rays->fv_angle / 2);
	wall.projWallHeight = (TILE_SIZE / wall.perpDistance) * wall.distProjPlan;
	wall.wallStrHeight = (int)wall.projWallHeight;
	wall.wallTpPixel = (map_conf.height / 2) - (wall.wallStrHeight / 2);
	if (wall.wallTpPixel < 0)
		wall.wallTpPixel = 0;
	else
		wall.wallTpPixel = wall.wallTpPixel;
	wall.wallBtPixel = (map_conf.height / 2) + (wall.wallStrHeight / 2);
	if (wall.wallBtPixel > map_conf.height)
		wall.wallBtPixel = map_conf.height;
	else
		wall.wallBtPixel = wall.wallBtPixel;
	if (rays[i].wasHitVertical)
		dtx.offX = (int)rays[i].wallHitY % TILE_SIZE;
	else
		dtx.offX = (int)rays[i].wallHitX % TILE_SIZE;
}
