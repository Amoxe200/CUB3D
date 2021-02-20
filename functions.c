#include "header.h"

void        my_mlx_pixel_put(t_data *data,  int x,  int y,  int color)
{
    // printf("%d \t %d \n", map_conf.width, map_conf.height);
    if (x < map_conf.width && y < map_conf.height)
        if (x >= 0 && y >= 0)
<<<<<<< HEAD
            data->addr[y * g_tmp_width * TILE_SIZE+ x] = color;
=======
            data->addr[y * map_conf.width+ x] = color;
>>>>>>> fac61a805d4ff0a64423490130c86d23f3b12fa5
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
<<<<<<< HEAD
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
=======
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
>>>>>>> fac61a805d4ff0a64423490130c86d23f3b12fa5
	angle += (angle < 0) ? (2 * M_PI) : 0;
    return (angle);
}
void ray_cast()
{
    // draaw a ray return a normalized ray angle
    int collumnId ;
    float rayAngle;
    int counter;
    int color;
    float smallDist;
     
    collumnId = 0;
<<<<<<< HEAD
    rayAngle = move_player.rotationAngle - (ray_config.fov_angle / 2);
=======
    rayAngle = move_player.rotationAngle - (ray_config.fov_angle / 2.0);
>>>>>>> fac61a805d4ff0a64423490130c86d23f3b12fa5
    ray_config.ray_angle_san = rayAngle;
    counter = 0;
    color = 0xECA72C;

<<<<<<< HEAD
    while (counter < ray_config.num_of_rays)
    {

       
        ray_config.ray_angle_san = angleSanitizer(ray_config.ray_angle_san);

        checkTheHorzIntersection(ray_config.ray_angle_san);

        checkTheVertiInter(ray_config.ray_angle_san);

        smallDist = (track_the_ray.distanceHorz > track_the_ray.distanceVertc) ? track_the_ray.distanceVertc : track_the_ray.distanceHorz;
       draw_ray(ray_config.ray_angle_san, smallDist);
        //draw_line(g_player.x, g_player.y, track_the_ray.distanceHorz, track_the_ray.distanceVertc);
        //render_wall(counter, smallDist);
        ray_config.ray_angle_san +=  ray_config.fov_angle / ray_config.num_of_rays;
        
        counter++;
        collumnId++;
        // printf("%d \n%f \n", ray_config.num_of_rays, ray_config.ray_angle_san);
        // exit(0);
    }
}

void checkTheHorzIntersection(float angle)
{
    float xStep;
    float yStep;
    float xIntersept;
    float yIntersept;

    checkTheDirection(angle);
    
    yIntersept = floor(g_player.y / TILE_SIZE) * TILE_SIZE;

    yIntersept += (track_the_ray.isRayFacingDown == 1) ? TILE_SIZE : -1;

    xIntersept = g_player.x + (yIntersept - g_player.y) / tan(angle);
    
	yStep = TILE_SIZE;
    yStep *= (track_the_ray.isRayFacingUp) ? -1 : 1;
	xStep = TILE_SIZE / tan(angle);
    xStep *= (track_the_ray.isRayFacingLeft && xStep > 0) ? -1 : 1;
    xStep *= ( track_the_ray.isRayFacingRight && xStep < 0) ? -1 : 1;
    //my_mlx_pixel_put(&img, xIntersept, yIntersept, 0xd51b1b);
    checkTheWallHitHorz(xStep, yStep, xIntersept, yIntersept);
}

void checkTheDirection(float angle)
{
    if (angle > 0  && angle < M_PI)
    {
        track_the_ray.isRayFacingDown = 1;
        track_the_ray.isRayFacingUp = 0;
    }   
    else
    {
        track_the_ray.isRayFacingUp    = 1;
        track_the_ray.isRayFacingDown  = 0;
    }
        
    if (angle < 0.5 * M_PI || angle > 1.5 * M_PI)
    {
        track_the_ray.isRayFacingRight = 1;
        track_the_ray.isRayFacingLeft = 0;
    }
    else
    {
        track_the_ray.isRayFacingLeft = 1;
        track_the_ray.isRayFacingRight = 0;
    }
        
}

