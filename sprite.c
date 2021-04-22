#include "header.h"

void	renderSpProj(t_sprite *sprites, ray_struct *rays)
{
	int			vbNumSp;
	int			i;
	t_sprite	*visibSprite;

	visibSprite = my_malloc(sizeof(t_sprite) * (map_conf.spNumber + 1));
	vbNumSp = 0;
	i = -1;
	while (++i < map_conf.spNumber)
	{
		sprites->angleSpPlayer = move_player.rotationAngle
			- atan2(sprites[i].y - g_player.y, sprites[i].x - g_player.x);
		if (sprites->angleSpPlayer > M_PI)
			sprites->angleSpPlayer -= (2 * M_PI);
		if (sprites->angleSpPlayer < -M_PI)
			sprites->angleSpPlayer += (2 * M_PI);
		sprites->angleSpPlayer = fabs(sprites->angleSpPlayer);
		if (sprites->angleSpPlayer < (FOV / 2) + EPSILON)
			calcsp(sprites, i, visibSprite, &vbNumSp);
		else
			sprites[i].visibSp = 0;
		sortSprite(vbNumSp, visibSprite);
		renderSprite(vbNumSp, visibSprite, rays);
	}
}

void	calcsp(t_sprite *sprites, int i, t_sprite *vbSp, int *vbNum)
{
	sprites[i].visibSp = 1;
	sprites[i].angle = sprites->angleSpPlayer;
	sprites[i].distance = distanceBpoint(sprites[i].x,
			sprites[i].y, g_player.x, g_player.y);
	vbSp[(*vbNum)] = sprites[i];
	(*vbNum)++;
}

void	sortSprite(int vbNumber, t_sprite *visibleSprite)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	while (i < vbNumber - 1)
	{
		j = i + 1;
		while (j < vbNumber)
		{
			if (visibleSprite[i].distance < visibleSprite[j].distance)
			{
				temp = visibleSprite[i];
				visibleSprite[i] = visibleSprite[j];
				visibleSprite[j] = temp;
			}
			j++;
		}
		i++;
	}
}
