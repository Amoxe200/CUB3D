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
	float x;
	float y;
	int last_x;
	int last_y;

}               m_player;

typedef struct mv_player
{
	int x;
	int y;
	int radius;
	int turnDirection;
	int walkDirection;
	float rotationAngle;
	float moveSpeed;
	float rotationSpeed;  
}               cls_player;

typedef struct map_config
{
	char **data;
	int height;
	char *wlrd;
	int width;
	int rFloor;
	int gFloor;
	int bFloor;
	char *north_texture;
	char *west_texture;
	char *east_texture;
	char *south_texture;
	char *sprite_texture;
	int ceilingR;
	int ceilingG;
	int ceilingB;
	int numHeight;
	int numWidth;
   
}               config_map;

typedef struct rays
{
	int wall_strWidth;
	float horzwallHitX;
	float horzwallHitY;
	float vertwallHitX;
	float vertwallHitY;
	int isRayFacingDown;
	int isRayFacingUp;
	int isRayFacingRight;
	int isRayFacingLeft;
	int foundHorzWallHit;
	int foundVertWallHit;
	int wasHitVertical;
	int horzWallContent;
	int vertWallContent;
	float wallHitX;
	float wallHitY;
	float fv_angle;
	float distance;
	float num_rays;
	float angle_norm;
}               ray_struct;


m_player        g_player;
t_data          img;
cls_player      move_player;
config_map      map_conf;


int g_tmp_width;


// int height  = 1080;
// int width   = 1920;
char **world;

void	my_mlx_pixel_put(t_data *data,  int x,  int y,  int color);
void	render();
void	draw_square(int x, int y, t_data data, int color);
void	draw_circle(int x, int y, t_data data, int color);
void	draw_map();
void draw_line(float pX, float pY, float dX, float dY);
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
void cast(ray_struct *rays);
void checkTheRayDir(ray_struct *rays);
void castAllRays(ray_struct *rays);
void checkHorzInter(ray_struct *rays);
void checkWallHorz(float *xyInter, float xStep, float yStep, ray_struct *rays);
void checkVertInter(ray_struct *rays);
void checkWallVert(float *xyInter, float xStep, float yStep, ray_struct *rays);
double distanceBpoint(float x1, float y1, float x2, float y2);
void calculDistance(ray_struct *rays);
void initialize(ray_struct *rays);
#endif
