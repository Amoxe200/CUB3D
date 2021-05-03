/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:18:57 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/28 16:25:44 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	freeptr(char **ptr, int r)
{
	*ptr = NULL;
	return (r);
}

int	checksave(char **line, char **save, t_struct *g)
{
	char	*ptr;
	char	*temp;

	if (*save)
	{
		temp = *line;
		ptr = ft_strchr_(*save, '\n');
		if (ptr)
		{
			*ptr = '\0';
			*line = ft_strjoin_(*line, *save, g);
			temp = *save;
			*save = ft_strdup_(ptr + 1, g);
			return (1);
		}
		*line = ft_strjoin_(*line, *save, g);
		*save = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line, t_struct *g)
{
	static char		*save;
	char			*buff;
	char			*ptr;
	int				rt;

	*line = ft_strdup_("", g);
	buff = my_malloc((BUFFER_SIZE + 1), g);
	if (fd < 0 || !buff || read(fd, buff, 0))
		return (-1);
	if (checksave(line, &save, g))
		return (freeptr(&buff, 1));
	rt = read(fd, buff, BUFFER_SIZE);
	while (rt > 0)
	{
		buff[rt] = '\0';
		*line = ft_strjoin_(*line, buff, g);
		ptr = ft_strchr_(*line, '\n');
		if (ptr)
		{
			!(*ptr = '\0') && (save = ft_strdup_(ptr + 1, g));
			return (freeptr(&buff, 1));
		}
		rt = read(fd, buff, BUFFER_SIZE);
	}
	return (freeptr(&buff, 0));
}
