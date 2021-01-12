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


#define     UP_DIR 13
#define     DOWN_DIR 1
#define     LEFT_ARROW 123
#define     RIGHT_ARROW 124
#define     RIGHT_DIR 2
#define     LEFT_DIR 0


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


m_player        g_player;
t_data          img;
cls_player      move_player;
config_map      map_conf;

int g_tmp_width;


// int height  = 1080;
// int width   = 1920;

void my_mlx_pixel_put(t_data *data,  int x,  int y,  int color);
int map[16][30];
char **world;
void draw();
void draw_square(int x, int y, t_data data, int color);
void draw_circle(int x, int y, t_data data, int color);
void draw_map();
int onClickListner(int keycode);
void draw_player();
void movePlayer();
void ft_line(float angle,int radius);
void turnDirect();
void movement();
void checkWall();
void store_data(char *line, int i);
char *fill_textures(char *texture, char *line, int i);
void fill_floor(char *line, int i);
void fill_ceilling(char *line, int i);
void creatingMap(char *line, int i);
void ft_field(float angle, int radius);
size_t count_line_skip_space(const char *str);
#endif