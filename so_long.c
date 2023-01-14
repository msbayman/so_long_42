/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:03:37 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/14 17:40:59 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_list so_long;

	parsing(ac , av[1], &so_long );
	so_long.mlx = mlx_init();
	so_long.win = mlx_new_window(so_long.mlx,so_long.w * 64 , so_long.h * 64 , "so_long");
	so_long.imag_ground = mlx_xpm_file_to_image(so_long.mlx,"./xpm/ground.xpm",&so_long.h,&so_long.w);
	so_long.imag_player = mlx_xpm_file_to_image(so_long.mlx,"xpm/player.xpm",&so_long.h,&so_long.w);
	so_long.imag_wall = mlx_xpm_file_to_image(so_long.mlx,"./xpm/wall.xpm",&so_long.h,&so_long.w);
	so_long.imag_exit = mlx_xpm_file_to_image(so_long.mlx,"xpm/exit.xpm",&so_long.h,&so_long.w);
	so_long.imag_collect = mlx_xpm_file_to_image(so_long.mlx,"./xpm/collect.xpm",&so_long.h,&so_long.w);
	draw_map(&so_long);
	mlx_loop(so_long.mlx);
	return(0);
}