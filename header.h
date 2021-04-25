#ifndef HEADER_H
#define HEADER_H

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <fcntl.h>
#include "getNextLine/get_next_line.h"
#include "libft/libft.h"
#include <limits.h>

#define UP_DIR 13
#define DOWN_DIR 1
#define LEFT_ARROW 123
#define RIGHT_ARROW 124
#define RIGHT_DIR 2
#define ECHAP 53
#define A 0
#define D 2
#define LEFT_DIR 0
#define TILE_SIZE 64
#define NUM_RAYS
#define nms 0.1
#define FOV (60 * (M_PI / 180))
#define EPSILON 0.2

typedef struct s_data
{
	void *img;
	int *addr;
	void *mlx_ptr;
	void *win_ptr;
	int bits_per_pixel;
	int line_lenght;
	int endian;
} t_data;

typedef struct s_player
{
	float x;
	float y;
	int last_x;
	int last_y;

} m_player;

typedef struct mv_player
{
	int x;
	int y;
	int radius;
	int turnDirection;
	int walkDirection;
	float rotationAngle;
	float moveSpeed;
	float rotationSpeed;
	float sideSteps;
	int walkside;
} cls_player;

typedef struct map_config
{
	int width;
	int rFloor;
	int gFloor;
	int bFloor;
	int height;
	char *filePath;
	int ceilingR;
	int ceilingG;
	int ceilingB;
	int numHeight;
	int numWidth;
	int spNumber;
	int counter;
	char **data;
	char **map;
	char *wlrd;
	char *north_texture;
	char *west_texture;
	char *east_texture;
	char *south_texture;
	char *sprite_texture;
	char *sprite;
	int indx;
	int player;
	char **world;
	int startMP;
	int res;
	int no;
	int so;
	int we;
	int ea;
	int s;
	int f;
	int c;
	int result;
} config_map;

typedef struct rays
{
	float horzwallHitX;
	float horzwallHitY;
	float nexthtx;
	float nexthty;
	float nextvtx;
	float nextvty;
	float vertwallHitX;
	float vertwallHitY;
	float wallHitX;
	float wallHitY;
	float fv_angle;
	float distance;
	float num_rays;
	float angle_norm;
	float hxstp;
	float hystp;
	float hxintr;
	float hyintr;
	float xyinh[2];
	float vxstp;
	float vystp;
	float vxintr;
	float vyintr;
	float xyintrv[2];
	int wall_strWidth;
	int isRayFacingDown;
	int isRayFacingUp;
	int isRayFacingRight;
	int isRayFacingLeft;
	int foundHorzWallHit;
	int foundVertWallHit;
	int wasHitVertical;
	int horzWallContent;
	int vertWallContent;
	int wallHitContent;
} ray_struct;

typedef struct walls
{
	float distProjPlan;
	float projWallHeight;
	int wallStrHeight;
	float wallTpPixel;
	float wallBtPixel;
	float perpDistance;

} wall_struct;

typedef struct txt
{
	int offX;
	int offY;
	int dist;
} txt_data;

typedef struct sp
{
	float x;
	float y;
	float dst;
	float angleSpPlayer;
	float angle;
	float distance;
	int visibSp;
	int offX;
	int offY;
} t_sprite;

typedef struct s_mem
{
	void *mem;
	struct s_mem *next;
} t_mem;

typedef struct s_struct
{

	m_player g_player;
	t_data img;
	t_data nt;
	t_data st;
	t_data et;
	t_data wt;
	t_data sp;
	cls_player move_player;
	config_map map_conf;
	wall_struct wall;
	txt_data dtx;

	int g_tmp_width;
}	t_struct;

