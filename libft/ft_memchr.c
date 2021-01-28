/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:55:20 by aaqari            #+#    #+#             */
/*   Updated: 2019/10/23 21:15:01 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*st;

	i = 0;
	st = (void *)s;
	while (i < n)
	{
		if (st[i] == (char)c)
			return (&st[i]);
		i++;
	}
	return (NULL);
}
