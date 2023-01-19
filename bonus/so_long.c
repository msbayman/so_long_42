/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:03:37 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/19 18:55:31 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long_bonus.h"

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

int render_next_frame(t_list *k)
{
	static int i;
	
	if (i == 6000)
		i = 0;
	if(i == 1000)
	{
		k->imag_collect = mlx_xpm_file_to_image(k->mlx,
				"./xpm/collect1.xpm", &k->h, &k->w);	
		draw_collect(k);
	}
	if(i == 2000)
	{
		k->imag_collect = mlx_xpm_file_to_image(k->mlx,
				"./xpm/collect2.xpm", &k->h, &k->w);	
		draw_collect(k );
	}
	render_help(k, i);
	i++;
	return (0);
	
}

int render_help(t_list *k, int i)
{
	if(i == 3000)
		{
		k->imag_collect = mlx_xpm_file_to_image(k->mlx,
				"./xpm/collect3.xpm", &k->h, &k->w);	
		draw_collect(k);
	}
	if(i == 4000)
		{
		k->imag_collect = mlx_xpm_file_to_image(k->mlx,
				"./xpm/collect4.xpm", &k->h, &k->w);	
		draw_collect(k);
	}
	if(i == 5000)
		{
		k->imag_collect = mlx_xpm_file_to_image(k->mlx,
				"./xpm/collect5.xpm", &k->h, &k->w);	
		draw_collect(k);
	}
	if(i == 6000)
		{
		k->imag_collect = mlx_xpm_file_to_image(k->mlx,
				"./xpm/collect6.xpm", &k->h, &k->w);	
		draw_collect(k);
	}
	return (i);
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
			"./xpm/collect1.xpm", &so_long.h, &so_long.w);
	draw_map(&so_long);
	mlx_hook(so_long.win, 2, 1L << 0, move_player, &so_long);
	mlx_loop_hook(so_long.mlx, render_next_frame, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}
