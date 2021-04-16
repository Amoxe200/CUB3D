# include <stdlib.h>
# include "header.h"

void    *my_malloc(size_t n)
{
    void *mem;

    mem = malloc(n);
    lst_push_front(&memory, mem);
    return (mem);
}

void    lst_push_front(t_mem **list, void *mem)
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

void    free_memory(t_mem *list)
{
    if (!list)
        return ;
    free_memory(list->next);
    free(list->mem);
    free(list);
}