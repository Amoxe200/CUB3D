#ifndef HEADER_H
# define HEADER_H

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <fcntl.h>
#include "getNextLine/get_next_line.h"
#include "libft/libft.h"
# include <limits.h>


#define     UP_DIR 13
#define     DOWN_DIR 1
#define     LEFT_ARROW 123
#define     RIGHT_ARROW 124
#define     RIGHT_DIR 2
#define     ECHAP 53
#define     LEFT_DIR 0
#define     TILE_SIZE 64
#define     NUM_RAYS
#define		nms 0.2
#define		FOV (60 * (M_PI / 180))
#define		EPSILON 0.2

typedef struct  s_data
{
	void    *img;
	int     *addr;
	void    *mlx_ptr;
	void    *win_ptr;
	int     bits_per_pixel;
	int     line_lenght;
	int     endian;
}               t_data;

typedef struct s_player
{
	float	x;
	float	y;
	int		last_x;
	int		last_y;

}               m_player;

typedef struct mv_player
{
	int		x;
	int		y;
	int		radius;
	int		turnDirection;
	int		walkDirection;
	float	rotationAngle;
	float	moveSpeed;
	float	rotationSpeed;
}               cls_player;

typedef struct map_config
{
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
	char	**data;
	char	*wlrd;
	char	*north_texture;
	char	*west_texture;
	char	*east_texture;
	char	*south_texture;
	char	*sprite_texture;
	char	*sprite;
	int		indx;
	int		player;
}               config_map;

typedef struct rays
{
	float	horzwallHitX;
	float	horzwallHitY;
	float	vertwallHitX;
	float	vertwallHitY;
	float	wallHitX;
	float	wallHitY;
	float	fv_angle;
	float	distance;
	float	num_rays;
	float	angle_norm;
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
}               ray_struct;

typedef struct walls
{
	float	distProjPlan;
	float	projWallHeight;
	int		wallStrHeight;
	float	wallTpPixel;
	float	wallBtPixel;
	float	perpDistance;

}				wall_struct;


typedef	struct txt
{	
	int		offX;
	int		offY;
	int		dist;
}			txt_data;

typedef struct sp
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


m_player        g_player;
t_data          img;
t_data			nt;
t_data			st;
t_data			et;
t_data			wt;
t_data			sp;
cls_player      move_player;
config_map      map_conf;
wall_struct		wall;
txt_data    	dtx;


int g_tmp_width;
char **world;

void collect_spData(t_sprite *sprite, int indx);
void store_the_spData(int i, int j, t_sprite *sprites, int indx);
void	my_mlx_pixel_put(t_data *data,  int x,  int y,  int color);
void	render();
void	draw_square(int x, int y, t_data data, int color);
void	draw_circle(int x, int y, t_data data, int color);
void	draw_map(t_sprite *sprites);
void 	draw_line(float pX, float pY, float dX, float dY);
int		onClickListner(int keycode);
void	draw_line(float xp, float yp, float xIntersept, float yIntersept);
void	draw_player();
void	movePlayer();
void	ft_line(float angle,int radius, int color);
void	turnDirect();
void	movement();
void	checkWall();
void	store_data(char *line, int i);
char	*fill_textures(char *texture, char *line, int i);
void	fill_floor(char *line, int i);
void	fill_ceilling(char *line, int i);
void	creatingMap(char *line, int i);
size_t	count_line_skip_space(const char *str);
void	ray_cast();
int		reset_player(int key);
void	read_map(void);
void	init_pl(int y, int x);
void	fill_line(char **temp_map, int i);
void	fill_map();
void	castAllRays();
void	draw_ray_line(float rayAngle);
void	init_pl(int y, int x);
double	angleSanitizer(float angle);
void cast(ray_struct *rays, int i);
void checkTheRayDir(ray_struct *rays);
void castAllRays(ray_struct *rays);
void checkHorzInter(ray_struct *rays);
void checkWallHorz(float *xyInter, float xStep, float yStep, ray_struct *rays);
void checkVertInter(ray_struct *rays);
void checkWallVert(float *xyInter, float xStep, float yStep, ray_struct *rays);
double distanceBpoint(float x1, float y1, float x2, float y2);
void calculDistance(ray_struct *rays, int i);
void store_array(ray_struct *rays, int i);
void render_wall(ray_struct *rays, int i);
void render_ray(ray_struct *rays);

void    text_init(void);
int assign_text(int i, ray_struct *rays);
void collect_res(char *line, int i);
void collect_text(char *line, int i);
void check_map(char *line, int i);
void initalize(ray_struct *rays, int i);
void renderSpProj(t_sprite  *sprites, ray_struct *rays);
void renderMapsp( t_sprite *sprites, int i, int j, int indx);
void draw_px(int x, int y, t_data data, int color);
void draw_sprite_in_map(t_sprite *sprite);
void renderSprite(t_sprite *sprite, int vbNumber, t_sprite *visibSprite, ray_struct *rays);
int assigne_sprite(t_sprite sprite, int x, int y, ray_struct *rays);
void sortSprite(t_sprite *sprites, int vbNumber, t_sprite *visibleSprite);

void rounting(char *line, int i);
void get_res(char *line);
int count_tab(char **tab);
int ft_error(char *err);
int keys();
void drawTheMap(int i, int j, t_sprite *sprites);
void lookError(int i, int j);
void checkNum(char *str, char *str2, char *str3);
//intialize variables
/*
img = 0;
addr = 0;
mlx_ptr = 0;
win_ptr = 0;
bits_per_pixel = 0;
line_lenght = 0;
endian = 0;
x = 0;
y = 0;
last_x = 0;
last_y = 0;
x = 0;
y = 0;
radius = 0;
turnDirection = 0;
walkDirection = 0;
rotationAngle = 0;
moveSpeed = 0;
rotationSpeed = 0;
width = 0;
rFloor = 0;
gFloor = 0;
bFloor = 0;
height = 0;
ceilingR = 0;
ceilingG = 0;
ceilingB = 0;
numHeight = 0;
numWidth = 0;
spNumber = 0;
counter = 0;
data = 0;
wlrd = 0;
north_texture = 0;
west_texture = 0;
east_texture = 0;
south_texture = 0;
sprite_texture = 0;
sprite = 0;
horzwallHitX = 0;
horzwallHitY = 0;
vertwallHitX = 0;
vertwallHitY = 0;
wallHitX = 0;
wallHitY = 0;
fv_angle = 0;
distance = 0;
num_rays = 0;
angle_norm = 0;
wall_strWidth = 0;
isRayFacingDown = 0;
isRayFacingUp = 0;
isRayFacingRight = 0;
isRayFacingLeft = 0;
foundHorzWallHit = 0;
foundVertWallHit = 0;
wasHitVertical = 0;
horzWallContent = 0;
vertWallContent = 0;
wallHitContent = 0;
distProjPlan = 0;
projWallHeight = 0;
wallStrHeight = 0;
wallTpPixel = 0;
wallBtPixel = 0;
perpDistance = 0;
offX = 0;
offY = 0;
dist = 0;
x = 0;
y = 0;
dst = 0;
angleSpPlayer = 0;
angle = 0;
distance = 0;
visibSp = 0;
offX = 0;
offY = 0;
*/

int g_floor;
int g_ceeling;
#endif
