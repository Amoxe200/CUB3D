#include "header.h"

void        my_mlx_pixel_put(t_data *data,  int x,  int y,  int color)
{
    // printf("%d \t %d \n", map_conf.width, map_conf.height);
    if (x < map_conf.width && y < map_conf.height)
        if (x >= 0 && y >= 0)
            data->addr[y * map_conf.width+ x] = color;
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

    if (keycode == UP_DIR) // w
            move_player.walkDirection = 1;
    else if (keycode == DOWN_DIR) // s
            move_player.walkDirection = -1;
    else if (keycode == RIGHT_ARROW)
            move_player.turnDirection = 1;
    else if (keycode == LEFT_ARROW)
          move_player.turnDirection = -1;
    else if (keycode ==  ECHAP)
    {
        exit(1);
	        return (0);
    }

    movement();
    mlx_destroy_image(img.mlx_ptr, img.img);
    draw_map();
    reset(keycode);
        return 0;
}



void movement()
{
    float moveSteps;
    float nextX;
    float nextY;
    nextY =  g_player.y;
    nextX = g_player.x;
    
    move_player.rotationAngle += move_player.turnDirection * move_player.rotationSpeed;
    move_player.rotationAngle = angleSanitizer(move_player.rotationAngle);
    moveSteps = move_player.walkDirection * move_player.moveSpeed;
   
    if (world[(int)(nextY + (sin(move_player.rotationAngle) * moveSteps)) / TILE_SIZE][(int)(nextX + (cos(move_player.rotationAngle) * moveSteps)) / TILE_SIZE] != '1')
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
        fill_textures(map_conf.north_texture, line, i);
    if (line[i] != '\0' && line[i] == 'S' && line [i + 1] == 'O')
        fill_textures(map_conf.south_texture, line, i);
    if (line[i] != '\0' && line[i] == 'W' && line [i + 1] == 'E')
        fill_textures(map_conf.west_texture, line, i);    
    if (line[i] != '\0' && line[i] == 'E' && line [i + 1] == 'A')
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
    char *tmp;
    if (save > g_tmp_width)
        g_tmp_width = save;
    //printf("%d", g_tmp_width);
    tmp = map_conf.wlrd;
    map_conf.wlrd = ft_strjoin_(map_conf.wlrd, line);
    tmp = map_conf.wlrd;
    map_conf.wlrd = ft_strjoin_(map_conf.wlrd, "\n");
    map_conf.numHeight++;
}

void read_map(void)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (world[i])
    {
        j = 0;
        while (world[i][j])
        {
            if (ft_strchr("NSEW", world[i][j]))
            {
                init_pl(i, j);
                break;
            }
            j++;
        }
        i++;
    }
}

void init_pl(int y, int x)
{
    g_player.x = x * TILE_SIZE + (TILE_SIZE / 2);
    g_player.y = y * TILE_SIZE + (TILE_SIZE / 2);
}
double angleSanitizer(float angle)
{
   angle = fmod(angle, (2 * M_PI));
	angle += (angle < 0) ? (2 * M_PI) : 0;
    return (angle);
}