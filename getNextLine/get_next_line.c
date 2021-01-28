/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:18:57 by aaqari            #+#    #+#             */
/*   Updated: 2019/12/05 14:30:20 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		freeptr(char **ptr, int r)
{
	free(*ptr);
	*ptr = NULL;
	return (r);
}

int		checksave(char **line, char **save)
{
	char *ptr;
	char *temp;

	if (*save)
	{
		temp = *line;
		if ((ptr = ft_strchr_(*save, '\n')))
		{
			*ptr = '\0';
			*line = ft_strjoin_(*line, *save);
			free(temp);
			temp = *save;
			*save = ft_strdup_(ptr + 1);
			free(temp);
			return (1);
		}
		*line = ft_strjoin_(*line, *save);
		free(temp);
		free(*save);
		*save = NULL;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*save;
	char			*buff;
	char			*ptr;
	int				rt;

	*line = ft_strdup_("");
	if (fd < 0 || !(buff = malloc(BUFFER_SIZE + 1)) || read(fd, buff, 0))
		return (-1);
	if (checksave(line, &save))
		return (freeptr(&buff, 1));
	while ((rt = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rt] = '\0';
		ptr = *line;
		*line = ft_strjoin_(*line, buff);
		free(ptr);
		if ((ptr = ft_strchr_(*line, '\n')))
		{
			*ptr = '\0';
			save = ft_strdup_(ptr + 1);
			return (freeptr(&buff, 1));
		}
	}
	return (freeptr(&buff, 0));
}
