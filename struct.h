/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:43:01 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/30 14:50:20 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define		UP_DIR 13
# define		DOWN_DIR 1
# define		LEFT_ARROW 123
# define		RIGHT_ARROW 124
# define		RIGHT_DIR 2
# define		ECHAP 53
# define		A 0
# define		D 2

typedef struct s_data
{
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	int		*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}					t_data;

typedef struct s_player
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		last_y;
	int		last_x;
}					t_player;

typedef struct s_mv_player
{
	float	rotationAngle;
	float	moveSpeed;
	float	rotationSpeed;
	float	sideSteps;
	int		x;
	int		y;
	int		radius;
	int		turnDirection;
	int		walkDirection;
	int		walkside;
}					t_cls_player;

typedef struct s_map_config
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
	int		ceilingR;
	int		ceilingG;
	int		ceilingB;
	int		numHeight;
	int		numWidth;
	int		spNumber;
	int		counter;
	int		startMP;
	int		rFloor;
	int		gFloor;
	int		bFloor;
	int		height;
	int		player;
	int		width;
	int		indx;
	int		res;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		s;
	int		f;
	int		c;
	int		result;
}				t_config_map;

typedef struct s_rays
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
}				t_r_struct;

typedef struct s_walls
{
	float	distProjPlan;
	float	projWallHeight;
	float	wallTpPixel;
	float	wallBtPixel;
	float	perpDistance;
	int		wallStrHeight;

}				t_wall_struct;

typedef struct s_txt
{
	int	offX;
	int	offY;
	int	dist;
}				t_txt_data;

typedef struct s_sp
{
	float	angleSpPlayer;
	float	angle;
	float	distance;
	float	x;
	float	y;
	float	dst;
	int		visibSp;
	int		offX;
	int		offY;
}				t_sprite;

typedef struct s_mem
{
	struct s_mem	*next;
	void			*mem;
}				t_mem;

typedef struct s_spr
{
	float	spHeight;
	float	spWidth;
	float	distProjPlan;
	float	spTpY;
	float	spBtY;
	float	spriteAngle;
	float	spritePosX;
	float	spriteLeftX;
	float	spriteRightX;
	float	perdistance;
	int		x;
	int		y;
}				t_spr;

typedef struct s_struct
{
	t_player		g_player;
	t_data			img;
	t_data			nt;
	t_data			st;
	t_data			et;
	t_data			wt;
	t_data			sp;
	t_cls_player	move_player;
	t_config_map	map_conf;
	t_wall_struct	wall;
	t_txt_data		dtx;
	t_sprite		*vbs;
	t_mem			*memory;
	t_spr			spr;
	float			px1;
	float			px2;
	int				tmp_width;
	int				floor;
	int				ceeling;
	char			*argv;
}			t_struct;

typedef struct s_bmp_header
{
	char			bftype[3];
	unsigned int	bfsize;
	unsigned short	bfreserved1;
	unsigned short	bfreserved2;
	unsigned int	bfoffbits;
	unsigned int	bisize;
	int				biwidth;
	int				biheight;
	unsigned short	biplanes;
	unsigned short	bibitcount;
	unsigned int	bicompression;
	unsigned int	bisizeimage;
	int				bixpermeter;
	int				biypermeter;
	unsigned int	biclrused;
	unsigned int	biclrimportant;
}				t_bmp_file;

#endif