void checkTheWallHitHorz(float xStep, float yStep, float xIntersept, float yIntersept)
{
    float nextHorzTouchX;
    float nextHorzTouchY;

    nextHorzTouchX = xIntersept;
    nextHorzTouchY = yIntersept;

    while (nextHorzTouchX >= 0 && nextHorzTouchX < g_tmp_width * TILE_SIZE &&
            nextHorzTouchY >= 0 && nextHorzTouchY < map_conf.numHeight * TILE_SIZE)
    {
          if (world[(int)(nextHorzTouchY/ TILE_SIZE)][(int)(nextHorzTouchX / TILE_SIZE)] == '1')
                    {

                        track_the_ray.wallHitXHorz = nextHorzTouchX;
                        track_the_ray.wallHitYHorz = nextHorzTouchY;
                        track_the_ray.distanceHorz = sqrt(pow((track_the_ray.wallHitXHorz - g_player.x), 2) + pow((track_the_ray.wallHitYHorz - g_player.y), 2));
                        my_mlx_pixel_put(&img, nextHorzTouchX, nextHorzTouchY, 0xd51b1b);
                        break;
                    }
                else 
                {
                        nextHorzTouchX += xStep;
                        nextHorzTouchY += yStep;
                }
    }
}

=======
    
    while (counter < ray_config.num_of_rays)
    {

        ray_config.ray_angle_san = angleSanitizer(ray_config.ray_angle_san);
        checkTheHorzIntersection(ray_config.ray_angle_san);
        checkTheVertiInter(ray_config.ray_angle_san);
        smallDist = (track_the_ray.distanceHorz > track_the_ray.distanceVertc) ? track_the_ray.distanceVertc : track_the_ray.distanceHorz;
        draw_ray(ray_config.ray_angle_san, smallDist);
        ray_config.ray_angle_san +=  ray_config.fov_angle / (float)ray_config.num_of_rays;
        counter++;
        collumnId++;
    }
}

void checkTheHorzIntersection(float angle)
{
    float xStep;
    float yStep;
    float xIntersept;
    float yIntersept;

    checkTheDirection(angle);
    if (track_the_ray.isRayFacingUp)
        yIntersept = (floor(g_player.y / (float) TILE_SIZE) * (float) TILE_SIZE) - 1;
    else if (track_the_ray.isRayFacingDown)
        yIntersept = (floor(g_player.y / (float) TILE_SIZE) * (float) TILE_SIZE) + 64;
    xIntersept = g_player.x + (g_player.y - yIntersept) / tan(angle);
    yStep = (track_the_ray.isRayFacingUp) ? (TILE_SIZE * -1) : TILE_SIZE;
    xStep = (float) TILE_SIZE / tan(angle);
    checkTheWallHitHorz(xStep, yStep, xIntersept, yIntersept);
}

void checkTheDirection(float angle)
{
    if (angle > 0  && angle < M_PI)
    {
        track_the_ray.isRayFacingDown = 1;
        track_the_ray.isRayFacingUp = 0;
    }   
    else
    {
        track_the_ray.isRayFacingUp    = 1;
        track_the_ray.isRayFacingDown  = 0;
    }
        
    if (angle < 0.5 * M_PI || angle > 1.5 * M_PI)
    {
        track_the_ray.isRayFacingRight = 1;
        track_the_ray.isRayFacingLeft = 0;
    }
    else
    {
        track_the_ray.isRayFacingLeft = 1;
        track_the_ray.isRayFacingRight = 0;
    }
        
}

