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
			my_mlx_pixel_put(&data, i * NMS, j * NMS, color);
			i++;
		}
		j++;
	}
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
			catchThem(j, i);
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
	else if (map_conf.map[j][i] != ' ')
	{
		color = 0x605F5E;
		draw_square(i, j, img, color);
	}
}

void	render_ray(ray_struct *rays)
{
	int	i;

	i = 0;
	while (i < rays -> num_rays)
	{
		draw_line(g_player.x * NMS, g_player.y * NMS,
			rays[i].wallHitX * NMS, rays[i].wallHitY * NMS);
		i++;
	}
}
