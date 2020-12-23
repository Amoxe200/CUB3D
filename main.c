#include "header.h"



void ft_init()
{
    height  = 1080;
    width   = 1920;
    move_player.radius = 3;
    move_player.turnDirection = 0;
    move_player.walkDirection = 0;
    move_player.rotationAngle = M_PI / 2;
    move_player.moveSpeed     = 15.0;
    move_player.rotationSpeed = 5 * (M_PI / 180);
    g_player.x = 13 * (width / 30);
    g_player.y = 7 * (height / 16);

    img.mlx_ptr =       mlx_init();
    img.win_ptr =       mlx_new_window(img.mlx_ptr, width, height, "AMOXE");
    img.img     =       mlx_new_image(img.mlx_ptr, width, height);
    img.addr    =      (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
}


int main()
{
    ft_init();
    draw();
	mlx_hook(img.win_ptr, 2, 1L<<0, onClickListner, &img);
    mlx_loop(img.mlx_ptr);
    return 0;
}
