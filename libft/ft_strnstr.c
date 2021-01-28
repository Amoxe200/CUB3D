/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 23:31:19 by aaqari            #+#    #+#             */
/*   Updated: 2019/10/24 23:31:25 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	if (*to_find == '\0' || to_find == NULL)
		return (char *)str;
	while (str[i] && i < len)
	{
		j = 0;
		while (to_find[j] == str[j + i] && i + j < len)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
