#include "header.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    // printf("%d \t %d \n", map_conf.width, map_conf.height);
    if (x < map_conf.width && y < map_conf.height)
        if (x >= 0 && y >= 0)
            data->addr[y * map_conf.width + x] = color;
}

void reset(int keycode)
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

void    free_all(void)
{
    // int i;

    // i = -1;
    // while (map_conf.map[++i])
    // {
    //     free(map_conf.map[i]);
    // }
    // free(map_conf.map);
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
    else if (keycode == ECHAP)
    {
        exit(1);
        free_all();
        return (0);
    }
    movement();
    reset(keycode);
    return 0;
}
int reset_player(int key)
{
    if (key == UP_DIR || key == DOWN_DIR)
    {
        move_player.walkDirection = 0;
        //g_pl.moove_forward_or_backward = 0;
    }
    else if (key == 124)
        move_player.turnDirection = 0;
    else if (key == 123)
        move_player.turnDirection = 0;

    return (0);
}

void movement()
{
    float moveSteps;
    float nextX;
    float nextY;
    nextY = g_player.y;
    nextX = g_player.x;

    move_player.rotationAngle += move_player.turnDirection * move_player.rotationSpeed;
    move_player.rotationAngle = angleSanitizer(move_player.rotationAngle);
    moveSteps = move_player.walkDirection * move_player.moveSpeed;

    if (map_conf.map[(int)(nextY + (sin(move_player.rotationAngle) * moveSteps)) / TILE_SIZE]
                    [(int)(nextX + (cos(move_player.rotationAngle) * moveSteps)) / TILE_SIZE] != '1' &&
        map_conf.map[(int)(nextY + (sin(move_player.rotationAngle) * moveSteps)) / TILE_SIZE]
                    [(int)(nextX + (cos(move_player.rotationAngle) * moveSteps)) / TILE_SIZE] != '2')
    {
        g_player.x = nextX + (cos(move_player.rotationAngle) * moveSteps);
        g_player.y = nextY + (sin(move_player.rotationAngle) * moveSteps);
    }
}

void store_data(char *line, int i)
{
    if (!ft_strchr("RNSWEFC1 ", line[i]))
        ft_error("Error\nMiss Config in map");
    collect_res(line, i);
    collect_text(line, i);
    check_map(line, i);

    map_conf.result = map_conf.res + map_conf.no +
                      map_conf.so + map_conf.we + map_conf.ea +
                      map_conf.s + map_conf.f + map_conf.c;
}

void collect_res(char *line, int i)
{
    if (line[i] != '\0' && (line[i] == 'R' && line[i + 1] == ' '))
    {
        rounting(line, i);

        map_conf.data = ft_split(line + i, ' ');
        map_conf.width = ft_atoi(map_conf.data[1]);
        map_conf.height = ft_atoi(map_conf.data[2]);
        if (map_conf.width > 2560)
            map_conf.width = 2560;
        if (map_conf.height > 1440)
            map_conf.height = 1440;
        if (map_conf.width <= 0 || map_conf.height <= 0)
            ft_error("Error\n Check Resolution");
    }
}

void rounting(char *line, int i)
{

    if (line[i] == 'R' && line[i + 1] == ' ' && (++map_conf.counter))
    {
        map_conf.res += 100;
        get_res(line);
    }
}

void get_res(char *line)
{
    char **temp;
    char *str1;
    char *str2;
    int i;
    int j;

    i = 0;
    temp = ft_split(line, ' ');
    if (temp == NULL || count_tab(temp) != 3)
        ft_error("Error\n In resolution");
    str1 = temp[1];
    str2 = temp[2];
    // change it later
    printf("the height = %s\n", str1);
    printf("the Width  = %s\n", str2);
    j = i;
    while (str1[i] && ft_isdigit(str1[i]) == 1)
        i++;
    if (str1[i])
        ft_error("Error\n Check Resolution");
    while (str2[j] && ft_isdigit(str2[j]) == 1)
        j++;
    if (str2[j])
        ft_error("Error\n Check Resolution");
}

int count_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return i;
}

