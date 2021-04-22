#include "header.h"

void	spinitone(t_sprite sprite, t_spt *sp)
{
	(*sp).perdistance = sprite.distance * cos(sprite.angle);
	(*sp).spHeight = (TILE_SIZE / (*sp).perdistance)
		* (*sp).distProjPlan;
	(*sp).spWidth = (*sp).spHeight;
	(*sp).spTpY = (map_conf.height / 2) - ((*sp).spHeight / 2);
	if (((*sp).spTpY < 0))
		(*sp).spTpY = 0;
	else
		(*sp).spTpY = (*sp).spTpY;
	(*sp).spBtY = (map_conf.height / 2) + ((*sp).spHeight / 2);
	if (((*sp).spBtY > map_conf.height))
		(*sp).spBtY = map_conf.height;
	else
		(*sp).spBtY = (*sp).spBtY;
	(*sp).spriteAngle = atan2(sprite.y - g_player.y,
			sprite.x - g_player.x) - move_player.rotationAngle;
	(*sp).spritePosX = tan((*sp).spriteAngle) * (*sp).distProjPlan;
	(*sp).spriteLeftX = (map_conf.width / 2) + (*sp).spritePosX
		- ((*sp).spWidth / 2);
	(*sp).SpriteRightX = (*sp).spriteLeftX + (*sp).spWidth;
}

void	spinittwo(t_sprite sprite, t_spt *sp, ray_struct *rays)
{
	int		y;
	int		x;
	int		distFtop;
	float	texelWidth;

	x = (*sp).spriteLeftX - 1;
	while (++x < (*sp).SpriteRightX)
	{
		texelWidth = (64 / (*sp).spWidth);
		if ((x - (*sp).spriteLeftX) * texelWidth < 0)
			sprite.offX = 0;
		else
			sprite.offX = (x - (*sp).spriteLeftX) * texelWidth;
		y = (*sp).spTpY - 1;
		while (++y < (*sp).spBtY)
		{
			if (x > 0 && x < map_conf.width && y > 0 && y < map_conf.height)
			{
				distFtop = y + ((*sp).spHeight / 2) - (map_conf.height / 2);
				sprite.offY = distFtop * (64 / (*sp).spHeight);
				assigne_sprite(sprite, x, y, rays);
			}
		}
	}
}

void	renderSprite(int vbNumber, t_sprite *visibSprite, ray_struct *rays)
{
	int			i;
	t_spt		sp;
	t_sprite	sprite;

	i = -1;
	sp.distProjPlan = ((map_conf.width / 2) / tan(FOV / 2));
	while (++i < vbNumber)
	{
		sprite = visibSprite[i];
		spinitone(sprite, &sp);
		spinittwo(sprite, &sp, rays);
	}
}
