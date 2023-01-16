/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:03:37 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/16 13:11:47 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int move_player(int k,t_list *so_long)
{
	(void)so_long;
	printf("%d\n", k);
	if (k == 53 )
		exit(0);
	if(k == 0)
	{
		if( so_long->map[so_long->y_P / 64 ][so_long->x_P / 64 -1] != '1')
		{
			mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->imag_ground , so_long->x_P, so_long->y_P) ;
			mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->imag_player , so_long->x_P - 64 , so_long->y_P );
			so_long->x_P -= 64;
		}
	}
	if(k == 1)
	{
		if( so_long->map[so_long->y_P / 64 + 1][so_long->x_P / 64] != '1')
		{
			mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->imag_ground , so_long->x_P, so_long->y_P ) ;
			mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->imag_player , so_long->x_P , so_long->y_P + 64 );
			so_long->y_P += 64;
		}
	}
	if(k == 2)
	{
		if( so_long->map[so_long->y_P / 64 ][so_long->x_P / 64 + 1] != '1')
		{
			mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->imag_ground , so_long->x_P, so_long->y_P) ;
			mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->imag_player , so_long->x_P + 64 , so_long->y_P );
			so_long->x_P += 64;
		}
	}
	if(k == 13)
	{
		if( so_long->map[so_long->y_P / 64 - 1][so_long->x_P / 64] != '1')
		{
			mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->imag_ground , so_long->x_P, so_long->y_P) ;
			mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->imag_player , so_long->x_P , so_long->y_P  - 64);
			so_long->y_P -= 64;
		}
	}
		
	return 0;
}
int main(int ac, char **av)
{
	t_list so_long;
	// void (*fun_ptr)(t_list) = &move_player;
	
	parsing(ac , av[1], &so_long );
	so_long.mlx = mlx_init();
	so_long.win = mlx_new_window(so_long.mlx,so_long.w * 64 , so_long.h * 64 , "so_long");
	so_long.imag_ground = mlx_xpm_file_to_image(so_long.mlx,"./xpm/ground.xpm",&so_long.h,&so_long.w);
	so_long.imag_player = mlx_xpm_file_to_image(so_long.mlx,"xpm/player.xpm",&so_long.h,&so_long.w);
	so_long.imag_wall = mlx_xpm_file_to_image(so_long.mlx,"./xpm/wall.xpm",&so_long.h,&so_long.w);
	so_long.imag_exit = mlx_xpm_file_to_image(so_long.mlx,"xpm/exit.xpm",&so_long.h,&so_long.w);
	so_long.imag_collect = mlx_xpm_file_to_image(so_long.mlx,"./xpm/collect.xpm",&so_long.h,&so_long.w);
	draw_map(&so_long);
	mlx_key_hook(so_long.win,move_player, &so_long);
	mlx_loop(so_long.mlx);
	return(0);
}