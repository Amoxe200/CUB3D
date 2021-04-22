#include "header.h"

double	distanceBpoint(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1)
			+ (y2 - y1) * (y2 - y1)));
}

void	check_map(char *line, int i)
{
	if ((line[i] == '1' || line[i] == ' ')
		&& line[i] != '\0')
	{
		map_conf.startMP = 1;
		creatingMap(line);
	}
}

int	assigne_sprite(t_sprite sprite, int x, int y, ray_struct *rays)
{
	int	*data[2];
	int	dst;

	data[1] = sp.addr;
	dst = data[1][64 * sprite.offY + sprite.offX];
	if (sprite.distance < rays[x].distance && dst != 0xFF00FF)
		my_mlx_pixel_put(&img, x, y, dst);
	return (dst);
}

void	draw_sprite_in_map(t_sprite *sprite)
{
	int	k;
	int	i;
	int	j;
	int	colors;

	k = 0;
	while (k < map_conf.spNumber)
	{
		i = sprite[k].x / TILE_SIZE;
		j = sprite[k].y / TILE_SIZE;
		if (sprite[k].visibSp == 1)
			colors = 0xEA3546;
		else if (sprite[k].visibSp == 0)
			colors = 0xF9C80E;
		draw_square(i, j, img, colors);
		k++;
	}
}

void	store_the_spData(int i, int j, t_sprite *sprites, int indx)
{
	sprites[indx].x = (i + 0.5) * TILE_SIZE;
	sprites[indx].y = (j + 0.5) * TILE_SIZE;
}
