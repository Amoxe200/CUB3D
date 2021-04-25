#include "header.h"

void	renderSpProj(t_sprite *sprites, ray_struct *rays, t_struct *g)
{
	int			vbNumSp;
	float		angleSpPlayer;
	int			i;
	t_sprite	*visibSprite;

	visibSprite = my_malloc(sizeof(t_sprite) * (g->map_conf.spNumber + 1));
	vbNumSp = 0;
	i = 0;
	while (i < g->map_conf.spNumber)
	{
		angleSpPlayer = g->move_player.rotationAngle
			- atan2(sprites[i].y - g->g_player.y, sprites[i].x - g->g_player.x);
		if (angleSpPlayer > M_PI)
			angleSpPlayer -= (2 * M_PI);
		if (angleSpPlayer < -M_PI)
			angleSpPlayer += (2 * M_PI);
		angleSpPlayer = fabs(angleSpPlayer);
		if (angleSpPlayer < (FOV / 2) + EPSILON)
		{
			sprites[i].visibSp = 1;
			sprites[i].angle = angleSpPlayer;
			sprites[i].distance = distanceBpoint(sprites[i].x,
					sprites[i].y, g->g_player.x, g->g_player.y);
			visibSprite[vbNumSp] = sprites[i];
			vbNumSp++;
		}
		else
			sprites[i].visibSp = 0;
		sortSprite(vbNumSp, visibSprite);
		renderSprite(vbNumSp, visibSprite, rays, g);
		i++;
	}
}

// void	spCalc(t_sprite *sprites, int i, t_sprite *vbSp, int vbNum)
// {
	
// }

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
