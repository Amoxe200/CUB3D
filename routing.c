#include "header.h"

void	store_data(char *line, int i)
{
	if (!ft_strchr("RNSWEFC1 ", line[i]))
		ft_error("Error\nMiss Config in map");
	collect_res(line, i);
	collect_text(line, i);
	check_map(line, i);
	map_conf.result = map_conf.res + map_conf.no
		+ map_conf.so + map_conf.we + map_conf.ea
		+ map_conf.s + map_conf.f + map_conf.c;
}

void	collect_res(char *line, int i)
{
	if (line[i] != '\0' && (line[i] == 'R' && line[i + 1] == ' '))
	{
		rounting(line, i);
		map_conf.data = ft_split(line + i, ' ');
		map_conf.width = ft_atoi(map_conf.data[1]);
		map_conf.height = ft_atoi(map_conf.data[2]);
		if (map_conf.width > 2560)
			map_conf.width = 2560;
		if (map_conf.height > 1440)
			map_conf.height = 1440;
		if (map_conf.width <= 0 || map_conf.height <= 0)
			ft_error("Error\n Check Resolution");
	}
}

void	rounting(char *line, int i)
{
	if (line[i] == 'R' && line[i + 1] == ' ' && (++map_conf.counter))
	{
		map_conf.res += 100;
		get_res(line);
	}
}

void	get_res(char *line)
{
	char	**temp;
	char	*str1;
	char	*str2;
	int		i;
	int		j;

	i = 0;
	temp = ft_split(line, ' ');
	if (temp == NULL || count_tab(temp) != 3)
		ft_error("Error\n In resolution");
	str1 = temp[1];
	str2 = temp[2];
	j = i;
	while (str1[i] && ft_isdigit(str1[i]) == 1)
		i++;
	if (str1[i])
		ft_error("Error\n Check Resolution");
	while (str2[j] && ft_isdigit(str2[j]) == 1)
		j++;
	if (str2[j])
		ft_error("Error\n Check Resolution");
}
