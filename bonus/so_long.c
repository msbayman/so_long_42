/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:03:37 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/19 11:22:32 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

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

int	main(int ac, char **av)
{
	t_list	so_long;

	if (ac != 2)
		er();
	so_long.cp = 0;
	parsing(av[1], &so_long);
	so_long.mlx = mlx_init();
	so_long.win = mlx_new_window(so_long.mlx,
			so_long.w * 64, so_long.h * 64, "so_long");
	so_long.imag_ground = mlx_xpm_file_to_image(so_long.mlx,
			"./xpm/ground.xpm", &so_long.h, &so_long.w);
	so_long.imag_player = mlx_xpm_file_to_image(so_long.mlx,
			"xpm/player.xpm", &so_long.h, &so_long.w);
	so_long.imag_wall = mlx_xpm_file_to_image(so_long.mlx,
			"./xpm/wall.xpm", &so_long.h, &so_long.w);
	so_long.imag_exit = mlx_xpm_file_to_image(so_long.mlx,
			"xpm/exit.xpm", &so_long.h, &so_long.w);
	so_long.imag_collect = mlx_xpm_file_to_image(so_long.mlx,
			"./xpm/collect.xpm", &so_long.h, &so_long.w);
	draw_map(&so_long);
	mlx_hook(so_long.win, 2, (1L << 0), move_player, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}
