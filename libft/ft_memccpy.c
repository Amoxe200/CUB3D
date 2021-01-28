/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:59:22 by aaqari            #+#    #+#             */
/*   Updated: 2019/10/22 17:06:09 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)src)[i] == (char)c)
		{
			((char*)dest)[i] = ((char *)src)[i];
			return (&((char *)dest)[i + 1]);
		}
		else
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (NULL);
}
