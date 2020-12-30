#include "header.h"



void ft_init()
{
   // map_conf.height  = 1080;
    //map_conf.width   = 1920;
    move_player.radius = 3;
    move_player.turnDirection = 0;
    move_player.walkDirection = 0;
    move_player.rotationAngle = M_PI / 2;
    move_player.moveSpeed     = 20.0;
    move_player.rotationSpeed = 10 * (M_PI / 180);
    g_player.x = 13 * (map_conf.width / 30);
    g_player.y = 7 * (map_conf.height / 16);

    img.mlx_ptr =       mlx_init();
    img.win_ptr =       mlx_new_window(img.mlx_ptr, map_conf.width, map_conf.height, "AMOXE");
   // img.img     =       mlx_new_image(img.mlx_ptr, map_conf.width, map_conf.height);
    //img.addr    =      (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
   
}


int main()
{
    int fd;
    int i;

    fd = open ("file.cub", O_RDONLY);
    i = 0;
    char *line;
    while (get_next_line(fd, &line) != 0)
    {
        
        i = 0;
        while (line[i] == ' ')
            i++; 
        store_data(line, i);
    }
    
    ft_init();
    draw_map();
	mlx_hook(img.win_ptr, 2, 1L<<0, onClickListner, &img);
    mlx_loop(img.mlx_ptr);
    return 0;
}
