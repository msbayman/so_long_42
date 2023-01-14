/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:03:37 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/14 16:01:55 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_list so_long;

	parsing(ac , av[1], &so_long );
	so_long.mlx = mlx_init();
	so_long.win = mlx_new_window(so_long.mlx,so_long.w * 64 , so_long.h * 64 , "so_long");
	mlx_loop(so_long.mlx);
	return(0);
}
