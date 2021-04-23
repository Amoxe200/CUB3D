/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:38:16 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/23 12:59:33 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include "mlx.h"
# include "getNextLine/get_next_line.h"
# include "libft/libft.h"
# include "struct.h"

# define	UP_DIR 13
# define	DOWN_DIR 1
# define	LEFT_ARROW 123
# define	RIGHT_ARROW 124
# define	RIGHT_DIR 2
# define 	ECHAP 53
# define	A 0

t_mem		*memory;
m_player	g_player;
t_data		img;
t_data		nt;
t_data		st;
t_data		et;
t_data		wt;
t_data		sp;
cls_player	move_player;
wall_struct	wall;
txt_data	dtx;
config_map	map_conf;

char	*fill_textures(char *texture, char *line, int i);
size_t	count_line_skip_space(const char *str);
double	distanceBpoint(float x1, float y1, float x2, float y2);
double	angleSanitizer(float angle);
void	lst_push_front(t_mem **list, void *mem);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	*my_malloc(size_t n);
void	circle(void);
void	catchThem(int j, int i);
void	free_memory(t_mem *list);
void	read_line(char *line, int fd);
void	collect_spData(t_sprite *sprite, int indx);
void	store_the_spData(int i, int j, t_sprite *sprites, int indx);
void	check_thefile(char **file);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	render(void);
void	draw_square(int x, int y, t_data data, int color);
void	draw_circle(int x, int y, t_data data, int color);
void	draw_map(t_sprite *sprites);
void	draw_line(float pX, float pY, float dX, float dY);
void	draw_line(float xp, float yp, float xIntersept, float yIntersept);
void	draw_player(void);
void	parse_file(char **file_path);
void	movePlayer(void);
void	ft_line(float angle, int radius, int color);
void	turnDirect(void);
void	movement(void);
void	checkWall(void);
void	store_data(char *line, int i);
void	fill_floor(char *line, int i);
void	fill_ceilling(char *line, int i);
void	creatingMap(char *line);
void	ray_cast(void);
void	read_map(void);
void	init_pl(int y, int x);
void	fill_line(char **temp_map, int i);
void	fill_map(void);
void	draw_ray_line(float rayAngle);
void	init_pl(int y, int x);
void	cast(ray_struct *rays, int i);
void	checkTheRayDir(ray_struct *rays);
void	castAllRays(ray_struct *rays);
void	checkHorzInter(ray_struct *rays);
void	checkWallHorz(ray_struct *rays);
void	checkVertInter(ray_struct *rays);
void	checkWallVert(ray_struct *rays);
void	calculDistance(ray_struct *rays, int i);
void	store_array(ray_struct *rays, int i);
void	render_wall(ray_struct *rays, int i);
void	render_ray(ray_struct *rays);
void	text_init(void);
void	collect_res(char *line, int i);
void	collect_text(char *line, int i);
void	check_map(char *line, int i);
void	initalize(ray_struct *rays, int i);
void	renderSpProj(t_sprite *sprites, ray_struct *rays);
void	renderMapsp( t_sprite *sprites, int i, int j, int indx);
void	draw_px(int x, int y, t_data data, int color);
void	draw_sprite_in_map(t_sprite *sprite);
void	renderSprite(int vbNumber, t_sprite *visibSprite, ray_struct *rays);
void	sortSprite(int vbNumber, t_sprite *visibleSprite);
void	ft_init(void);
void	rounting(char *line, int i);
void	get_res(char *line);
void	drawTheMap(int i, int j, t_sprite *sprites);
void	lookError(void);
void	checkNum(char *str, char *str2, char *str3);
void	fil_space(char **map);
void	fil_themp(char **map, char **wrld);
void	textnsw(char *line, int i);
void	textesf(char *line, int i);
void	checkFloor(void);
void	checkceeling(void);
void	initwall(ray_struct *rays);
void	checker(ray_struct *rays, float xToCheck, float yToCheck);
void	vinitwall(ray_struct *rays);
void	vchecker(ray_struct *rays, float xtoCheck, float ytoCheck);
void	compDist(float h_hdist, float v_hdist, ray_struct *rays, int i);
void	text_checker(void);
void	calcsp(t_sprite *sprites, int i, t_sprite *vbSp, int *vbNum);
void	spinittwo(t_sprite sprite, t_spt *sp, ray_struct *rays);
int		reset_player(int key);
int		assign_text(int i, ray_struct *rays);
int		assigne_sprite(t_sprite sprite, int x, int y, ray_struct *rays);
int		ft_error(char *err);
int		keys(void);
int		destroy(void);
int		onClickListner(int keycode);
int		count_tab(char **tab);
int		has_wall(float x, float y);
int			g_floor;
int			g_ceeling;
int			g_tmp_width;

#endif
