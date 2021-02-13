#include "header.h"

void draw_square(int x, int y, t_data data, int color)
{
    int i;
    int j;
    int c;
    int d;

    i = TILE_SIZE * x;
    c = i;
    j = TILE_SIZE * y;
    d = j;

    while (j <  d + TILE_SIZE)
    {
        i = c;
        while (i < c + TILE_SIZE)
        {
            my_mlx_pixel_put(&data, i, j, color);
            i++;
        }
        j++;
    }
}



void circle(int x, int y)
{
    int radius;
    float angle;
    int color;
    
    radius = 10;
    angle = 0;
    color = 0x196876;
    while (angle < 2 * M_PI)
    {
        ft_line(angle,radius, color);
         angle += M_PI / 180;
    }
    ft_line(move_player.rotationAngle, 150, 0x662E9B);
}

void draw_map()
{
    int i;
    int j;
    int color;

    img.img     =       mlx_new_image(img.mlx_ptr, map_conf.width, map_conf.height);
    img.addr    =      (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
    //printf("World %s\n", world[1][]);
    // printf("height %d\n",map_conf.numHeight);
    // printf("width %d\n",g_tmp_width);
    
    i = 0;
     while (i < map_conf.numHeight)
     {
         j = 0;
         while (j < g_tmp_width)
         {
            if (world[i][j] != '1')
            {
                color = 0x000000;
				draw_square(j, i, img, color);
            }

            else
			 {
				color = 0x0E3B43;
				draw_square(j, i, img, color);
			 }  
            
            j++;
         }
        i++;
     }
     draw();
}


void draw_player()
{
    int color;
    color = 0x662E9B;
   
    circle(g_player.last_x, g_player.last_y);
    
}

void draw()
{

    ray_cast();
    draw_player();
    mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
}

void ft_line(float angle,int radius, int color)
{
    float nextX;
    float nextY;
    int k;

    k = 0;
    
    while (k < radius)
        { 
            nextX = g_player.x + cos(angle) * k;
            nextY = g_player.y + sin(angle) * k;
            my_mlx_pixel_put(&img, nextX, nextY, color);
            k++;
        }       
}