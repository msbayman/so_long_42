/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtraking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:51:08 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/19 11:21:51 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

char	**copy_map(char **map)
{
	int		i;
	char	**tab;

	i = 0;
	while (map[i])
		i++;
	tab = ft_calloc(sizeof(char *), i + 1);
	if (!tab)
		er();
	i = 0;
	while (map[i])
	{
		tab[i] = ft_strdup(map[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

void	find_pos(int *x, int *y, char **tab, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == c)
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
			i++;
	}
}

int	back_track_fun(char **tab, char c, int y, int x)
{
	if (tab[y][x] == 'P')
		return (1);
	if (tab[y][x] == '1' || (c != 'E' && tab[y][x] == 'E'))
		return (0);
	tab[y][x] = '1';
	if (back_track_fun(tab, c, y + 1, x))
		return (1);
	if (back_track_fun(tab, c, y - 1, x))
		return (1);
	if (back_track_fun(tab, c, y, x + 1))
		return (1);
	if (back_track_fun(tab, c, y, x - 1))
		return (1);
	return (0);
}

int	backtracking(char **str)
{
	int		i;
	int		j;
	char	**test;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C' || str[i][j] == 'E')
			{
				test = copy_map(str);
				if (!test)
					return (freemap(test), 0);
				if (!back_track_fun(test, str[i][j], i, j))
					return (freemap(test), 0);
				freemap(test);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// char	**print_map(char **tab)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (tab[i])
// 	{
// 		j = 0;
// 		while (tab[i][j])
// 		{
// 					printf("%c ",tab[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 			i++;
// 	}
// 	return (tab);
// }