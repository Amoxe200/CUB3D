#include "header.h"

void        my_mlx_pixel_put(t_data *data,  int x,  int y,  int color)
{
    if (x < map_conf.width && y < map_conf.height)
        if (x >= 0 && y >= 0)
            data->addr[y * map_conf.width + x] = color;
}

// int map[map_conf.numHeight][g_tmp_width] =
// {
//         {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//         {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//         {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//         {1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1},
//         {1,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1},
//         {1,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1},
//         {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1},
//         {1,0,0,0,0,1,0,0,1,0,0,0,0,2,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1},
//         {1,0,0,0,0,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//         {1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1},
//         {1,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,1},
//         {1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1},
//         {1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1},
//         {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//         {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//         {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        
// };

void draw_square(int x, int y, t_data data, int color)
{
    int i;
    int j;
    int c;
    int d;

    i = (map_conf.width / g_tmp_width) * x;
    c = i;
    j = (map_conf.height / map_conf.numHeight) * y;
    d = j;

    while (j <  d + (map_conf.height / map_conf.numHeight))
    {
        i = c;
        while (i < c + (map_conf.width / g_tmp_width))
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
    ft_field(move_player.rotationAngle,150);
}

void draw_map()
{
    int i;
    int j;
    int color;

    img.img     =       mlx_new_image(img.mlx_ptr, map_conf.width, map_conf.height);
    img.addr    =      (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
   
     j = 0;
     
    // while (j < map_conf.numHeight)
    //     printf("|%s|\n", world[j++]);


     while (j < map_conf.numHeight)
     {
         i = 0;
         while (i < g_tmp_width)
         {

            if (i >= ft_strlen(world[j]) || world[j][i] != '1')
            {
                color = 0x000000;
				draw_square(i, j, img, color);
            }

            else
			 {
				color = 0xFF0000;
				draw_square(i, j, img, color);
			 }  
            
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

    draw_player();
    mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
}

void ft_line(float angle,int radius)
{
    float nextX;
    float nextY;
    int k;

    k = 0;
    while (k < radius)
        { 
            nextX = g_player.x + cos(angle) * k;
            nextY = g_player.y + sin(angle) * k;
            my_mlx_pixel_put(&img, nextX, nextY, 0x662E9B);
            k++;
        }
}

void ft_field(float angle, int radius)
{
    double A = angle - (M_PI/6);
    double add = (M_PI/3)/map_conf.width;
    while (A < angle + (M_PI/6))
    {
        ft_line(A, radius);
        A += add;
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
   
    if (world[(int)(nextY + (sin(move_player.rotationAngle) * moveSteps)) / (map_conf.height / map_conf.numHeight)][(int)(nextX + (cos(move_player.rotationAngle) * moveSteps)) / (map_conf.width / g_tmp_width)] != '1')
    {
        g_player.x = nextX + (cos(move_player.rotationAngle) * moveSteps);
        g_player.y = nextY + (sin(move_player.rotationAngle) * moveSteps);
    }
}

void store_data(char *line, int i)
{
    int     c;
    
    c = 0;
    if (line[i] != '\0' && line[i] == 'R')
        {
            // printf("%s========>\n", line);
             map_conf.data = ft_split(line + i, ' ');
             map_conf.width = ft_atoi(map_conf.data[1]);
             map_conf.height  = ft_atoi(map_conf.data[2]);  
        }

    if (line[i] != '\0' && line[i] == 'N' && line [i + 1] == 'O')
            // printf("%s|-------|\n", fill_textures(map_conf.north_texture, line, i));
        fill_textures(map_conf.north_texture, line, i);
    if (line[i] != '\0' && line[i] == 'S' && line [i + 1] == 'O')
            // printf("%s|-------|\n", fill_textures(map_conf.south_texture, line, i));
        fill_textures(map_conf.south_texture, line, i);
    if (line[i] != '\0' && line[i] == 'W' && line [i + 1] == 'E')
            // printf("%s|-------|\n", fill_textures(map_conf.west_texture, line, i));     
        fill_textures(map_conf.west_texture, line, i);    
    if (line[i] != '\0' && line[i] == 'E' && line [i + 1] == 'A')
            // printf("%s|-------|\n", fill_textures(map_conf.east_texture, line, i));
        fill_textures(map_conf.east_texture, line, i);
    if (line[i] != '\0' && line[i] == 'F')
            fill_floor(line, i);
    if (line[i] != '\0' && line[i] == 'C')
            fill_ceilling(line, i);
    if (line[i] != '\0' && line[i] == '1')
    {       
        while(line[i] == ' ')
            i++;
        creatingMap(line, i);
    }
  
   
}

char  *fill_textures(char *texture, char *line, int i)
{
     i += 2;
        while (line[i] == ' ')
            i++;
    texture = ft_strdup_(line + i);
    return (texture);
}

void fill_floor(char *line, int i)
{
    i +=2;
        while (line[i] == ' ')
            i++;
    map_conf.data   = ft_split(line + i, ',');
    map_conf.rFloor = ft_atoi(map_conf.data[0]);
    map_conf.gFloor = ft_atoi(map_conf.data[1]);
    map_conf.bFloor = ft_atoi(map_conf.data[2]);
}

void fill_ceilling(char *line, int i)
{
    i +=2;
        while (line[i] == ' ')
            i++;
    map_conf.data     = ft_split(line + i, ',');
    map_conf.ceilingR = ft_atoi(map_conf.data[0]);
    map_conf.ceilingG = ft_atoi(map_conf.data[1]);
    map_conf.ceilingB = ft_atoi(map_conf.data[2]);
    
}

void creatingMap(char *line, int i)
{
    int save = ft_strlen(line);

    if (save > g_tmp_width)
        g_tmp_width = save;

    map_conf.wlrd = ft_strjoin_(map_conf.wlrd, line);
    // map_conf.wlrd = ft_strdup(line);
    // printf("line = %s\n", line);
    map_conf.wlrd = ft_strjoin_(map_conf.wlrd, "\n");
    map_conf.numHeight++;
}

