/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:50:39 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/17 15:54:46 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	up(t_list *so_long)
{
	if (so_long->map[so_long->y_p / 64 - 1][so_long->x_p / 64] != '1')
	{
		if (so_long->map[so_long->y_p / 64 - 1][so_long->x_p / 64] == 'E'
			&& so_long->cp_collect > 0)
			return (0);
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->imag_ground, so_long->x_p, so_long->y_p);
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->imag_ground, so_long->x_p, so_long->y_p - 64);
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->imag_player, so_long->x_p, so_long->y_p - 64);
		so_long->y_p -= 64;
		check_collect(so_long);
		so_long->cp++;
		ft_putnbr(so_long->cp);
		write(1, "\n", 1);
	}
	return (0);
}

int	down(t_list *so_long)
{
	if (so_long->map[so_long->y_p / 64 + 1][so_long->x_p / 64] != '1')
	{
		if (so_long->map[so_long->y_p / 64 + 1][so_long->x_p / 64] == 'E'
			&& so_long->cp_collect > 0)
			return (0);
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->imag_ground, so_long->x_p, so_long->y_p);
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->imag_ground, so_long->x_p, so_long->y_p + 64);
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->imag_player, so_long->x_p, so_long->y_p + 64);
		so_long->y_p += 64;
		check_collect(so_long);
		so_long->cp++;
		ft_putnbr(so_long->cp);
		write(1, "\n", 1);
	}
	return (0);
}

int	right(t_list *so_long)
{
	if (so_long->map[so_long->y_p / 64][so_long->x_p / 64 + 1] != '1')
	{	
		if (so_long->map[so_long->y_p / 64][so_long->x_p / 64 + 1] == 'E'
			&& so_long->cp_collect > 0)
			return (0);
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->imag_ground, so_long->x_p + 64, so_long->y_p);
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->imag_ground, so_long->x_p, so_long->y_p);
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->imag_player, so_long->x_p + 64, so_long->y_p);
		so_long->x_p += 64;
		check_collect(so_long);
		so_long->cp++;
		ft_putnbr(so_long->cp);
		write(1, "\n", 1);
	}
	return (0);
}

int	left(t_list *so_long)
{
	if (so_long->map[so_long->y_p / 64][so_long->x_p / 64 - 1] != '1')
	{
		if (so_long->map[so_long->y_p / 64][so_long->x_p / 64 - 1] == 'E'
			&& so_long->cp_collect > 0)
			return (0);
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->imag_ground, so_long->x_p, so_long->y_p);
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->imag_ground, so_long->x_p - 64, so_long->y_p);
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->imag_player, so_long->x_p - 64, so_long->y_p);
		so_long->x_p -= 64;
		check_collect(so_long);
		so_long->cp++;
		ft_putnbr(so_long->cp);
		write(1, "\n", 1);
	}
	return (0);
}
