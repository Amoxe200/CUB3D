#include "header.h"

void	draw_square(int x, int y, t_data data, int color, t_struct *g)
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
			my_mlx_pixel_put(&data, i * nms, j * nms, color, g);
			i++;
		}
		j++;
	}
}

void	draw_map(t_sprite *sprites, t_struct *g)
{
	int	i;
	int	j;

	j = 0;
	g->map_conf.indx = 0;
	g->map_conf.player = 0;
	while (j < g->map_conf.numHeight)
	{
		i = 0;
		while (i < g->g_tmp_width)
		{
			drawTheMap(i, j, sprites, g);
			i++;
		}
		j++;
	}
}

void	lookError(t_struct *g)
{
	int	i;
	int	j;

	j = 0;
	while (g->map_conf.map[j])
	{
		i = 0;
		while (g->map_conf.map[j][i])
		{
			catchThem(j, i, g);
			i++;
		}
		j++;
	}
}

void	drawTheMap(int i, int j, t_sprite *sprites, t_struct *g)
{
	int	color;

	if (g->map_conf.map[j][i] == '1')
	{
		color = 0x0E3B43;
		draw_square(i, j, g->img, color, g);
	}
	else if (g->map_conf.map[j][i] == '2')
		store_the_spData(i, j, sprites, g->map_conf.indx++);
	else if (g->map_conf.map[j][i] != ' ')
	{
		color = 0x605F5E;
		draw_square(i, j, g->img, color, g);
	}
}

void	render_ray(ray_struct *rays, t_struct *g)
{
	int	i;

	i = 0;
	while (i < rays -> num_rays)
	{
		draw_line(g->g_player.x * nms, g->g_player.y * nms,
			rays[i].wallHitX * nms, rays[i].wallHitY * nms, g);
		i++;
	}
}
