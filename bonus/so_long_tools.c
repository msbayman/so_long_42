/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:43:03 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/21 18:43:12 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long_bonus.h"

void	er(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	draw_map1(t_list *k, int i, int j)
{
	if ((k->map)[i][j] == '1')
		mlx_put_image_to_window(k->mlx, k->win,
			k->imag_wall, j * 64, i * 64);
	if ((k->map)[i][j] == '0')
		mlx_put_image_to_window(k->mlx, k->win,
			k->imag_ground, j * 64, i * 64);
	if ((k->map)[i][j] == 'C')
	{
		mlx_put_image_to_window(k->mlx, k->win,
			k->imag_ground, j * 64, i * 64);
		mlx_put_image_to_window(k->mlx, k->win,
			k->imag_collect, j * 64, i * 64);
	}
	if ((k->map)[i][j] == 'F')
	{
		mlx_put_image_to_window(k->mlx, k->win,
			k->imag_ground, j * 64, i * 64);
		mlx_put_image_to_window(k->mlx, k->win,
			k->imag_fire, j * 64, i * 64);
	}
	if ((k->map)[i][j] == 'E')
	{
		mlx_put_image_to_window(k->mlx, k->win,
			k->imag_ground, j * 64, i * 64);
		mlx_put_image_to_window(k->mlx, k->win,
			k->imag_exit, j * 64, i * 64);
	}
}

void	draw_map(t_list *k)
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
			draw_map1(k, i, j);
			if ((k->map)[i][j] == 'P')
			{
				mlx_put_image_to_window(k->mlx, k->win,
					k->imag_ground, j * 64, i * 64);
				mlx_put_image_to_window(k->mlx, k->win,
					k->imag_player, j * 64, i * 64);
				k->x_p = j * 64;
				k->y_p = i * 64;
			}
			j++;
		}
		i++;
	}
}

void	draw_collect(t_list *k)
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
			if ((k->map)[i][j] == 'C')
			{
				mlx_put_image_to_window(k->mlx, k->win,
					k->imag_ground, j * 64, i * 64);
				mlx_put_image_to_window(k->mlx, k->win,
					k->imag_collect, j * 64, i * 64);
			}
			if ((k->map)[i][j] == 'F')
			{
				mlx_put_image_to_window(k->mlx, k->win,
					k->imag_ground, j * 64, i * 64);
				mlx_put_image_to_window(k->mlx, k->win,
					k->imag_fire, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	check_collect(t_list *so_long)
{
	if (so_long->map[so_long->y_p / 64][so_long->x_p / 64] == 'C')
	{
			so_long->cp_collect--;
			so_long->map[so_long->y_p / 64][so_long->x_p / 64] = '0';
	}
	if (so_long->map[so_long->y_p / 64][so_long->x_p / 64] == 'E')
	{
		write(1, "you win", 8);
		exit(0);
	}
}
