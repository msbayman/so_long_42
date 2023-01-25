/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:03:37 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/23 11:11:51 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long_bonus.h"

int	main(int ac, char **av)
{
	t_list	so_long;

	if (ac != 2)
		er();
	so_long.cp = 0;
	parsing(av[1], &so_long);
	so_long.mlx = mlx_init();
	init_image(&so_long);
	check_anime(&so_long);
	draw_map(&so_long);
	mlx_hook(so_long.win, 2, 1L << 0, move_player, &so_long);
	mlx_loop_hook(so_long.mlx, render_next_frame, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}
