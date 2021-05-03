/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:40:21 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/28 12:41:29 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void	*my_malloc(size_t n, t_struct *g)
{
	void	*mem;

	mem = malloc(n);
	lst_push_front(&(g->memory), mem);
	return (mem);
}

void	lst_push_front(t_mem **list, void *mem)
{
	if ((*list))
		lst_push_front(&(*list)->next, mem);
	else
	{
		(*list) = malloc(sizeof(t_mem));
		(*list)->mem = mem;
		(*list)->next = NULL;
	}
}

void	free_memory(t_mem *list)
{
	if (!list)
		return ;
	free_memory(list->next);
	free(list->mem);
	free(list);
}

int	destroy(t_struct *g)
{
	exit(1);
	free_memory(g->memory);
}
