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
            my_mlx_pixel_put(&data, i * nms, j * nms, color);
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
        ft_line(angle ,radius, color);
         angle += M_PI / 180;
    }
    ft_line(move_player.rotationAngle, 150, 0x662E9B);
}

void draw_map()
{
    int i;
    int j;
    int color;

   
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
                color = 0x605F5E;
				draw_square(j , i, img, color);
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
}


void draw_player()
{
    int color;
    color = 0x662E9B;
   
    circle(g_player.last_x, g_player.last_y);
    
}

// void render_rays(ray_struct *rays)
// {
//     int i;

//     i = 0;
//     while (i < map_conf.width - 1)
//     {
//         //printf("rays->wallhitx = %f\n", rays[i].wallHitX);
//         //printf("rays->wallhity = %f\n", rays[i].wallHitY);
        
//         i++;
//     }
// }
void render_ray(ray_struct *rays)
{
    int i;
     i = 0; 

     while ( i < rays -> num_rays)
     {
         draw_line(g_player.x * nms, g_player.y * nms, rays[i].wallHitX * nms, rays[i].wallHitY * nms);
         i++;
     }
}
void render()
{
    int a;
    ray_struct rays[g_tmp_width * TILE_SIZE];

    mlx_destroy_image(img.mlx_ptr, img.img);
    img.img     =       mlx_new_image(img.mlx_ptr, map_conf.width, map_conf.height);
    img.addr    =      (int *)mlx_get_data_addr(img.img, &a, &a, &a);
    castAllRays(rays);
    render_wall(rays);
    draw_map();
    draw_player();
    render_ray(rays);
    mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
}

void ft_line(float angle,int radius, int color)
{
    float nextX;
    float nextY;
    int k;

    k = 0;
    nextX = 0;
    nextY = 0;
    
    while (k < radius)
        { 
            nextX = g_player.x + cos(angle) * k;
            nextY = g_player.y + sin(angle) * k;
           
            my_mlx_pixel_put(&img, nextX * nms, nextY * nms, color);
            k++;
        }       
}

// void draw_line(float pX, float pY, float dX, float dY)
// {
//     float nextX;
//     float nextY;
//     float steps;
//     float xInc;
//     float yInc;
//     float x;
//     float y;
//     int i;

//     nextX = dX - pX;
//     nextY = dY - pY;
//     steps = fabs(nextX) > fabs(nextY) ? fabs(nextX) : fabs(nextY);
//     xInc = nextX / steps;
//     yInc = nextY / steps;
//     x = pX;
//     y = pY;
//     i = 0;

//     while (i < steps)
//     {
//         my_mlx_pixel_put(&img, round(x), round(y), 0xCE4760);
//         x += xInc;
//         y += yInc;
//         i++;
//     }
// }

void	draw_line(float pX, float pY, float dX, float dY)
{
	int		dx;
	int		dy;
	float	steps;
	float	x_inc;
	float	y_inc;

	dx = dX - pX;
	dy = dY - pY;
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	x_inc = dx / steps;
	y_inc = dy / steps;
	while (steps--)
	{
		my_mlx_pixel_put(&img, pX, pY, 0xCE4760);
		pX += x_inc;
		pY += y_inc;
	}
}