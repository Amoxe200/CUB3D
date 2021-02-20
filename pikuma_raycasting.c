#include "header.h"

int			wall_at(float x, float y)
{
	int		index_x;
	int		index_y;

	index_x = x;
	index_y = y;
	if (index_x < 0 || index_x > g_tmp_width * TILE_SIZE ||
		index_y < 0 || index_y > map_conf.numHeight * TILE_SIZE)
		return (1);
	index_x = floor(index_x / TILE_SIZE);
	index_y = floor(index_y / TILE_SIZE);
	if (world[index_y][index_x] == '1')
		return (1);
	return (0);
}

float       distancebetweenpoints(float x1, float y1, float x2, float y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

float       normalized_angle(float angle)
{
	angle = remainder(angle , 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void        cast_ray(float rayAngle, int stripId)
{
    rayAngle = normalized_angle(rayAngle);
    
    int isRayFacingDown = rayAngle > 0 && rayAngle < M_PI;
    int isRayFacingUp = !isRayFacingDown;

    int isRayFacingRight = rayAngle < 0.5 * M_PI || rayAngle > 1.5 * M_PI;
    int isRayFacingLeft = !isRayFacingRight;
    
    float xintercept, yintercept;
    float xstep, ystep;

    ///////////////////////////////////////////
    // HORIZONTAL RAY-GRID INTERSECTION CODE
    ///////////////////////////////////////////
    int foundHorzWallHit = 0;
    float horzWallHitX = 0;
    float horzWallHitY = 0;
    int horzWallContent = 0;

    // Find the y-coordinate of the closest horizontal grid intersection
    yintercept = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
    yintercept += isRayFacingDown ? TILE_SIZE : 0;

    // Find the x-coordinate of the closest horizontal grid intersection
    xintercept = g_player.x + (yintercept - g_player.y) / tan(rayAngle);

    // Calculate the increment xstep and ystep
    ystep = TILE_SIZE;
    ystep *= isRayFacingUp ? -1 : 1;

    xstep = TILE_SIZE / tan(rayAngle);
    xstep *= (isRayFacingLeft && xstep > 0) ? -1 : 1;
    xstep *= (isRayFacingRight && xstep < 0) ? -1 : 1;

    float nextHorzTouchX = xintercept;
    float nextHorzTouchY = yintercept;

    // Increment xstep and ystep until we find a wall
    while (nextHorzTouchX >= 0 && nextHorzTouchX <= (map_conf.width * TILE_SIZE) && nextHorzTouchY >= 0 && nextHorzTouchY <= (map_conf.width * TILE_SIZE)) {
        float xToCheck = nextHorzTouchX;
        float yToCheck = nextHorzTouchY + (isRayFacingUp ? -1 : 0);
        
        if (wall_at(xToCheck, yToCheck)) {
            // found a wall hit
            horzWallHitX = nextHorzTouchX;
            horzWallHitY = nextHorzTouchY;
            horzWallContent = world[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
            foundHorzWallHit = 1;
            break;
        }
        else
        {
            nextHorzTouchX += xstep;
            nextHorzTouchY += ystep;
        }
    }
    
    ///////////////////////////////////////////
    // VERTICAL RAY-GRID INTERSECTION CODE
    ///////////////////////////////////////////
    int foundVertWallHit = 0;
    float vertWallHitX = 0;
    float vertWallHitY = 0;
    int vertWallContent = 0;

    // Find the x-coordinate of the closest horizontal grid intersection
    xintercept = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
    xintercept += isRayFacingRight ? TILE_SIZE : 0;

    // Find the y-coordinate of the closest horizontal grid intersection
    yintercept = g_player.y + (xintercept - g_player.x) * tan(rayAngle);

    // Calculate the increment xstep and ystep
    xstep = TILE_SIZE;
    xstep *= isRayFacingLeft ? -1 : 1;

    ystep = TILE_SIZE * tan(rayAngle);
    ystep *= (isRayFacingUp && ystep > 0) ? -1 : 1;
    ystep *= (isRayFacingDown && ystep < 0) ? -1 : 1;

    float nextVertTouchX = xintercept;
    float nextVertTouchY = yintercept;

    // Increment xstep and ystep until we find a wall
    while (nextVertTouchX >= 0 && nextVertTouchX <= (map_conf.width * TILE_SIZE) && nextVertTouchY >= 0 && nextVertTouchY <= (map_conf.height * TILE_SIZE)) {
        float xToCheck = nextVertTouchX + (isRayFacingLeft ? -1 : 0);
        float yToCheck = nextVertTouchY;
        
        if (wall_at(xToCheck, yToCheck)) {
            // found a wall hit
            vertWallHitX = nextVertTouchX;
            vertWallHitY = nextVertTouchY;
            vertWallContent = world[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
            foundVertWallHit = 1;
            break;
        }
        else
        {
            nextVertTouchX += xstep;
            nextVertTouchY += ystep;
        }
    }
    // Calculate both horizontal and vertical hit distances and choose the smallest one
    float horzHitDistance = foundHorzWallHit
        ? distancebetweenpoints(g_player.x, g_player.y, horzWallHitX, horzWallHitY)
        : INT_MAX;
    float vertHitDistance = foundVertWallHit
        ? distancebetweenpoints(g_player.x, g_player.y, vertWallHitX, vertWallHitY)
        : INT_MAX;

    if (vertHitDistance < horzHitDistance) {
        rays[stripId].distance = vertHitDistance;
        rays[stripId].wallhit_x = vertWallHitX;
        rays[stripId].wallhit_y = vertWallHitY;
        rays[stripId].wallhitcontent = vertWallContent;
        rays[stripId].washit_vertical = 1;
    } else {
        rays[stripId].distance = horzHitDistance;
        rays[stripId].wallhit_x = horzWallHitX;
        rays[stripId].wallhit_y = horzWallHitY;
        rays[stripId].wallhitcontent = horzWallContent;
        rays[stripId].washit_vertical = 0;
    }
    rays[stripId].ray_angle = rayAngle;
    rays[stripId].israyfacing_down = isRayFacingDown;
    rays[stripId].israyfacing_up = isRayFacingUp;
    rays[stripId].israyfacing_left = isRayFacingLeft;
    rays[stripId].israyfacing_right = isRayFacingRight;
}

// void	drw_line(t_player *pl, int x, int y, int color)
// {
//     t_point p0;
// 	int	dx;
// 	int	dy;
// 	float	steps;
// 	float	x_inc;
// 	float	y_inc;
// 	float	i;

//     p0.x = pl->x;
//     p0.y = pl->y;
//     dx = x - p0.x;
//     dy = y - p0.y;
//     steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
//     x_inc = dx / steps;
//     y_inc = dy / steps;
// 	i = -1;
// 	while (++i <= steps - 1)
// 	{
// 		my_mlx_pixel_put(p0.x * SCALE, p0.y * SCALE, color, img.mlx_img);
// 		p0.x += x_inc;
// 		p0.y += y_inc;
// 	}
// }

void        cast_rays()
{
	float		rayAngle;
	int			i;

	rayAngle = move_player.rotationAngle - ((M_PI / 3) / 2);
	i = -1;
	while (++i < map_conf.width)
	{
		cast_ray(rayAngle, i);
        // drw_line(pl, rays[i].wallhit_x, rays[i].wallhit_y, rgb(255,0,0));
		rayAngle += (M_PI / 3) / map_conf.width;
	}
}