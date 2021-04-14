/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 01:24:15 by aaqari            #+#    #+#             */
/*   Updated: 2019/10/22 15:38:54 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	result;
	int sign;

	result = 0;
	sign = 1;
	if ((*str) == '-')
	{
		str++;
		sign = -1;
	}
	while ((((*str) >= 9 && (*str) <= 13) || (*str) == 32) && (*str))
		str++;
	if ((*str) == '+')
		str++;
	while ((*str) >= '0' && (*str) <= '9')
	{
		if (result < 0 && sign < 0)
			return (0);
		if (result < 0 && sign > 0)
			return (-1);
		result = result * 10 + (*str) - '0';
		str++;
	}
	return (result * sign);
}