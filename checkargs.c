/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:40:18 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/30 14:58:36 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_check_save(char *str, t_struct *g)
{
	int	sv;

	sv = 0;
	if (ft_strncmp(str, "--save", 7) == 0)
		save_bmp(g);
	else
		ft_error("Error\n2nd argument incorrect");
}
