/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:34:51 by aaqari            #+#    #+#             */
/*   Updated: 2019/10/23 22:51:08 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (d == '\0' && s == '\0')
		return (NULL);
	if (ft_memcmp(d, s, len) == 0)
		return (dest);
	if (s < d && d < s + len)
	{
		s = s + len;
		d = d + len;
		while (len--)
			*--d = *--s;
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dest);
}
