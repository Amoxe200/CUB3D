#include "header.h"



void ft_init()
{
    int a;
    move_player.radius = 3;
    move_player.turnDirection = 0;
    move_player.walkDirection = 0;
    move_player.rotationAngle = 180 * (M_PI / 180.0);
    move_player.moveSpeed     = 20.0;
    move_player.rotationSpeed = 20 * (M_PI / 180.0);
    map_conf.startMP = 0;
    map_conf.indx = 0;
    img.mlx_ptr =       mlx_init();
    img.win_ptr =       mlx_new_window(img.mlx_ptr,
    map_conf.width, map_conf.height, "AMOXE");
    img.img     =       mlx_new_image(img.mlx_ptr, map_conf.width, map_conf.height);
    img.addr    =      (int *)mlx_get_data_addr(img.img, &a, &a, &a);
}


void    fill_map()
{
    
    int i;
    int j;
    int k;
    int h;
    char *z;
    
    k = 0;
    i = 0;
   z = map_conf.wlrd;
    map_conf.world = ft_split(map_conf.wlrd, '\n');
    printf("%s", map_conf.wlrd);

    //   while (map_conf.world[k])
    //  {
    //      h = 0;
    //      while (map_conf.world[k][h])
    //      {
    //          z = map_conf.world[k];
    //          printf("%c", map_conf.world[k][h]);
    //          h++;
    //      }
    //      printf("\n");
    //      k++;
    //  }
    map_conf.map = malloc((map_conf.numHeight + 3) * sizeof(char *));
    while (i < map_conf.numHeight + 2)
    {
        map_conf.map[i] = malloc((g_tmp_width + 3) * sizeof(char));
        
        map_conf.map[i][g_tmp_width +2] = '\0';
        i++;

    }
    map_conf.map[i] = NULL;

    //   while (map_conf.world[k])
    //  {
    //      h = 0;
    //      while (map_conf.world[k][h])
    //      {
    //          z = map_conf.world[k];
    //          printf("%c", map_conf.world[k][h]);
    //          h++;
    //      }
    //      printf("\n");
    //      k++;
    //  }
   
    fil_space(map_conf.map);
    fil_themp(map_conf.map, map_conf.world);
    lookError();

    map_conf.player > 1 ? ft_error("Multiple Players in Maps") : 0;
     map_conf.player == 0 ? ft_error("No Players in Maps") : 0;

    
}

void fil_space(char **map)
{
    int i;
    int j;

    i = 0;
    while (i < map_conf.numHeight + 2)
    {
        j = 0;
        
        while (map[i][j])
        {
            
            map[i][j] = ' ';
            j++;
        }
        i++;
    }

}

void fil_themp(char **map, char **wrld)
{
    int i;
    int j; 
    int y;
    int h;
    
    i = 0;
    y = 1;
    while (wrld[i])
    {
        j = 0;
        h = 1;

        while (wrld[i][j])
        {
            map[y][h] = map_conf.world[i][j];
            if (ft_strchr("NSEW", map_conf.map[i][j]))
                init_pl(i, j);
            else if (ft_strchr("2", map_conf.map[i][j]))
                map_conf.spNumber++;
            j++;
            h++;
        }
        i++;
        y++;
    }

}
void fill_line(char **temp_map, int i)
{
    int j;
    int player;

    j = 0;
    while (temp_map[i][j])
    {   
       map_conf.world[i][j] = temp_map[i][j];
        j++;
    }
    while (j < g_tmp_width)
    {
       map_conf.world[i][j] = ' ';
        j++;
    }
}
int keys()
{ 
    render();
    mlx_hook(img.win_ptr, 2, 1L<<0, onClickListner, &img);
    mlx_hook(img.win_ptr, 3, 0, reset_player, (void *)0);
    return 1;
}
void parse_file()
{
    int fd;
    int i;
    fd = open ("file.cub", O_RDONLY);
    i = 0;
    char *line;
    map_conf.counter = 0;
    
    while (get_next_line(fd, &line) != 0)
    {
        i = 0;
        if (map_conf.counter == 8 && map_conf.startMP == 1 && line[0] == '\0')
        {
            printf("map row %d\n",i);
            ft_error("Error");// check later
        }
        //while (line[i] == ' ' && map_conf.counter != 8)
         //  i++;
        store_data(line, i);
    }
    if (line != NULL && line[0] != '\0')
    {
        i = 0;
        
        //while (line[i] == ' ' && map_conf.counter != 8)
         //   i++; 
        store_data(line, i);
    }
    else
        ft_error("Error\n map should be the last in the file");

     if (map_conf.counter != 8)
    {
        ft_putstr_fd("Error In Configuration", 1);
        exit(0);
    }
}

int main()
{
    int a;

    //remove it later
    //setbuf(stdout, NULL);
    
    // map_conf.numHeight = 0;
    // map_conf.numWidth = 0;
    // g_tmp_width = 0;
    map_conf.wlrd = "";
    parse_file();
    fill_map();
    ft_init();
    img.img     =       mlx_new_image(img.mlx_ptr, map_conf.width, map_conf.height);
    img.addr    =      (int *)mlx_get_data_addr(img.img, &a, &a, &a);
    mlx_loop_hook(img.mlx_ptr, keys, (void *)0);
    mlx_loop(img.mlx_ptr);
 
    return 0;
}