/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_tools3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:29:17 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/21 17:37:35 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long_bonus.h"

void	print_cp(t_list *so_long)
{
	char	*s;

	mlx_put_image_to_window(so_long->mlx, so_long->win,
		so_long->imag_wall, 0, 0);
	mlx_put_image_to_window(so_long->mlx, so_long->win,
		so_long->imag_wall, 64, 0);
	s = ft_itoa(so_long->cp);
	mlx_string_put(so_long->mlx,
		so_long->win, 0, 0, 0xffffff, s);
	free(s);
}

void	lose(void)
{
	write(1, "you lose!", 10);
	exit(0);
}

int	render_help(t_list *k, int i)
{
	if (i == 3000)
	{
		k->imag_collect = mlx_xpm_file_to_image(k->mlx,
				"./xpm/collect3.xpm", &k->h, &k->w);
		draw_collect(k);
	}
	if (i == 4000)
	{
		k->imag_collect = mlx_xpm_file_to_image(k->mlx,
				"./xpm/collect4.xpm", &k->h, &k->w);
		draw_collect(k);
	}
	if (i == 5000)
	{
		k->imag_collect = mlx_xpm_file_to_image(k->mlx,
				"./xpm/collect5.xpm", &k->h, &k->w);
		draw_collect(k);
	}
	if (i == 6000)
	{
		k->imag_collect = mlx_xpm_file_to_image(k->mlx,
				"./xpm/collect6.xpm", &k->h, &k->w);
		draw_collect(k);
	}
	return (i);
}

int	render_next_frame(t_list *k)
{
	static int	i;

	if (i == 6000)
		i = 0;
	if (i == 1000)
	{
		k->imag_collect = mlx_xpm_file_to_image(k->mlx,
				"./xpm/collect1.xpm", &k->h, &k->w);
		draw_collect(k);
	}
	if (i == 2000)
	{
		k->imag_collect = mlx_xpm_file_to_image(k->mlx,
				"./xpm/collect2.xpm", &k->h, &k->w);
		draw_collect(k);
	}
	render_help(k, i);
	movesf(k);
	i++;
	return (i);
}
