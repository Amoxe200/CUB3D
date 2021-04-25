#include "header.h"

void	render(t_struct *g)
{
	t_sprite	*sprites;
	ray_struct	rays[2561];

	sprites = my_malloc(sizeof(t_sprite) * (g->map_conf.spNumber + 1));
	castAllRays(rays, g);
	draw_map(sprites, g);
	renderSpProj(sprites, rays, g);
	render_ray(rays, g);
	draw_sprite_in_map(sprites, g);
	draw_player(g);
	mlx_put_image_to_window(g->img.mlx_ptr, g->img.win_ptr, g->img.img, 0, 0);
}

void	ft_line(float angle, int radius, int color, t_struct *g)
{
	float	nextX;
	float	nextY;
	int		k;

	k = 0;
	nextX = 0;
	nextY = 0;
	while (k < radius)
	{
		nextX = g->g_player.x + cos(angle) * k;
		nextY = g->g_player.y + sin(angle) * k;
		my_mlx_pixel_put(&(g->img), nextX * nms, nextY * nms, color, g);
		k++;
	}
}

void	draw_line(float pX, float pY, float dX, float dY, t_struct *g)
{
	int		dx;
	int		dy;
	float	steps;
	float	x_inc;
	float	y_inc;

	dx = dX - pX;
	dy = dY - pY;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	x_inc = dx / steps;
	y_inc = dy / steps;
	while (steps--)
	{
		my_mlx_pixel_put(&(g->img), pX, pY, 0xCE4760, g);
		pX += x_inc;
		pY += y_inc;
	}
}

void	draw_px(int x, int y, t_data data, int color, t_struct *g)
{
	int	i;
	int	j;
	int	c;
	int	d;

	i = TILE_SIZE * x;
	c = i;
	j = TILE_SIZE * y;
	d = j;
	while (j < d + 2)
	{
		i = c;
		while (i < c + 2)
		{
			my_mlx_pixel_put(&data, i * nms, j * nms, color, g);
			i++;
		}
		j++;
	}
}

void	circle(t_struct *g)
{
	int		radius;
	float	angle;
	int		color;

	radius = 10;
	angle = 0;
	color = 0x196876;
	while (angle < 2 * M_PI)
	{
		ft_line(angle, radius, color, g);
		angle += M_PI / 180;
	}
	ft_line(g->move_player.rotationAngle, 150, 0x662E9B, g);
}
