#include "header.h"

void	reset(int keycode, t_struct *g)
{
	if (keycode == UP_DIR)
		g->move_player.walkDirection = 0;
	else if (keycode == DOWN_DIR)
		g->move_player.walkDirection = 0;
	else if (keycode == RIGHT_ARROW)
		g->move_player.turnDirection = 0;
	else if (keycode == LEFT_ARROW)
		g->move_player.turnDirection = 0;
	else if (keycode == A || keycode == D)
	{
		g->move_player.sideSteps = 0;
		g->move_player.walkDirection = 0;
	}
}

void 	checkKeyCode(int keycode, t_struct *g)
{
	if (keycode == UP_DIR)
		g->move_player.walkDirection = 1;
	if (keycode == DOWN_DIR)
		g->move_player.walkDirection = -1;
	if (keycode == RIGHT_ARROW)
		g->move_player.turnDirection = 1;
	if (keycode == LEFT_ARROW)
		g->move_player.turnDirection = -1;
	if (keycode == A)
	{
		g->move_player.sideSteps = -M_PI_2;
		g->move_player.walkDirection = 1;
	}
	if (keycode == D)
	{
		g->move_player.sideSteps = M_PI_2;
		g->move_player.walkDirection = 1;
	}
	if (keycode == ECHAP)
	{
		exit(1);
		free_memory(memory);
	}
}

int	onClickListner(int keycode, t_struct *g)
{
	checkKeyCode(keycode, g);
	movement(g);
	reset(keycode, g);
	return (0);
}

int	reset_player(int key, t_struct *g)
{
	if (key == UP_DIR || key == DOWN_DIR)
		g->move_player.walkDirection = 0;
	if (key == A || key == D)
	{
		g->move_player.sideSteps = 0;
		g->move_player.walkDirection = 0;
	}
	else if (key == 124)
		g->move_player.turnDirection = 0;
	else if (key == 123)
		g->move_player.turnDirection = 0;
	return (0);
}

void	movement(t_struct *g)
{
	float	moveSteps;
	float	nextX;
	float	nextY;

	g->move_player.rotationAngle += g->move_player.turnDirection
		* g->move_player.rotationSpeed;
	g->move_player.rotationAngle = angleSanitizer(g->move_player.rotationAngle);
	moveSteps = g->move_player.walkDirection * g->move_player.moveSpeed;
	nextY = g->g_player.y + sin(g->move_player.rotationAngle
			+ g->move_player.sideSteps) * moveSteps;
	nextX = g->g_player.x + cos(g->move_player.rotationAngle
			+ g->move_player.sideSteps) * moveSteps;
	if ((!has_wall(g->g_player.x, nextY + 20, g))
		&& (!has_wall(g->g_player.x, nextY - 20, g)))
		g->g_player.y = nextY;
	if ((!has_wall(nextX + 20, g->g_player.y, g))
		&& (!has_wall(nextX - 20, g->g_player.y, g)))
		g->g_player.x = nextX;
}
