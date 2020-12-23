#ifndef HEADER_H
# define HEADER_H

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include "getNextLine/get_next_line.h"

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
    int mv_x;
    int mv_y;
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

m_player        g_player;
t_data          img;
cls_player      move_player;



// int height  = 1080;
// int width   = 1920;
int height;
int width;
void my_mlx_pixel_put(t_data *data,  int x,  int y,  int color);
int map[16][30];
void draw();
void draw_square(int x, int y, t_data data, int color);
void draw_circle(int x, int y, t_data data, int color);
void draw_map(int x, int y, t_data data);
int onClickListner(int keycode);
void draw_player();
void movePlayer();
void ft_line(float angle,int radius);
void turnDirect();
void movement();
#endif