void collect_text(char *line, int i)
{
    if (line[i] != '\0' && line[i] == 'N' && line[i + 1] == 'O' && (++map_conf.counter))
    {
        map_conf.north_texture = fill_textures(map_conf.north_texture, line, i);
        map_conf.no += 200;
    }
    else if (line[i] != '\0' && line[i] == 'S' && line[i + 1] == 'O' && (++map_conf.counter))
    {
        map_conf.south_texture = fill_textures(map_conf.south_texture, line, i);
        map_conf.so += 500;
    }
    else if (line[i] != '\0' && line[i] == 'W' && line[i + 1] == 'E' && (++map_conf.counter))
    {
        map_conf.west_texture = fill_textures(map_conf.west_texture, line, i);
        map_conf.we += 40;
    }
    else if (line[i] != '\0' && line[i] == 'E' && line[i + 1] == 'A' && (++map_conf.counter))
    {
        map_conf.east_texture = fill_textures(map_conf.east_texture, line, i);
        map_conf.ea += 600;
    }
    else if (line[i] != '\0' && line[i] == 'S' && line[i + 1] == ' ' && (++map_conf.counter))
    {
        map_conf.sprite = fill_textures(map_conf.sprite, line, i);
        map_conf.s += 20;
    }
    else if (line[i] != '\0' && line[i] == 'F' && line[i + 1] == ' ' && (++map_conf.counter))
    {
        fill_floor(line, i);
        map_conf.f += 350;
    }
    else if (line[i] != '\0' && line[i] == 'C' && line[i + 1] == ' ' && (++map_conf.counter))
    {
        fill_ceilling(line, i);
        map_conf.c += 670;
    }
    // else if (map_conf.result != 2480)
    //         ft_error("Error\n Duplucate or missing params");
    // else if (line[i] == '1' && map_conf.counter < 8)
    //     ft_error("Error\n Check your file");
}

char *fill_textures(char *texture, char *line, int i)
{
    i += 2;
    while (line[i] == ' ')
        i++;
    texture = ft_strdup_(line + i);
    return (texture);
}

void fill_floor(char *line, int i)
{
    int j;
    int comma;

    j = i;
    comma = 0;
    i += 2;

    while (line[i] == ' ')
        i++;
    while (line[j])
    {
        if (line[j] == ',')
            comma++;
        j++;
    }
    if (!ft_isdigit(line[ft_strlen(line) - 1]))
        ft_error("Error\nCheck floor");
    map_conf.data = ft_split(line + i, ',');
    if (count_tab(map_conf.data) > 3)
        ft_error("Error\nCheck floor");
    if (comma > 2)
        ft_error("Error\n There is more than two commas");
    checkNum(map_conf.data[0], map_conf.data[1], map_conf.data[2]);
    map_conf.rFloor = ft_atoi(map_conf.data[0]);
    map_conf.gFloor = ft_atoi(map_conf.data[1]);
    map_conf.bFloor = ft_atoi(map_conf.data[2]);
    (map_conf.rFloor < 0 || map_conf.rFloor > 255) ? ft_error("Error red in floor") : 0;
    (map_conf.gFloor < 0 || map_conf.gFloor > 255) ? ft_error("Error green in floor") : 0;
    (map_conf.bFloor < 0 || map_conf.bFloor > 255) ? ft_error("Error blue in floor") : 0;
    g_floor = (map_conf.rFloor << 16) | (map_conf.gFloor << 8) | map_conf.bFloor;
}

void checkNum(char *str, char *str2, char *str3)
{
    int i;

    i = 0;

    while (str[i] && str2[i] && str3[i])
    {
        if (ft_isdigit(str[i]) == 0 || ft_isdigit(str2[i]) == 0 || ft_isdigit(str3[i]) == 0)
            ft_error("Error\n Check your ceiling or floor");
        i++;
    }
}

void fill_ceilling(char *line, int i)
{
    int comma;
    int j;

    comma = 0;
    i += 2;
    j = i;

    while (line[i] == ' ')
        i++;
    while (line[j])
    {
        if (line[j] == ',')
            comma++;
        j++;
    }
    if (!ft_isdigit(line[ft_strlen(line) - 1]))
        ft_error("Error\nCheck Ceiling");
    map_conf.data = ft_split(line + i, ',');
    if (count_tab(map_conf.data) > 3)
        ft_error("Error\nCheck ceiling");
    if (comma > 2)
        ft_error("Error\n There is more than two commas");
    checkNum(map_conf.data[0], map_conf.data[1], map_conf.data[2]);
    map_conf.ceilingR = ft_atoi(map_conf.data[0]);
    map_conf.ceilingG = ft_atoi(map_conf.data[1]);
    map_conf.ceilingB = ft_atoi(map_conf.data[2]);
    (map_conf.ceilingR < 0 || map_conf.ceilingR > 255) ? ft_error("Error red in ceeling") : 0;
    (map_conf.ceilingG < 0 || map_conf.ceilingG > 255) ? ft_error("Error green in ceeling") : 0;
    (map_conf.ceilingB < 0 || map_conf.ceilingB > 255) ? ft_error("Error blue in ceeling") : 0;
    g_ceeling = (map_conf.ceilingR << 16) | (map_conf.ceilingG << 8) | map_conf.ceilingB;
}

