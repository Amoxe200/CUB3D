#include "header.h"



void ft_init()
{
    move_player.radius = 3;
    move_player.turnDirection = 0;
    move_player.walkDirection = 0;
    move_player.rotationAngle = 180 * (M_PI / 180.0);
    move_player.moveSpeed     = 20.0;
    move_player.rotationSpeed = 10 * (M_PI / 180.0);
    ray_config.fov_angle = 60 * (M_PI / 180.0);
    ray_config.wall_strip_width = 1;
    ray_config.num_of_rays  = map_conf.width / ray_config.wall_strip_width;
    track_the_ray.distanceHorz = 0;
    track_the_ray.isRayFacingDown = 0;
    track_the_ray.isRayFacingUp = 0;
    track_the_ray.isRayFacingLeft = 0;
    track_the_ray.isRayFacingRight = 0;
    img.mlx_ptr =       mlx_init();
    img.win_ptr =       mlx_new_window(img.mlx_ptr,
    map_conf.width, map_conf.height, "AMOXE");
}


void    fill_map()
{
    char **tmp_map;
    int i;
    int j;

    tmp_map = ft_split(map_conf.wlrd, '\n');
    world = malloc(map_conf.numHeight * sizeof(char *));
    while (i < map_conf.numHeight)
    {
        // printf("%d\n", i);
        world[i] = malloc(g_tmp_width * sizeof(char));
        fill_line(tmp_map, i);
        i++;
    }
    //printf("%s\n",tmp_map[0]);
}

void fill_line(char **temp_map, int i)
{
    int j;

    j = 0;
    while (temp_map[i][j])
    {   
        world[i][j] = temp_map[i][j];
        if (ft_strchr("NSEW", world[i][j]))
        {
                init_pl(i, j);
                world[i][j] = '0';
        }
        j++;
    }
    /*while (j < g_tmp_width)
    {
        world[i][j] = '1';
        j++;
    }*/
        //printf("j %d\n", j);
}
int main()
{
    int fd;
    int i;
    fd = open ("file.cub", O_RDONLY);
    i = 0;
    char *line;
    map_conf.numHeight = 0;
    map_conf.numWidth = 0;
    g_tmp_width = 0;
    map_conf.wlrd = "";
    while (get_next_line(fd, &line) != 0)
    {
        
        i = 0;
        while (line[i] == ' ')
            i++;
        store_data(line, i);
    }
    if (line != NULL && line[0] != '\0')
    {
        i = 0;
        while (line[i] == ' ')
            i++;
        
        store_data(line, i);
    }
    //printf("%s\n",map_conf.wlrd);
    i = 0;
   // world = ft_split(map_conf.wlrd, '\n');
    fill_map();
    ft_init();
    draw_map();
    mlx_hook(img.win_ptr, 2, 1L<<0, onClickListner, &img);
    mlx_loop(img.mlx_ptr);
    //             int k;
    //     j = 0;
    // k = 0;
    //  while (k < map_conf.numHeight)
    // {
    //     j = 0;
    //     while (j < g_tmp_width)
    //     {
    //         printf("%c", world[k][j]);
    //         j++;
    //     }
    //     printf("\n");
    //     k++;
    // }
 
    return 0;
}
