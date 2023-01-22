/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_tools2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:27:17 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/22 14:22:05 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long_bonus.h"

int	render_next_frame_fire(t_list *k)
{
	static int	j;

	if (j == 6000)
		j = 0;
	if (j == 1000)
	{
		k->imag_fire = mlx_xpm_file_to_image(k->mlx,
				"./xpm/fire1.xpm", &k->h, &k->w);
		draw_collect(k);
	}
	if (j == 2000)
	{
		k->imag_fire = mlx_xpm_file_to_image(k->mlx,
				"./xpm/fire2.xpm", &k->h, &k->w);
		draw_collect(k);
	}
	render_help(k, j);
	j++;
	return (0);
}

int	move_fire(t_list *k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((k->map)[i])
	{
		j = 0;
		while ((k->map)[i][j])
		{
			if ((k->map)[i][j] == 'F')
			{
				move_fire_h(k, i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	movesf(t_list *k)
{
	static int	i;

	if (i == 10000)
	{
		i = 0;
		move_fire(k);
	}
	i++;
	return (0);
}

int	move_fire_h(t_list *k, int i, int j)
{
	int	x;
	int	y;

	x = (rand() % 3) - 1;
	y = (rand() % 3) - 1;
	if (x == y || - x == y)
		return (0);
	if (k->map[i + x][j + y] == 'P' ||
		(k->x_p / 64 == j + y && k->y_p / 64 == i + x))
		lose();
	if (k->map[i + x][j + y] == '0')
	{
		mlx_put_image_to_window(k->mlx, k->win,
			k->imag_ground, j * 64, i * 64);
		k->map[i][j] = '0';
		k->map[i + x][j + y] = 'F';
		draw_collect(k);
	}
	return (0);
}

void	init_image(t_list *so_long)
{
	so_long->win = mlx_new_window(so_long->mlx,
			so_long->w * 64, so_long->h * 64, "so_long");
	so_long->imag_ground = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/ground.xpm", &so_long->h, &so_long->w);
	so_long->imag_player = mlx_xpm_file_to_image(so_long->mlx,
			"xpm/player.xpm", &so_long->h, &so_long->w);
	so_long->imag_wall = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/wall.xpm", &so_long->h, &so_long->w);
	so_long->imag_exit = mlx_xpm_file_to_image(so_long->mlx,
			"xpm/exit.xpm", &so_long->h, &so_long->w);
	so_long->imag_collect = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/collect1.xpm", &so_long->h, &so_long->w);
	so_long->imag_fire = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/fire1.xpm", &so_long->h, &so_long->w);
	if (!so_long->win || !so_long->imag_ground || !so_long->imag_player
		|| !so_long->imag_wall || !so_long->imag_exit
		|| !so_long->imag_collect || !so_long->imag_fire)
		er();
}
