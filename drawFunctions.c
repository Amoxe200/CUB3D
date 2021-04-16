#include "header.h"

void	draw_square(int x, int y, t_data data, int color)
{
	int	i;
	int	j;
	int	c;
	int	d;

	i = TILE_SIZE * x;
	c = i;
	j = TILE_SIZE * y;
	d = j;
	while (j < d + TILE_SIZE)
	{
		i = c;
		while (i < c + TILE_SIZE)
		{
			my_mlx_pixel_put(&data, i * nms, j * nms, color);
			i++;
		}
		j++;
	}
}

void	draw_px(int x, int y, t_data data, int color)
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
			my_mlx_pixel_put(&data, i * nms, j * nms, color);
			i++;
		}
		j++;
	}
}

void	circle(int x, int y)
{
	int		radius;
	float	angle;
	int		color;

	radius = 10;
	angle = 0;
	color = 0x196876;
	while (angle < 2 * M_PI)
	{
		ft_line(angle, radius, color);
		angle += M_PI / 180;
	}
	ft_line(move_player.rotationAngle, 150, 0x662E9B);
}

void	draw_map(t_sprite *sprites)
{
	int	i;
	int	j;

	j = 0;
	map_conf.indx = 0;
	map_conf.player = 0;
	while (j < map_conf.numHeight)
	{
		i = 0;
		while (i < g_tmp_width)
		{
			drawTheMap(i, j, sprites);
			i++;
		}
		j++;
	}
}

void	lookError(void)
{
	int	i;
	int	j;

	j = 0;
	while (map_conf.map[j])
	{
		i = 0;
		while (map_conf.map[j][i])
		{
			if (ft_strchr("NSWE", map_conf.map[j][i]))
				map_conf.player++;
			if (j == 0 || j == map_conf.numHeight)
			{
				if (map_conf.map[j][i] != '1' && map_conf.map[j][i] != ' ')
					ft_error("Error In map");
			}
			else if (map_conf.map[j][i] == '0' || map_conf.map[j][i] == '2'
			|| map_conf.map[j][i] == 'S' || map_conf.map[j][i] == 'N'
			|| map_conf.map[j][i] == 'W' || map_conf.map[j][i] == 'E')
			{
				if (map_conf.map[j - 1][i] == ' '
				|| map_conf.map[j][i + 1] == ' '
				|| map_conf.map[j + 1][i] == ' ')
					ft_error("Error In map");
			}
			else if (map_conf.map[j][i] != '1' && map_conf.map[j][i] != ' ')
				ft_error("Error\nWrong character in map");
			i++;
		}
		j++;
	}
}

void	drawTheMap(int i, int j, t_sprite *sprites)
{
	int	color;

	if (map_conf.map[j][i] == '1')
	{
		color = 0x0E3B43;
		draw_square(i, j, img, color);
	}
	else if (map_conf.map[j][i] == '2')
		store_the_spData(i, j, sprites, map_conf.indx++);
	else
	{
		color = 0x605F5E;
		draw_square(i, j, img, color);
	}
}

void	draw_player(void)
{
	int	color;

	color = 0x662E9B;
	circle(g_player.last_x, g_player.last_y);
}

void	render_ray(ray_struct *rays)
{
	int	i;

	i = 0;
	while (i < rays -> num_rays)
	{
		draw_line(g_player.x * nms, g_player.y * nms, rays[i].wallHitX * nms, rays[i].wallHitY * nms);
		i++;
	}
}

void	render(void)
{
	ray_struct	rays[map_conf.width];
	t_sprite	sprites[map_conf.spNumber];

	castAllRays(rays);
	draw_map(sprites);
	renderSpProj(sprites, rays);
	render_ray(rays);
	draw_sprite_in_map(sprites);
	draw_player();
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
}

void	ft_line(float angle, int radius, int color)
{
	float	nextX;
	float	nextY;
	int		k;

	k = 0;
	nextX = 0;
	nextY = 0;
	while (k < radius)
	{
		nextX = g_player.x + cos(angle) * k;
		nextY = g_player.y + sin(angle) * k;
		my_mlx_pixel_put(&img, nextX * nms, nextY * nms, color);
		k++;
	}
}

void	draw_line(float pX, float pY, float dX, float dY)
{
	int		dx;
	int		dy;
	float	steps;
	float	x_inc;
	float	y_inc;

	dx = dX - pX;
	dy = dY - pY;
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	x_inc = dx / steps;
	y_inc = dy / steps;
	while (steps--)
	{
		my_mlx_pixel_put(&img, pX, pY, 0xCE4760);
		pX += x_inc;
		pY += y_inc;
	}
}