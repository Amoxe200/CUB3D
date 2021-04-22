/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:27:57 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/22 16:01:12 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_GET_NEXT_LINE_H
# define __FT_GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include "../header.h"
# define BUFFER_SIZE 10

int		get_next_line(int fd, char **line);
char	*ft_strcpy_(char *dest, char *src);
char	*ft_strdup_(const char *src);
char	*ft_strjoin_(char *s1, char *s2);
char	*ft_strchr_(const char *s, int c);
size_t	ft_strlen_(const char *s);

#endif
