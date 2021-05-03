/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:40:33 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/30 12:44:08 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <fcntl.h>
# include "getNextLine/get_next_line.h"
# include "libft/libft.h"
# include "struct.h"
# include <limits.h>

# define LEFT_DIR 0
# define TILE_SIZE 64
# define NUM_RAYS
# define NMS 0.1
# define FOV 1.0471975512
# define EPSILON 0.2

void	lst_push_front(t_mem **list, void *mem);
void	*my_malloc(size_t n, t_struct *g);
void	circle(t_struct *g);
void	catchThem(int j, int i, t_struct *g);
void	free_memory(t_mem *list);
void	read_line(char *line, int fd, t_struct *g);
void	collect_spData(t_sprite *sprite, int indx);
void	store_the_spData(int i, int j, t_sprite *sprites, int indx);
void	check_thefile(char **file, int argc);
void	my_mlx_pixel_put(int x, int y, int color, t_struct *g);
void	render(t_struct *g);
void	init_all(t_struct *g);
void	draw_square(int x, int y, int color, t_struct *g);
void	draw_circle(int x, int y, t_data data, int color);
void	draw_map(t_sprite *sprites, t_struct *g);
void	draw_line(float dX, float dY, t_struct *g);
void	draw_player(t_struct *g);
void	parse_file(char **file_path, t_struct *g, int argc);
void	movePlayer(void);
void	ft_line(float angle, int radius, int color, t_struct *g);
void	turnDirect(void);
void	movement(t_struct *g);
void	checkWall(void);
void	store_data(char *line, int i, t_struct *g);
void	fill_ceilling(char *line, int i, t_struct *g);
void	fill_floor(char *line, int i, t_struct *g);
void	creatingMap(char *line, t_struct *g);
void	ray_cast(void);
void	read_map(void);
void	fill_line(char **temp_map, int i);
void	fill_map(t_struct *g);
void	draw_ray_line(float rayAngle);
void	init_pl(int y, int x, t_struct *g);
void	cast(t_r_struct *rays, int i, t_struct *g);
void	castAllRays(t_r_struct *rays, t_struct *g);
void	checkWallHorz(t_r_struct *rays, t_struct *g);
void	checkWallVert(t_r_struct *rays, t_struct *g);
void	checkTheRayDir(t_r_struct *rays);
void	checkHorzInter(t_r_struct *rays, t_struct *g);
void	checkVertInter(t_r_struct *rays, t_struct *g);
void	calculDistance(t_r_struct *rays, int i, t_struct *g);
void	store_array(t_r_struct *rays, int i);
void	render_ray(t_r_struct *rays, t_struct *g);
void	render_wall(t_r_struct *rays, int i, t_struct *g);
void	text_init(t_struct *g);
void	collect_res(char *line, int i, t_struct *g);
void	collect_text(char *line, int i, t_struct *g);
void	check_map(char *line, int i, t_struct *g);
void	initalize(t_r_struct *rays, int i, t_struct *g);
void	renderSpProj(t_sprite *sprites, t_r_struct *rays, t_struct *g);
void	renderMapsp(t_sprite *sprites, int i, int j, int indx);
void	draw_px(int x, int y, int color, t_struct *g);
void	draw_sprite_in_map(t_sprite *sprite, t_struct *g);
void	renderSprite(int vbNumber, t_r_struct *rays, t_struct *g);
void	sortSprite(int vbNumber, t_struct *g);
void	ft_init(t_struct *g);
void	rounting(char *line, int i, t_struct *g);
void	get_res(char *line, t_struct *g);
void	drawTheMap(int i, int j, t_sprite *sprites, t_struct *g);
void	checkNum(char *str, char *str2, char *str3);
void	lookError(t_struct *g);
void	fil_space(char **map, t_struct *g);
void	fil_themp(char **map, char **wrld, t_struct *g);
void	textnsw(char *line, int i, t_struct *g);
void	textesf(char *line, int i, t_struct *g);
void	checkFloor(t_struct *g);
void	checkceeling(t_struct *g);
void	initwall(t_r_struct *rays);
void	checker(t_r_struct *rays, float xToCheck, float yToCheck, t_struct *g);
void	vinitwall(t_r_struct *rays);
void	vchecker(t_r_struct *rays, float xtoCheck, float ytoCheck, t_struct *g);
void	compDist(float horzHitDistance, float vertHitDistance,
			t_r_struct *rays, int i);
void	text_checker(t_struct *g);
void	calcsp(t_struct *g, t_sprite *sp, int i, int *vbns);
int		reset_player(int key, t_struct *g);
int		onClickListner(int keycode, t_struct *g);
int		has_wall(float x, float y, t_struct *g);
int		assign_text(int i, t_r_struct *rays, t_struct *g);
int		assigne_sprite(t_sprite sprite, t_r_struct *rays, t_struct *g);
int		count_tab(char **tab);
int		ft_error(char *err);
int		keys(void *g);
int		destroy(t_struct *g);
double	angleSanitizer(float angle);
double	distanceBpoint(float x1, float y1, float x2, float y2);
char	*fill_textures(char *texture, char *line, int i, t_struct *g);
size_t	count_line_skip_space(const char *str);
void	save_bmp(t_struct *g);
void	ft_check_save(char *str, t_struct *g);

#endif
