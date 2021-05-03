/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:28:13 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/28 16:27:47 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "get_next_line.h"
#include "../header.h"

char	*ft_strcpy_(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen_(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup_(const char *src, t_struct *g)
{
	const char	*dest;

	dest = my_malloc(sizeof(char) * (ft_strlen_(src) + 1), g);
	if (dest == 0)
		return (NULL);
	ft_strcpy_((char *)dest, (char *)src);
	return ((char *)dest);
}

char	*ft_strchr_(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (!*s++)
			return (0);
	}
	return ((char *)s);
}

char	*ft_strjoin_(char *s1, char *s2, t_struct *g)
{
	int		l1;
	int		i;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen_(s1);
	i = 0;
	p = my_malloc(sizeof(char) * (l1 + ft_strlen_(s2) + 1), g);
	if (p == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		p[i + l1] = s2[i];
		i++;
	}
	p[i + l1] = '\0';
	return (p);
}
