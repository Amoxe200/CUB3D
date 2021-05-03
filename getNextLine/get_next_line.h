/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:27:57 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/28 16:28:07 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include "../header.h"
# include "../struct.h"

# define BUFFER_SIZE 10

int		get_next_line(int fd, char **line, t_struct *g);
char	*ft_strcpy_(char *dest, char *src);
char	*ft_strdup_(const char *src, t_struct *g);
char	*ft_strjoin_(char *s1, char *s2, t_struct *g);
char	*ft_strchr_(const char *s, int c);
size_t	ft_strlen_(const char *s);

#endif