void checkTheWallHitHorz(float xStep, float yStep, float xIntersept, float yIntersept)
{
    float nextHorzTouchX;
    float nextHorzTouchY;

    nextHorzTouchX = xIntersept;
    nextHorzTouchY = yIntersept;
    // printf("width %d\n\n", g_tmp_width);
    // printf("height %d\n", map_conf.numHeight);
    while (1)
    {
        if (nextHorzTouchX >= 0 && nextHorzTouchX < g_tmp_width * TILE_SIZE &&
            nextHorzTouchY >= 0 && nextHorzTouchY < map_conf.numHeight * TILE_SIZE)
            {
                 //printf("width %d \t map_conf.numHeight %d \n", g_tmp_width, map_conf.numHeight);
                //printf("horzX -----> %d\t horzy ------> %d \n", (int)(nextHorzTouchX / TILE_SIZE), (int)(nextHorzTouchY / TILE_SIZE));
                if (world[(int)(nextHorzTouchY/ TILE_SIZE)][(int)(nextHorzTouchX / TILE_SIZE)] == '1')
                    {

                        track_the_ray.wallHitXHorz = nextHorzTouchX;
                        track_the_ray.wallHitYHorz = nextHorzTouchY;
                        //my_mlx_pixel_put(&img, track_the_ray.wallHitXHorz, track_the_ray.wallHitYHorz, 0xd51b1b);
                        track_the_ray.distanceHorz = sqrt(pow((g_player.x - track_the_ray.wallHitXHorz), 2) + pow((g_player.y - track_the_ray.wallHitYHorz), 2));
                        break;
                    }
                else
                {
                        nextHorzTouchY += yStep;
                        nextHorzTouchX += xStep;
                }   
            }
            else
               break;
    }
}
>>>>>>> fac61a805d4ff0a64423490130c86d23f3b12fa5

