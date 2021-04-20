#include "header.h"

void	reset(int keycode)
{
	if (keycode == UP_DIR)
		move_player.walkDirection = 0;
	else if (keycode == DOWN_DIR)
		move_player.walkDirection = 0;
	else if (keycode == RIGHT_ARROW)
		move_player.turnDirection = 0;
	else if (keycode == LEFT_ARROW)
		move_player.turnDirection = 0;
	else if (keycode == A || keycode == D)
	{
		move_player.sideSteps = 0;
		move_player.walkDirection = 0;
	}
}

void 	checkKeyCode(int keycode)
{
	if (keycode == UP_DIR)
		move_player.walkDirection = 1;
	if (keycode == DOWN_DIR)
		move_player.walkDirection = -1;
	if (keycode == RIGHT_ARROW)
		move_player.turnDirection = 1;
	if (keycode == LEFT_ARROW)
		move_player.turnDirection = -1;
	if (keycode == A)
	{
		move_player.sideSteps = -M_PI_2;
		move_player.walkDirection = 1;
	}
	if (keycode == D)
	{
		move_player.sideSteps = M_PI_2;
		move_player.walkDirection = 1;
	}
	if (keycode == ECHAP)
	{
		exit(1);
		free_memory(memory);
	}
}

int	onClickListner(int keycode)
{
	checkKeyCode(keycode);
	movement();
	reset(keycode);
	return (0);
}

int	reset_player(int key)
{
	if (key == UP_DIR || key == DOWN_DIR)
		move_player.walkDirection = 0;
	if (key == A || key == D)
	{
		move_player.sideSteps = 0;
		move_player.walkDirection = 0;
	}
	else if (key == 124)
		move_player.turnDirection = 0;
	else if (key == 123)
		move_player.turnDirection = 0;
	return (0);
}

void	movement(void)
{
	float	moveSteps;
	float	nextX;
	float	nextY;

	move_player.rotationAngle += move_player.turnDirection
		* move_player.rotationSpeed;
	move_player.rotationAngle = angleSanitizer(move_player.rotationAngle);
	moveSteps = move_player.walkDirection * move_player.moveSpeed;
	nextY = g_player.y + sin(move_player.rotationAngle
			+ move_player.sideSteps) * moveSteps;
	nextX = g_player.x + cos(move_player.rotationAngle
			+ move_player.sideSteps) * moveSteps;
	if ((!has_wall(g_player.x, nextY + 20))
		&& (!has_wall(g_player.x, nextY - 20)))
		g_player.y = nextY;
	if ((!has_wall(nextX + 20, g_player.y))
		&& (!has_wall(nextX - 20, g_player.y)))
		g_player.x = nextX;
}
