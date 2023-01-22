/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_tools4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:42:27 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/22 14:20:30 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	move_player(int k, t_list *so_long)
{
	if (k == 53)
	{	
		free(so_long->map);
		mlx_clear_window(so_long->mlx, so_long->win);
		exit(0);
	}
	if (k == 0 || k == 123)
		left(so_long);
	if (k == 1 || k == 125)
		down(so_long);
	if (k == 2 || k == 124)
		right(so_long);
	if (k == 13 || k == 126)
		up(so_long);
	return (0);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	k = ft_strlen((char *)src);
	i = 0;
	if (dstsize == 0)
		return (k);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (k);
}

void	check_anime(t_list *k)
{
	k->try = mlx_xpm_file_to_image(k->mlx, "./xpm/collect1.xpm", &k->h, &k->w);
	if (!k->try)
		er();
	k->try = mlx_xpm_file_to_image(k->mlx, "./xpm/collect2.xpm", &k->h, &k->w);
	if (!k->try)
		er();
	k->try = mlx_xpm_file_to_image(k->mlx, "./xpm/collect3.xpm", &k->h, &k->w);
	if (!k->try)
		er();
	k->try = mlx_xpm_file_to_image(k->mlx, "./xpm/collect4.xpm", &k->h, &k->w);
	if (!k->try)
		er();
	k->try = mlx_xpm_file_to_image(k->mlx, "./xpm/collect5.xpm", &k->h, &k->w);
	if (!k->try)
		er();
	k->try = mlx_xpm_file_to_image(k->mlx, "./xpm/collect6.xpm", &k->h, &k->w);
	if (!k->try)
		er();
}
