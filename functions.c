#include "header.h"

double angleSanitizer(float angle)
{
    angle = remainder(angle, 2 * M_PI);
    if (angle < 0)
        angle += 2 * M_PI;
    if (angle > 2 * M_PI)
        angle -= 2 * M_PI;
    return (angle);
}

void checkWallHorz(float *xyInter, float xStep, float yStep, ray_struct *rays)
{
    float nextHorzTouchX;
    float nextHorzTouchY;

    nextHorzTouchX = xyInter[0];
    nextHorzTouchY = xyInter[1];
    rays->foundHorzWallHit = 0;
    rays->horzwallHitX = 0;
    rays->horzwallHitY = 0;

    while (nextHorzTouchX > 0 && nextHorzTouchX < g_tmp_width * TILE_SIZE &&
           nextHorzTouchY > 0 && nextHorzTouchY < map_conf.numHeight * TILE_SIZE)
    {
        float xToCheck;
        float yToCheck;

        xToCheck = nextHorzTouchX;
        yToCheck = nextHorzTouchY + (rays->isRayFacingUp ? -1 : 0);
        if (map_conf.map[(int)(yToCheck / TILE_SIZE)][(int)(xToCheck / TILE_SIZE)] == '1')
        {
            rays->foundHorzWallHit = 1;
            rays->horzWallContent = map_conf.map[(int)(yToCheck / TILE_SIZE)][(int)(xToCheck / TILE_SIZE)];
            rays->horzwallHitX = nextHorzTouchX;
            rays->horzwallHitY = nextHorzTouchY;
            break;
        }
        else
        {
            nextHorzTouchX += xStep;
            nextHorzTouchY += yStep;
        }
    }
}

void checkVertInter(ray_struct *rays)
{
    float xStep;
    float yStep;
    float xInter;
    float yInter;
    float xyInter[2];
    rays->foundVertWallHit = 0;
    rays->vertwallHitX = 0;
    rays->vertwallHitY = 0;

    xInter = floor((g_player.x / TILE_SIZE)) * TILE_SIZE;
    xInter += rays->isRayFacingRight ? TILE_SIZE : 0;
    yInter = g_player.y + (xInter - g_player.x) * tan(rays->angle_norm);
    xStep = TILE_SIZE;
    xStep *= rays->isRayFacingLeft ? -1 : 1;
    yStep = TILE_SIZE * tan(rays->angle_norm);
    yStep *= (rays->isRayFacingUp && yStep > 0) ? -1 : 1;
    yStep *= (rays->isRayFacingDown && yStep < 0) ? -1 : 1;
    xyInter[0] = xInter;
    xyInter[1] = yInter;
    checkWallVert(xyInter, xStep, yStep, rays);
}

void checkWallVert(float *xyInter, float xStep, float yStep, ray_struct *rays)
{
    float nextVertTouchX;
    float nextVertTouchY;

    nextVertTouchX = xyInter[0];
    nextVertTouchY = xyInter[1];

    while (nextVertTouchX > 0 && nextVertTouchX < g_tmp_width * TILE_SIZE &&
           nextVertTouchY > 0 && nextVertTouchY < map_conf.numHeight * TILE_SIZE)
    {
        float ytoCheck;
        float xtoCheck;

        xtoCheck = nextVertTouchX + (rays->isRayFacingLeft ? -1 : 0);
        ytoCheck = nextVertTouchY;
        if (map_conf.map[(int)(ytoCheck / TILE_SIZE)][(int)(xtoCheck / TILE_SIZE)] == '1')
        {
            rays->foundVertWallHit = 1;
            rays->vertWallContent = map_conf.map[(int)(ytoCheck / TILE_SIZE)][(int)(xtoCheck / TILE_SIZE)];
            rays->vertwallHitX = nextVertTouchX;
            rays->vertwallHitY = nextVertTouchY;
            break;
        }
        else
        {
            nextVertTouchX += xStep;
            nextVertTouchY += yStep;
        }
    }
}

void calculDistance(ray_struct *rays, int i)
{
    float horzHitDistance;
    float vertHitDistance;

    horzHitDistance = (rays->foundHorzWallHit) ? distanceBpoint(g_player.x, g_player.y, rays->horzwallHitX, rays->horzwallHitY) : INT_MAX;
    vertHitDistance = (rays->foundVertWallHit) ? distanceBpoint(g_player.x, g_player.y, rays->vertwallHitX, rays->vertwallHitY) : INT_MAX;
    //printf("%f\n", vertHitDistance);
    if (vertHitDistance < horzHitDistance)
    {
        rays[i].distance = vertHitDistance;
        rays[i].wallHitX = rays->vertwallHitX;
        rays[i].wallHitY = rays->vertwallHitY;
        rays[i].wallHitContent = rays->vertWallContent;
        rays[i].wasHitVertical = 1;
    }
    else
    {
        rays[i].distance = horzHitDistance;
        rays[i].wallHitX = rays->horzwallHitX;
        rays[i].wallHitY = rays->horzwallHitY;
        rays[i].wallHitContent = rays->horzWallContent;
        rays[i].wasHitVertical = 0;
    }
    store_array(rays, i);
}

