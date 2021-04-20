#include "header.h"

void	collect_text(char *line, int i)
{
	textnsw(line, i);
	textesf(line, i);
	if (line[i] != '\0' && line[i] == 'C'
		&& line[i + 1] == ' ' && (++map_conf.counter))
	{
		fill_ceilling(line, i);
		map_conf.c += 670;
	}
}

void	textnsw(char *line, int i)
{
	if (line[i] != '\0' && line[i] == 'N'
		&& line[i + 1] == 'O' && (++map_conf.counter))
	{
		map_conf.north_texture
			= fill_textures(map_conf.north_texture, line, i);
		map_conf.no += 200;
	}
	else if (line[i] != '\0' && line[i] == 'S'
		&& line[i + 1] == 'O' && (++map_conf.counter))
	{
		map_conf.south_texture
			= fill_textures(map_conf.south_texture, line, i);
		map_conf.so += 500;
	}
	else if (line[i] != '\0' && line[i] == 'W'
		&& line[i + 1] == 'E' && (++map_conf.counter))
	{
		map_conf.west_texture
			= fill_textures(map_conf.west_texture, line, i);
		map_conf.we += 40;
	}
}

void	textesf(char *line, int i)
{
	if (line[i] != '\0' && line[i] == 'E'
		&& line[i + 1] == 'A' && (++map_conf.counter))
	{
		map_conf.east_texture
			= fill_textures(map_conf.east_texture, line, i);
		map_conf.ea += 600;
	}
	else if (line[i] != '\0' && line[i] == 'S'
		&& line[i + 1] == ' ' && (++map_conf.counter))
	{
		map_conf.sprite
			= fill_textures(map_conf.sprite, line, i);
		map_conf.s += 20;
	}
	else if (line[i] != '\0' && line[i] == 'F'
		&& line[i + 1] == ' ' && (++map_conf.counter))
	{
		fill_floor(line, i);
		map_conf.f += 350;
	}
}
