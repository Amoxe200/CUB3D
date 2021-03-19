#include "header.h"



void ft_init()
{
    int a;
    move_player.radius = 3;
    move_player.turnDirection = 0;
    move_player.walkDirection = 0;
    move_player.rotationAngle = 180 * (M_PI / 180.0);
    move_player.moveSpeed     = 20.0;
    move_player.rotationSpeed = 10 * (M_PI / 180.0);
    
    img.mlx_ptr =       mlx_init();
    img.win_ptr =       mlx_new_window(img.mlx_ptr,
    map_conf.width, map_conf.height, "AMOXE");
    img.img     =       mlx_new_image(img.mlx_ptr, map_conf.width, map_conf.height);
    img.addr    =      (int *)mlx_get_data_addr(img.img, &a, &a, &a);
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
        world[i] = malloc(g_tmp_width * sizeof(char));
        fill_line(tmp_map, i);
        i++;
    }
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
        else if (ft_strchr("2", world[i][j]))
            map_conf.spNumber++;
            

        j++;
    }
    while (j < g_tmp_width)
    {
        world[i][j] = '1';
        j++;
    }
}
int keys()
{ 
    mlx_hook(img.win_ptr, 2, 1L<<0, onClickListner, &img);
    mlx_hook(img.win_ptr, 3, 0, reset_player, (void *)0);
    render();
    return 1;
}
void parse_file()
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
    if (line != NULL && line[0] != '\0')
    {
        i = 0;
        while (line[i] == ' ')
            i++; 
        store_data(line, i);
    }

}

int main()
{
    //remove it later
    setbuf(stdout, NULL);
    
    // map_conf.numHeight = 0;
    // map_conf.numWidth = 0;
    // g_tmp_width = 0;
    map_conf.wlrd = "";
    parse_file();
    fill_map();
    ft_init();
    mlx_loop_hook(img.mlx_ptr, keys, (void *)0);
    mlx_loop(img.mlx_ptr);
 
    return 0;
}