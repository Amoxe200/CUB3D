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

typedef struct ray_param
{
   float fov_angle;
   float wall_strip_width;
   float num_of_rays;
   float ray_angle_san;
    char **flt_map;
}               ray_conf;

// typedef struct ray_param
// {
//     float rayAngle;
//     float wallHitX;
//     float wallHitY;
//     float distance;
//     int wasHitVertical;
//     int isRayFacingUp;
//     int isRayFacingDown;
//     int isRayFacingLeft;
//     int isRayFacingRight;
//     int wallHitContent;
// }               ray_conf;

typedef struct ray_track
{
    float wallHitXHorz;
    float wallHitYHorz;
    float wallHitXVert;
    float wallHitYVert;
    float distanceHorz;
    float distanceVertc;
    int isRayFacingDown;
    int isRayFacingUp;
    int isRayFacingLeft;
    int isRayFacingRight;

}               track_ray;

typedef struct s_rays
{
	float		ray_angle;
	float		wallhit_x;
	float		wallhit_y;
	float		distance;
	int			washit_vertical;
	int			washit_horizontal;
	int			israyfacing_up;
	int			israyfacing_down;
	int			israyfacing_left;
	int			israyfacing_right;
	int			wallhitcontent;
	float		horzhitdistance;
	float		verthitdistance;
}               t_rays;

typedef struct	s_walls
{
	float		perpdistance;
	float		distanceprojplane;
	float		projectedwallheight;
	int			wallstripheight;
}				t_walls;

t_rays            *rays;
m_player        g_player;
t_walls         g_wall;
t_data          img;
cls_player      move_player;
config_map      map_conf;
ray_conf        ray_config;
track_ray       track_the_ray;

int g_tmp_width;


// int height  = 1080;
// int width   = 1920;

void my_mlx_pixel_put(t_data *data,  int x,  int y,  int color);
char **world;
void draw();
void draw_square(int x, int y, t_data data, int color);
void draw_circle(int x, int y, t_data data, int color);
void draw_map();
int onClickListner(int keycode);
void draw_line(float xp, float yp, float xIntersept, float yIntersept);
void draw_player();
void movePlayer();
void ft_line(float angle,int radius, int color);
void turnDirect();
void movement();
void checkWall();
void store_data(char *line, int i);
char *fill_textures(char *texture, char *line, int i);
void fill_floor(char *line, int i);
void fill_ceilling(char *line, int i);
void creatingMap(char *line, int i);
size_t count_line_skip_space(const char *str);
void ray_cast();
void read_map(void);
void init_pl(int y, int x);
void fill_line(char **temp_map, int i);
void    fill_map();
void init_pl(int y, int x);
double angleSanitizer(float angle);
void checkTheHorzIntersection(float angle);
void checkTheDirection(float angle);
void checkDirectionIncrementSteps(float xStep, float yStep, float xIntersept, float yInterspet);
void checkTheWallHitHorz(float xStep, float yStep, float xIntersept, float yIntersept);
void draw_ray(float angle, float smallDist);
void checkTheVertiInter(float angle);
void checkTheWallHitVert(float xStep, float yStep, float xIntersept, float yIntersept);
void        cast_rays();
int			wall_at(float x, float y);
void render_wall(int counter, float smallDist);
#endif
