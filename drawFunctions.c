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
				// if (map_conf.map[j][i] == '0')
				// {
				// 	printf("j = %d\n", j);
				// 	printf("i = %d\n", i);
				// 	printf("j - 1 =  %c", map_conf.map[j - 1][i]);
				// 	printf("\n");
				// 	printf("repaire = %c", map_conf.map[j][i]);
				// 	printf("\n");
				// 	printf("i + 1 = %c", map_conf.map[j][i + 1]);
				// 	printf("\n");
				// 	printf("j + 1 = %c", map_conf.map[j + 1][i]);
				// 	printf("\n");
				// }
				if (map_conf.map[j - 1][i] == ' '
				|| map_conf.map[j][i + 1] == ' '
				|| map_conf.map[j + 1][i] == ' ')
				{
					printf("%d %d\n",j ,i);
					ft_error("Error In map");
				}
			}
			else if (map_conf.map[j][i] != '1' && map_conf.map[j][i] != ' ')
				ft_error("Error\nWrong character in map");
			i++;
		}
		printf("\n");
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

void	render_ray(ray_struct *rays)
{
	int	i;

	i = 0;
	while (i < rays -> num_rays)
	{
		draw_line(g_player.x * nms, g_player.y * nms,
			rays[i].wallHitX * nms, rays[i].wallHitY * nms);
		i++;
	}
}