t_mem *memory;
void
lst_push_front(t_mem **list, void *mem);
// void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void *my_malloc(size_t n);
void	circle(t_struct *g);
void catchThem(int j, int i, t_struct *g);
void free_memory(t_mem *list);
void read_line(char *line, int fd, t_struct *g);
void collect_spData(t_sprite *sprite, int indx);
void store_the_spData(int i, int j, t_sprite *sprites, int indx);
void check_thefile(char **file);
void my_mlx_pixel_put(t_data *data, int x, int y, int color, t_struct *g);
void render(t_struct *);
void draw_square(int x, int y, t_data data, int color, t_struct *g);
void draw_circle(int x, int y, t_data data, int color);
void draw_map(t_sprite *sprites, t_struct *);
void draw_line(float pX, float pY, float dX, float dY, t_struct *);
int onClickListner(int keycode, t_struct *);
// void draw_line(float xp, float yp, float xIntersept, float yIntersept);
void draw_player(t_struct *g);
void parse_file(char **file_path, t_struct*);
void movePlayer();
void ft_line(float angle, int radius, int color, t_struct *);
void turnDirect();
void movement(t_struct *);
int has_wall(float x, float y, t_struct*);
void checkWall();
void store_data(char *line, int i, t_struct*);
char *fill_textures(char *texture, char *line, int i);
void fill_floor(char *line, int i, t_struct *);
void fill_ceilling(char *line, int i, t_struct *);
void creatingMap(char *line,t_struct *);
size_t count_line_skip_space(const char *str);
void ray_cast();
int reset_player(int key, t_struct *);
void read_map(void);
// void init_pl(int y, int x);
void fill_line(char **temp_map, int i);
void fill_map();
// void castAllRays();
void draw_ray_line(float rayAngle);
void init_pl(int y, int x,t_struct *);
double angleSanitizer(float angle);
void cast(ray_struct *rays, int i, t_struct *);
void checkTheRayDir(ray_struct *rays);
void castAllRays(ray_struct *rays, t_struct *);
void checkHorzInter(ray_struct *rays, t_struct *);
void checkWallHorz(ray_struct *rays, t_struct*);
void checkVertInter(ray_struct *rays, t_struct*);
void checkWallVert(ray_struct *rays, t_struct*);
double distanceBpoint(float x1, float y1, float x2, float y2);
void calculDistance(ray_struct *rays, int i, t_struct *);
void store_array(ray_struct *rays, int i);
void render_wall(ray_struct *rays, int i, t_struct *);
void render_ray(ray_struct *rays, t_struct *);
void text_init(t_struct*);
int assign_text(int i, ray_struct *rays, t_struct*);
void collect_res(char *line, int i, t_struct *);
void collect_text(char *line, int i, t_struct *);
void check_map(char *line, int i, t_struct *);
void initalize(ray_struct *rays, int i, t_struct *);
void renderSpProj(t_sprite *sprites, ray_struct *rays, t_struct *);
void renderMapsp(t_sprite *sprites, int i, int j, int indx);
void draw_px(int x, int y, t_data data, int color, t_struct*);
void draw_sprite_in_map(t_sprite *sprite, t_struct *);
void renderSprite(int vbNumber, t_sprite *visibSprite, ray_struct *rays, t_struct *);
int assigne_sprite(t_sprite sprite, int x, int y, ray_struct *rays, t_struct *);
void sortSprite(int vbNumber, t_sprite *visibleSprite);
void ft_init(t_struct *);
void rounting(char *line, int i, t_struct *);
void get_res(char *line);
int count_tab(char **tab);
int ft_error(char *err);
int keys();
void drawTheMap(int i, int j, t_sprite *sprites, t_struct *);
void lookError();
void checkNum(char *str, char *str2, char *str3);
void fil_space(char **map, t_struct *);
void fil_themp(char **map, char **wrld, t_struct *);
int destroy(void);
void textnsw(char *line, int i, t_struct *);
void textesf(char *line, int i, t_struct *);
void checkFloor(t_struct *g);
void checkceeling(t_struct *);
void initwall(ray_struct *rays);
void checker(ray_struct *rays, float xToCheck, float yToCheck, t_struct*);
void vinitwall(ray_struct *rays);
void vchecker(ray_struct *rays, float xtoCheck, float ytoCheck, t_struct*);
void compDist(float horzHitDistance, float vertHitDistance, ray_struct *rays, int i);
void text_checker(t_struct*);
void spCalc(t_sprite *sprites, int i, t_sprite *vbSp, int vbNum);
//intialize variables
/*
img = 0;
addr = 0;
mlx_ptr = 0;
win_ptr = 0;
bits_per_pixel = 0;
line_lenght = 0;
endian = 0;
x = 0;
y = 0;
last_x = 0;
last_y = 0;
x = 0;
y = 0;
radius = 0;
turnDirection = 0;
walkDirection = 0;
rotationAngle = 0;
moveSpeed = 0;
rotationSpeed = 0;
width = 0;
rFloor = 0;
gFloor = 0;
bFloor = 0;
height = 0;
ceilingR = 0;
ceilingG = 0;
ceilingB = 0;
numHeight = 0;
numWidth = 0;
spNumber = 0;
counter = 0;
data = 0;
wlrd = 0;
north_texture = 0;
west_texture = 0;
east_texture = 0;
south_texture = 0;
sprite_texture = 0;
sprite = 0;
horzwallHitX = 0;
horzwallHitY = 0;
vertwallHitX = 0;
vertwallHitY = 0;
wallHitX = 0;
wallHitY = 0;
fv_angle = 0;
distance = 0;
num_rays = 0;
angle_norm = 0;
wall_strWidth = 0;
isRayFacingDown = 0;
isRayFacingUp = 0;
isRayFacingRight = 0;
isRayFacingLeft = 0;
foundHorzWallHit = 0;
foundVertWallHit = 0;
wasHitVertical = 0;
horzWallContent = 0;
vertWallContent = 0;
wallHitContent = 0;
distProjPlan = 0;
projWallHeight = 0;
wallStrHeight = 0;
wallTpPixel = 0;
wallBtPixel = 0;
perpDistance = 0;
offX = 0;
offY = 0;
dist = 0;
x = 0;
y = 0;
dst = 0;
angleSpPlayer = 0;
angle = 0;
distance = 0;
visibSp = 0;
offX = 0;
offY = 0;
*/

int g_floor;
int g_ceeling;
#endif