void store_array(ray_struct *rays, int i)
{
    rays[i].angle_norm = rays->angle_norm;
    rays[i].isRayFacingDown = rays->isRayFacingDown;
    rays[i].isRayFacingUp = rays->isRayFacingUp;
    rays[i].isRayFacingLeft = rays->isRayFacingLeft;
    rays[i].isRayFacingRight = rays->isRayFacingRight;
}

double distanceBpoint(float x1, float y1, float x2, float y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void render_wall(ray_struct *rays, int i)
{
    int y;

    y = 0;

    initalize(rays, i);
    while (y < wall.wallTpPixel)
    {
        my_mlx_pixel_put(&img, i, y, g_floor);
        y++;
    }
    y = wall.wallTpPixel;
    while (y < wall.wallBtPixel)
    {
        dtx.dist = y + (wall.wallStrHeight / 2) - (map_conf.height / 2);
        dtx.offY = (int)(dtx.dist * ((float)64 / wall.wallStrHeight));
        my_mlx_pixel_put(&img, i, y, assign_text(i, rays));
        y++;
    }

    y = wall.wallBtPixel;
    while (y < map_conf.height)
    {
        my_mlx_pixel_put(&img, i, y, g_ceeling);
        y++;
    }
}

void check_map(char *line, int i)
{
    if ((line[i] == '1' || line[i] == ' ') && line[i] != '\0') // add line[i] != '/0' &&
    {
        map_conf.startMP = 1;
        // while (line[i] == ' ')
        //     i++;
        creatingMap(line);
    }
}

void initalize(ray_struct *rays, int i)
{
    wall.perpDistance = (rays[i].distance * cos(rays[i].angle_norm - move_player.rotationAngle));
    wall.distProjPlan = (map_conf.width / 2) / tan(rays->fv_angle / 2);
    wall.projWallHeight = (TILE_SIZE / wall.perpDistance) * wall.distProjPlan;
    wall.wallStrHeight = (int)wall.projWallHeight;
    wall.wallTpPixel = (map_conf.height / 2) - (wall.wallStrHeight / 2);
    wall.wallTpPixel = wall.wallTpPixel < 0 ? 0 : wall.wallTpPixel;
    wall.wallBtPixel = (map_conf.height / 2) + (wall.wallStrHeight / 2);
    wall.wallBtPixel = wall.wallBtPixel > map_conf.height ? map_conf.height : wall.wallBtPixel;
    if (rays[i].wasHitVertical)
        dtx.offX = (int)rays[i].wallHitY % TILE_SIZE;
    else
        dtx.offX = (int)rays[i].wallHitX % TILE_SIZE;
}

int ft_error(char *err)
{
    printf("%s\n", err);
    exit(0);
}

void text_init(void)
{
    int w;
    int h;

    if (!(nt.img = mlx_xpm_file_to_image(img.mlx_ptr, map_conf.north_texture, &w, &h)))
        ft_error("Error\nNO texture");
    nt.addr = (int *)mlx_get_data_addr(nt.img, &nt.bits_per_pixel, &nt.line_lenght, &nt.endian);
    if (!(st.img = mlx_xpm_file_to_image(img.mlx_ptr, map_conf.south_texture, &w, &h)))
        ft_error("Error\nSO texture");
    st.addr = (int *)mlx_get_data_addr(st.img, &st.bits_per_pixel, &st.line_lenght, &st.endian);
    if (!(wt.img = mlx_xpm_file_to_image(img.mlx_ptr, map_conf.west_texture, &w, &h)))
        ft_error("Error\nWE texture");
    wt.addr = (int *)mlx_get_data_addr(wt.img, &wt.bits_per_pixel, &wt.line_lenght, &wt.endian);
    if (!(et.img = mlx_xpm_file_to_image(img.mlx_ptr, map_conf.east_texture, &w, &h)))
        ft_error("Error\nEA texture");
    et.addr = (int *)mlx_get_data_addr(et.img, &et.bits_per_pixel, &et.line_lenght, &et.endian);
    if (!(sp.img = mlx_xpm_file_to_image(img.mlx_ptr, map_conf.sprite, &w, &h)))
        ft_error("Error\nS texture");
    sp.addr = (int *)mlx_get_data_addr(sp.img, &sp.bits_per_pixel, &sp.line_lenght, &sp.endian);
}

int assign_text(int i, ray_struct *rays)

{
    int *data[5];
    int dst;
    data[0] = nt.addr;
    data[1] = st.addr;
    data[2] = wt.addr;
    data[3] = et.addr;
    if (rays[i].isRayFacingUp && !rays[i].wasHitVertical)
        dst = data[1][64 * dtx.offY + dtx.offX];
    if (rays[i].isRayFacingLeft && rays[i].wasHitVertical)
        dst = data[0][64 * dtx.offY + dtx.offX];
    if (rays[i].isRayFacingDown && !rays[i].wasHitVertical)
        dst = data[3][64 * dtx.offY + dtx.offX];
    if (rays[i].isRayFacingRight && rays[i].wasHitVertical)
        dst = data[2][64 * dtx.offY + dtx.offX];
    return (dst);
}

void renderSpProj(t_sprite *sprites, ray_struct *rays)
{

    t_sprite visibSprite[map_conf.spNumber];
    int vbNumSp;
    float angleSpPlayer;
    int i;

    vbNumSp = 0;
    i = 0;

    while (i < map_conf.spNumber)
    {
        angleSpPlayer = move_player.rotationAngle - atan2(sprites[i].y - g_player.y, sprites[i].x - g_player.x);

        if (angleSpPlayer > M_PI)
            angleSpPlayer -= (2 * M_PI);
        if (angleSpPlayer < -M_PI)
            angleSpPlayer += (2 * M_PI);
        angleSpPlayer = fabs(angleSpPlayer);

        if (angleSpPlayer < (FOV / 2) + EPSILON)
        {
            sprites[i].visibSp = 1;
            sprites[i].angle = angleSpPlayer;
            // if something went wrong try to change the x and y position in the function
            sprites[i].distance = distanceBpoint(sprites[i].x, sprites[i].y, g_player.x, g_player.y);
            visibSprite[vbNumSp] = sprites[i];
            vbNumSp++;
        }
        else
            sprites[i].visibSp = 0;

        sortSprite(vbNumSp, visibSprite);
        renderSprite(vbNumSp, visibSprite, rays);
        i++;
    }
}

void sortSprite(int vbNumber, t_sprite *visibleSprite)
{
    int i;
    int j;
    t_sprite temp;
    i = 0;

    while (i < vbNumber - 1)
    {
        j = i + 1;
        while (j < vbNumber)
        {
            if (visibleSprite[i].distance < visibleSprite[j].distance)
            {
                temp = visibleSprite[i];
                visibleSprite[i] = visibleSprite[j];
                visibleSprite[j] = temp;
            }
            j++;
        }
        i++;
    }
}

void renderSprite(int vbNumber, t_sprite *visibSprite, ray_struct *rays)
{
    int i;
    int y;
    float spHeight;
    float spWidth;
    float distProjPlan;
    float spTpY;
    float spBtY;
    float spriteAngle;
    float spritePosX;
    float spriteLeftX;
    float SpriteRightX;
    float perdistance;
    t_sprite sprite;
    int x;

    i = 0;

    // check with this part later and remove the y test
    distProjPlan = ((map_conf.width / 2) / tan(FOV / 2));
    while (i < vbNumber)
    {
        sprite = visibSprite[i];
        perdistance = sprite.distance * cos(sprite.angle);
        spHeight = (TILE_SIZE / perdistance) * distProjPlan;
        spWidth = spHeight;
        spTpY = (map_conf.height / 2) - (spHeight / 2);
        spTpY = (spTpY < 0) ? 0 : spTpY;
        spBtY = (map_conf.height / 2) + (spHeight / 2);
        spBtY = (spBtY > map_conf.height) ? map_conf.height : spBtY;

        spriteAngle = atan2(sprite.y - g_player.y, sprite.x - g_player.x) - move_player.rotationAngle;
        spritePosX = tan(spriteAngle) * distProjPlan;
        spriteLeftX = (map_conf.width / 2) + spritePosX - (spWidth / 2);
        SpriteRightX = spriteLeftX + spWidth;
        x = spriteLeftX;
        while (x < SpriteRightX)
        {
            float texelWidth = (64 / spWidth);
            sprite.offX = (x - spriteLeftX) * texelWidth < 0 ? 0 : (x - spriteLeftX) * texelWidth;
            y = spTpY;
            while (y < spBtY)
            {
                if (x > 0 && x < map_conf.width && y > 0 && y < map_conf.height)
                {
                    int distFtop = y + (spHeight / 2) - (map_conf.height / 2);
                    sprite.offY = distFtop * (64 / spHeight);
                    //printf("%d\n", sprite.offY);
                    assigne_sprite(sprite, x, y, rays);
                }
                y++;
            }
            x++;
        }
        i++;
    }
}

int assigne_sprite(t_sprite sprite, int x, int y, ray_struct *rays)
{
    int *data[2];
    int dst;

    data[1] = sp.addr;
    dst = data[1][64 * sprite.offY + sprite.offX];
    if (sprite.distance < rays[x].distance && dst != 0xFF00FF)
        my_mlx_pixel_put(&img, x, y, dst);
    return (dst);
}

void draw_sprite_in_map(t_sprite *sprite)
{
    int k;
    int i;
    int j;

    k = 0;
    int colors;

    while (k < map_conf.spNumber)
    {
        i = sprite[k].x / TILE_SIZE;
        j = sprite[k].y / TILE_SIZE;
        if (sprite[k].visibSp == 1)
            colors = 0xEA3546;
        else if (sprite[k].visibSp == 0)
            colors = 0xF9C80E;
        draw_square(i, j, img, colors);
        k++;
    }
}

void store_the_spData(int i, int j, t_sprite *sprites, int indx)
{
    sprites[indx].x = (i + 0.5) * TILE_SIZE;
    sprites[indx].y = (j + 0.5) * TILE_SIZE;
}
