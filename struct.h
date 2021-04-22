/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:09:54 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/22 16:10:27 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_data
{
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	int		*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

typedef struct	s_player
{
	float	x;
	float	y;
	int		last_x;
	int		last_y;

}				m_player;

typedef struct	mv_player
{
	int		x;
	int		y;
	int		radius;
	int		turnDirection;
	int		walkDirection;
	int		walkside;
	float	rotationAngle;
	float	moveSpeed;
	float	rotationSpeed;
	float	sideSteps;
}				cls_player;

typedef struct	map_config
{
	char	*filePath;
	char	**data;
	char	**map;
	char	*wlrd;
	char	*north_texture;
	char	*west_texture;
	char	*east_texture;
	char	*south_texture;
	char	*sprite_texture;
	char	*sprite;
	char	**world;
	int		width;
	int		rFloor;
	int		gFloor;
	int		bFloor;
	int		height;
	int		ceilingR;
	int		ceilingG;
	int		ceilingB;
	int		numHeight;
	int		numWidth;
	int		spNumber;
	int		counter;
	int		indx;
	int		player;
	int		startMP;
	int		res;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		s;
	int		f;
	int		c;
	int		result;
}				config_map;

typedef struct	rays
{
	float	horzwallHitX;
	float	horzwallHitY;
	float	nexthtx;
	float	nexthty;
	float	nextvtx;
	float	nextvty;
	float	vertwallHitX;
	float	vertwallHitY;
	float	wallHitX;
	float	wallHitY;
	float	fv_angle;
	float	distance;
	float	num_rays;
	float	angle_norm;
	float	hxstp;
	float	hystp;
	float	hxintr;
	float	hyintr;
	float	xyinh[2];
	float	vxstp;
	float	vystp;
	float	vxintr;
	float	vyintr;
	float	xyintrv[2];
	int		wall_strWidth;
	int		isRayFacingDown;
	int		isRayFacingUp;
	int		isRayFacingRight;
	int		isRayFacingLeft;
	int		foundHorzWallHit;
	int		foundVertWallHit;
	int		wasHitVertical;
	int		horzWallContent;
	int		vertWallContent;
	int		wallHitContent;
}				ray_struct;

typedef struct	walls
{
	float	distProjPlan;
	float	projWallHeight;
	float	wallTpPixel;
	float	wallBtPixel;
	float	perpDistance;
	int		wallStrHeight;

}				wall_struct;


typedef	struct	txt
{	
	int		offX;
	int		offY;
	int		dist;
}				txt_data;

typedef struct	sp
{
	float	x;
	float	y;
	float	dst;
	float	angleSpPlayer;
	float	angle;
	float	distance;
	int		visibSp;
	int		offX;
	int		offY;
}				t_sprite;

typedef struct	s_spt
{
	float	spHeight;
    float	spWidth;
    float	distProjPlan;
    float	spTpY;
    float	spBtY;
    float	spriteAngle;
    float	spritePosX;
    float	spriteLeftX;
    float	SpriteRightX;
    float	perdistance;
}				t_spt;


typedef struct	s_mem
{
	void *mem;
	struct s_mem *next;
}				t_mem;

#endif