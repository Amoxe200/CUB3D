/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:54:42 by aaqari            #+#    #+#             */
/*   Updated: 2021/04/28 15:08:12 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	calc_num(const char *s, char c)
{
	int	count;
	int	i;
	int	mot;

	count = 0;
	mot = 0;
	i = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			mot = 0;
		else if (mot == 0)
		{
			mot = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static	int	long_mot(const char *s, int i, char c)
{
	int	len;
	int	j;

	len = 0;
	j = i;
	i = 0;
	while (s[j] && s[j] != c)
	{
		len++;
		j++;
	}
	return (len);
}

static	void	*fr_ee(char **mots, int j)
{
	while (j--)
		free(mots[j]);
	free(mots);
	return (NULL);
}

static	char	**help(const char *s, char c, char **mots, t_struct *g)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < calc_num(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		mots[j] = my_malloc(sizeof(char) * long_mot(s, i, c) + 1, g);
		if (mots[j] == NULL)
			return (fr_ee(mots, j));
		while (s[i] && s[i] != c)
			mots[j][k++] = s[i++];
		mots[j][k] = '\0';
		j++;
	}
	mots[j] = 0;
	return (mots);
}

char	**ft_split(char const *s, char c, t_struct *g)
{
	char	**mots;

	if (!s)
		return (NULL);
	mots = my_malloc(sizeof(char *) * (calc_num(s, c) + 1), g);
	if (!mots)
		return (NULL);
	return (help(s, c, mots, g));
}