void draw_ray(float angle, float smallDist) 
{
    float nextX;
    float nextY;
    int k;
    int color;

    k = 0;
    color = 0xECA72C;
    
<<<<<<< HEAD
    while (k <= smallDist)
    {
        nextX = g_player.x + (cos(angle) * k);
        nextY = g_player.y + (sin(angle) * k);
=======
    while (k < smallDist)
    {
        nextX = g_player.x + cos(angle) * k;
        nextY = g_player.y + sin(angle) * k;
>>>>>>> fac61a805d4ff0a64423490130c86d23f3b12fa5
        my_mlx_pixel_put(&img, nextX, nextY, color);
        k++;
    }
}

<<<<<<< HEAD
void draw_line(float xp, float yp, float xIntersept, float yIntersept)
{
    float nextX;
    float nextY;
    int i;
    float steps;
    float xInc;
    float yInc;
    float xfp;
    float yfp;
    int color;

    color = 0xECA72C;
    nextX = xIntersept - xp;
    nextY = yIntersept - yp;
    xfp = xp;
    yfp = yp;
    i = 0;
    steps = fabs(nextX) > fabs(nextY) ? fabs(nextX) : fabs(nextY);
    xInc = nextX / steps;
    yInc = nextY / steps;

    while (i < steps)
    {
        my_mlx_pixel_put(&img, xfp, yfp, color);
        xfp += xInc;
        yfp += yInc;
        i++;
    }
    
}
=======
>>>>>>> fac61a805d4ff0a64423490130c86d23f3b12fa5
void checkTheVertiInter(float angle)
{
    float xStep;
    float yStep;
    float xIntersept;
    float yIntersept;

    checkTheDirection(angle);
<<<<<<< HEAD
    xIntersept = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
    xIntersept += (track_the_ray.isRayFacingRight == 1) ? TILE_SIZE : -1;
    yIntersept = g_player.y + (xIntersept - g_player.x) * tan(angle);
    xStep = TILE_SIZE; 
    xStep *= (track_the_ray.isRayFacingLeft) ? -1 : 1;
    yStep = TILE_SIZE * tan(angle);
    yStep *= (track_the_ray.isRayFacingUp && yStep > 0) ? -1 : 1;
    yStep *= (track_the_ray.isRayFacingDown && yStep < 0) ? -1 : 1;
    my_mlx_pixel_put(&img, xIntersept, yIntersept, 0xd51b1b);
    checkTheWallHitVert(xStep, yStep, xIntersept, yIntersept);
=======
    if (track_the_ray.isRayFacingRight)
        xIntersept = (floor(g_player.x / (float) TILE_SIZE) * (float)TILE_SIZE) + TILE_SIZE;
    else if (track_the_ray.isRayFacingLeft)
        xIntersept = (floor(g_player.x / (float)TILE_SIZE) * (float)TILE_SIZE) - 1;
    yIntersept = g_player.y + (g_player.x - xIntersept) * tan(angle);
    xStep = (track_the_ray.isRayFacingRight) ? TILE_SIZE : (TILE_SIZE * -1);
    yStep = TILE_SIZE * tan(angle);
    checkTheWallHitVert(xStep, yStep, xIntersept, yIntersept);
  
>>>>>>> fac61a805d4ff0a64423490130c86d23f3b12fa5
}

void checkTheWallHitVert(float xStep, float yStep, float xIntersept, float yIntersept)
 {
<<<<<<< HEAD
    float nextVertTouchX;
    float nextVertTouchY;

        nextVertTouchX = xIntersept;
        nextVertTouchY = yIntersept;
    
    while (nextVertTouchX >= 0 && nextVertTouchX < g_tmp_width * TILE_SIZE &&
        nextVertTouchY >= 0 && nextVertTouchY < map_conf.numHeight * TILE_SIZE)
        {

=======
     float nextVertTouchX;
    float nextVertTouchY;

    nextVertTouchX = xIntersept;
    nextVertTouchY = yIntersept;
    while (1)
    {

    if (nextVertTouchX > 0 && nextVertTouchX < g_tmp_width * TILE_SIZE &&
        nextVertTouchY > 0 && nextVertTouchY < map_conf.numHeight * TILE_SIZE)
        {
>>>>>>> fac61a805d4ff0a64423490130c86d23f3b12fa5
            if (world[(int)(nextVertTouchY/ TILE_SIZE)][(int)(nextVertTouchX / TILE_SIZE)] == '1')
                {
                    track_the_ray.wallHitXVert = nextVertTouchX;
                    track_the_ray.wallHitYVert = nextVertTouchY;
                    my_mlx_pixel_put(&img, track_the_ray.wallHitXVert, track_the_ray.wallHitYVert, 0xd51b1b);
<<<<<<< HEAD
                    track_the_ray.distanceVertc = sqrt(pow((track_the_ray.wallHitXVert - g_player.x), 2) + pow((track_the_ray.wallHitYVert - g_player.y), 2));
                    break;
                }
            else 
            {
                    nextVertTouchX += xStep;
                    nextVertTouchY += yStep;
                    my_mlx_pixel_put(&img, nextVertTouchX , nextVertTouchY, 0xd51b1b);
             }
        }
 }

/*void render_wall(int counter, float smallDist)
{

    int		px;
	int		walltop_px;
	int		wallbottom_px;


    px = -1;
     g_wall.perpdistance = smallDist *
    cos(ray_config.ray_angle_san - move_player.rotationAngle);
    g_wall.distanceprojplane = (map_conf.width / 2) / tan((60 * (M_PI / 180)) / 2);
    g_wall.projectedwallheight = (TILE_SIZE / g_wall.perpdistance) *
    g_wall.distanceprojplane;
        g_wall.wallstripheight = (int)g_wall.projectedwallheight;
    
        walltop_px = (map_conf.height / 2) - (g_wall.wallstripheight / 2);
		walltop_px = walltop_px < 0 ? 0 : walltop_px;
		wallbottom_px = (map_conf.height / 2) + (g_wall.wallstripheight / 2);
		wallbottom_px = wallbottom_px > map_conf.height
			? map_conf.height : wallbottom_px;
		px = -1;
		while (++px < 1080)
		{
			if (px < walltop_px)
				my_mlx_pixel_put(&img, counter, px, 0x414361);
			else if (px >= walltop_px && px < wallbottom_px)
				my_mlx_pixel_put(&img, counter, px, 0xF15025);
				
			else if (px >= wallbottom_px)
				my_mlx_pixel_put(&img, counter, px, 0xA7ABC8);

		}

}*/
=======
                    track_the_ray.distanceVertc = sqrt(pow((g_player.x - track_the_ray.wallHitXVert), 2) + pow((g_player.y - track_the_ray.wallHitYVert), 2));
                    break;
                }
            else
            {
                    nextVertTouchY += yStep;
                    nextVertTouchX += xStep;
            }   
        }
        else
            break;
    }
 }
>>>>>>> fac61a805d4ff0a64423490130c86d23f3b12fa5
