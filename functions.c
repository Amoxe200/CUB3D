#include "header.h"

void        my_mlx_pixel_put(t_data *data,  int x,  int y,  int color)
{
    if (x < width && y < height)
    data->addr[y * width + x] = color;
}

int map[16][30] =
{
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1},
        {1,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,1,0,0,0,0,2,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1},
        {1,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        
};

void draw_square(int x, int y, t_data data, int color)
{
    int i;
    int j;
    int c;
    int d;

    i = (width / 30) * x;
    c = i;
    j = (height / 16) * y;
    d = j;

    while (j <  d + (height / 16))
    {
        i = c;
        while (i < c + (width / 30))
        {
            my_mlx_pixel_put(&data, i, j, color);
            i++;
        }
        j++;
    }
}

void draw_circle(int x, int y, t_data data, int color)
{
    int     radius;
    float   angle;
    float   i;
    float   j;

    angle = 0;
    while (angle < 360)
    {
        radius = 0;
        while (radius < 10)
        {
            i = x *  /*g_player.mv_x +*/ radius*cos(angle * (M_PI/180));
            j = y * /*g_player.mv_y + */ radius*sin(angle*  (M_PI/180));
            my_mlx_pixel_put(&data, i, j, 0x662E9B);
            radius++;
        }
        angle++;
    }
    //ft_line(move_player.rotationAngle,radius);
}

void circle(int x, int y)
{
    int radius;
    float angle;
    
    radius = 10;
    angle = 0;

    while (angle < 2 * M_PI)
    {
        ft_line(angle,radius);
         angle += M_PI / 180;
    }
    ft_line(move_player.rotationAngle,50);
}

void draw_map()
{
    int i;
    int j;
    int color;

    img.img     =       mlx_new_image(img.mlx_ptr, width, height);
    img.addr    =      (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
   
     j = 0;
     while (j < 16)
     {
         i = 0;
         while (i < 30)
         {
            
             if (map[j][i] == 1)
			 {
				color = 0xFF0000;
				draw_square(i, j, img, color);
			 }  
            
            else
			{
					color = 0x000000;
					draw_square(i, j, img, color);
			}
			
          /* if (map[j][i] == 2)
             {
                  g_player.x = i * (width / 30);
                  g_player.y = j * (height / 16);
             }*/

            i++;
         }
        j++;
     }
     draw();
}

void    reset(int keycode)
{
   if (keycode == UP_DIR) // w
    {
            move_player.walkDirection = 0;
    }
    else if (keycode == DOWN_DIR) // s
    {
            move_player.walkDirection = 0;
    }
    else if (keycode == RIGHT_ARROW)
    {
            move_player.turnDirection = 0;
    }
    else if (keycode == LEFT_ARROW)
    {
          move_player.turnDirection = 0;
    } 
}
int onClickListner(int keycode)
{

    //printf("%d\n",keycode);
    if (keycode == UP_DIR) // w
    {
            move_player.walkDirection = 1;
    }
    else if (keycode == DOWN_DIR) // s
    {
            move_player.walkDirection = -1;
    }
    else if (keycode == RIGHT_ARROW)
    {
            move_player.turnDirection = 1;
    }
    else if (keycode == LEFT_ARROW)
    {
          move_player.turnDirection = -1;
    }
    
    movement();
    mlx_destroy_image(img.mlx_ptr, img.img);
    draw_map();
    reset(keycode);
        return 0;
}

void draw_player()
{
    int color;
    color = 0x662E9B;
   
    circle(g_player.last_x, g_player.last_y);
    
}
void draw()
{

    printf("2 = %f\n", g_player.y);
    draw_player();
    mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
}

void ft_line(float angle,int radius)
{
    float nextX;
    float nextY;
    int k;
    //g_player.x *= width  / 30;
   // g_player.y *= height / 16;

    k = 0;
    while (k < radius)
        { 
            nextX = g_player.x + cos(angle) * k;
            nextY = g_player.y + sin(angle) * k;
            my_mlx_pixel_put(&img, nextX, nextY, 0x662E9B);
            k++;
        }
}

void movement()
{
    float moveSteps;
    float nextX;
    float nextY;
    nextY =  g_player.y;
    nextX = g_player.x;
    
    move_player.rotationAngle += move_player.turnDirection * move_player.rotationSpeed;
    moveSteps = move_player.walkDirection * move_player.moveSpeed;
   
    g_player.x = nextX + (cos(move_player.rotationAngle) * moveSteps);
    g_player.y = nextY + (sin(move_player.rotationAngle) * moveSteps);


}