void creatingMap(char *line, int i)
{
    int save = ft_strlen(line);
    char *tmp;
    if (save > g_tmp_width)
        g_tmp_width = save;
    tmp = map_conf.wlrd;
    map_conf.wlrd = ft_strjoin_(map_conf.wlrd, line);
    tmp = map_conf.wlrd;
    map_conf.wlrd = ft_strjoin_(map_conf.wlrd, "\n");
    map_conf.numHeight++;
}

// void read_map(void)
// {
//     int i;
//     int j;

//     j = 0;
//     i = 0;
//     while (map_conf.map[i])
//     {
//         j = 0;
//         while (map_conf.map[i][j])
//         {
//             if (ft_strchr("NSEW", map_conf.map[i][j]))
//             {
//                 init_pl(i, j);
//                 break;
//             }
//             j++;
//         }
//         i++;
//     }
// }

void init_pl(int y, int x)
{
    g_player.x = x * TILE_SIZE + (TILE_SIZE / 2);
    g_player.y = y * TILE_SIZE + (TILE_SIZE / 2);
}

double angleSanitizer(float angle)
{
    angle = remainder(angle, 2 * M_PI);
    if (angle < 0)
        angle += 2 * M_PI;
    if (angle > 2 * M_PI)
        angle -= 2 * M_PI;
    return (angle);
}

void rays_init(ray_struct *rays)
{

    rays->angle_norm = move_player.rotationAngle - (rays->fv_angle / 2);
    rays->num_rays = map_conf.width;
    rays->fv_angle = 60 * (M_PI / 180);
}

void castAllRays(ray_struct *rays)
{
    int i;

    int k;
    int h;

    float rayAngle;

    rays_init(rays);

    i = 0;
    k = 0;
    text_init();

    while (i < rays->num_rays)
    {
        cast(rays, i);
        render_wall(rays, i);
        rays->angle_norm += (rays->fv_angle / rays->num_rays);
        i++;
    }
}
void checkTheRayDir(ray_struct *rays)
{
    rays->isRayFacingDown = (rays->angle_norm > 0 && rays->angle_norm < M_PI) ? 1 : 0;
    rays->isRayFacingUp = !rays->isRayFacingDown;
    rays->isRayFacingRight = (rays->angle_norm < 0.5 * M_PI || rays->angle_norm > 1.5 * M_PI) ? 1 : 0;
    rays->isRayFacingLeft = !rays->isRayFacingRight;
}

void cast(ray_struct *rays, int i)
{

    rays->angle_norm = angleSanitizer(rays->angle_norm);
    checkTheRayDir(rays);
    checkHorzInter(rays);
    checkVertInter(rays);
    calculDistance(rays, i);

    // draw_line(g_player.x * nms, g_player.y * nms, rays[i].wallHitX * nms, rays[i].wallHitY * nms);
}

void checkHorzInter(ray_struct *rays)
{
    float xStep;
    float yStep;
    float xInter;
    float yInter;
    float xyInter[2];

    yInter = floor((g_player.y / TILE_SIZE)) * TILE_SIZE;
    yInter += rays->isRayFacingDown ? TILE_SIZE : 0;
    xInter = g_player.x + (yInter - g_player.y) / tan(rays->angle_norm);

    yStep = TILE_SIZE;
    yStep *= rays->isRayFacingUp ? -1 : 1;
    xStep = TILE_SIZE / tan(rays->angle_norm);
    xStep *= (rays->isRayFacingLeft && xStep > 0) ? -1 : 1;
    xStep *= (rays->isRayFacingRight && xStep < 0) ? -1 : 1;
    xyInter[0] = xInter;
    xyInter[1] = yInter;
    checkWallHorz(xyInter, xStep, yStep, rays);
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

    int i = 0;
    int j;

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
        creatingMap(line, i);
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

        sortSprite(sprites, vbNumSp, visibSprite);
        renderSprite(sprites, vbNumSp, visibSprite, rays);
        i++;
    }
}

void sortSprite(t_sprite *sprites, int vbNumber, t_sprite *visibleSprite)
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

void renderSprite(t_sprite *sprites, int vbNumber, t_sprite *visibSprite, ray_struct *rays)
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
    int a;
    sprites[indx].x = (i + 0.5) * TILE_SIZE;
    sprites[indx].y = (j + 0.5) * TILE_SIZE;
}
