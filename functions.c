#include "header.h"

double distanceBpoint(float x1, float y1, float x2, float y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
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

int ft_error(char *err)
{
    printf("%s\n", err);
    exit(0);
}

void renderSprite(int vbNumber, t_sprite *visibSprite, ray_struct *rays)
{
    int i;
    int y;
    t_spt    sp;
    t_sprite sprite;
    int x;

    i = 0;

    // check with this part later and remove the y test
    sp.distProjPlan = ((map_conf.width / 2) / tan(FOV / 2));
    while (i < vbNumber)
    {
        sprite = visibSprite[i];
        sp.perdistance = sprite.distance * cos(sprite.angle);
        sp.spHeight = (TILE_SIZE / sp.perdistance) * sp.distProjPlan;
        sp.spWidth = sp.spHeight;
        sp.spTpY = (map_conf.height / 2) - (sp.spHeight / 2);
        sp.spTpY = (sp.spTpY < 0) ? 0 : sp.spTpY;
        sp.spBtY = (map_conf.height / 2) + (sp.spHeight / 2);
        sp.spBtY = (sp.spBtY > map_conf.height) ? map_conf.height : sp.spBtY;

        sp.spriteAngle = atan2(sprite.y - g_player.y, sprite.x - g_player.x) - move_player.rotationAngle;
        sp.spritePosX = tan(sp.spriteAngle) * sp.distProjPlan;
        sp.spriteLeftX = (map_conf.width / 2) + sp.spritePosX - (sp.spWidth / 2);
        sp.SpriteRightX = sp.spriteLeftX + sp.spWidth;
        x = sp.spriteLeftX;
        while (x < sp.SpriteRightX)
        {
            float texelWidth = (64 / sp.spWidth);
            sprite.offX = (x - sp.spriteLeftX) * texelWidth < 0 ? 0 : (x - sp.spriteLeftX) * texelWidth;
            y = sp.spTpY;
            while (y < sp.spBtY)
            {
                if (x > 0 && x < map_conf.width && y > 0 && y < map_conf.height)
                {
                    int distFtop = y + (sp.spHeight / 2) - (map_conf.height / 2);
                    sprite.offY = distFtop * (64 / sp.spHeight);
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
