#include "header.h"



void ft_init()
{
    move_player.radius = 3;
    move_player.turnDirection = 0;
    move_player.walkDirection = 0;
    move_player.rotationAngle = M_PI / 2;
    move_player.moveSpeed     = 20.0;
    move_player.rotationSpeed = 10 * (M_PI / 180);
    g_player.x = 15 * TILE_SIZE;
    g_player.y = 9 * TILE_SIZE;
    ray_config.fov_angle = 60 * (M_PI / 180);
    ray_config.wall_strip_width = 1;
    ray_config.num_of_rays  = map_conf.width / ray_config.wall_strip_width;

    img.mlx_ptr =       mlx_init();
    img.win_ptr =       mlx_new_window(img.mlx_ptr, map_conf.width, map_conf.height, "AMOXE");
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
        // printf("last line => %s\n", line);
      world = ft_split(map_conf.wlrd, '\n');
    //   int h ;
    //   h  = 0;
    //   while (world[h])
    //   {
    //     printf("====>%s\n", world[h]);
    //     h++;  
    //   }
        
    // printf("height = %d|width = %d| \n", map_conf.numHeight, g_tmp_width);
    ft_init();
    draw_map();
	mlx_hook(img.win_ptr, 2, 1L<<0, onClickListner, &img);
    mlx_loop(img.mlx_ptr);
    
    return 0;
}
