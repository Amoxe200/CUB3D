#include "header.h"

double distanceBpoint(float x1, float y1, float x2, float y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}


void check_map(char *line, int i, t_struct *g)
{
    if ((line[i] == '1' || line[i] == ' ') && line[i] != '\0') // add line[i] != '/0' &&
    {
        g->map_conf.startMP = 1;
        // while (line[i] == ' ')
        //     i++;
        creatingMap(line, g);
    }
}

int ft_error(char *err)
{
    printf("%s\n", err);
    exit(0);
}

void renderSprite(int vbNumber, t_sprite *visibSprite, ray_struct *rays, t_struct *g)
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
    distProjPlan = ((g->map_conf.width / 2) / tan(FOV / 2));
    while (i < vbNumber)
    {
        sprite = visibSprite[i];
        perdistance = sprite.distance * cos(sprite.angle);
        spHeight = (TILE_SIZE / perdistance) * distProjPlan;
        spWidth = spHeight;
        spTpY = (g->map_conf.height / 2) - (spHeight / 2);
        spTpY = (spTpY < 0) ? 0 : spTpY;
        spBtY = (g->map_conf.height / 2) + (spHeight / 2);
        spBtY = (spBtY > g->map_conf.height) ? g->map_conf.height : spBtY;

        spriteAngle = atan2(sprite.y - g->g_player.y, sprite.x - g->g_player.x) - g->move_player.rotationAngle;
        spritePosX = tan(spriteAngle) * distProjPlan;
        spriteLeftX = (g->map_conf.width / 2) + spritePosX - (spWidth / 2);
        SpriteRightX = spriteLeftX + spWidth;
        x = spriteLeftX;
        while (x < SpriteRightX)
        {
            float texelWidth = (64 / spWidth);
            sprite.offX = (x - spriteLeftX) * texelWidth < 0 ? 0 : (x - spriteLeftX) * texelWidth;
            y = spTpY;
            while (y < spBtY)
            {
                if (x > 0 && x < g->map_conf.width && y > 0 && y < g->map_conf.height)
                {
                    int distFtop = y + (spHeight / 2) - (g->map_conf.height / 2);
                    sprite.offY = distFtop * (64 / spHeight);
                    //printf("%d\n", sprite.offY);
                    assigne_sprite(sprite, x, y, rays, g);
                }
                y++;
            }
            x++;
        }
        i++;
    }
}

int assigne_sprite(t_sprite sprite, int x, int y, ray_struct *rays, t_struct *g)
{
    int *data[2];
    int dst;

    data[1] = g->sp.addr;
    dst = data[1][64 * sprite.offY + sprite.offX];
    if (sprite.distance < rays[x].distance && dst != 0xFF00FF)
        my_mlx_pixel_put(&(g->img), x, y, dst
        , g);
    return (dst);
}

void draw_sprite_in_map(t_sprite *sprite, t_struct *g)
{
    int k;
    int i;
    int j;

    k = 0;
    int colors;

    while (k < g->map_conf.spNumber)
    {
        i = sprite[k].x / TILE_SIZE;
        j = sprite[k].y / TILE_SIZE;
        if (sprite[k].visibSp == 1)
            colors = 0xEA3546;
        else if (sprite[k].visibSp == 0)
            colors = 0xF9C80E;
        draw_square(i, j, g->img, colors, g);
        k++;
    }
}

void store_the_spData(int i, int j, t_sprite *sprites, int indx)
{
    sprites[indx].x = (i + 0.5) * TILE_SIZE;
    sprites[indx].y = (j + 0.5) * TILE_SIZE;
}
