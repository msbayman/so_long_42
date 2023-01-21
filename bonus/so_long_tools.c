/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:43:03 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/21 17:18:06 by amsaoub          ###   ########.fr       */
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

void print_cp(t_list *so_long)
{
	char *s;
	mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->imag_wall, 0, 0);
	mlx_put_image_to_window(so_long->mlx, so_long->win,
	so_long->imag_wall, 64, 0);
s =  ft_itoa(so_long->cp);
	mlx_string_put(so_long->mlx,
			so_long->win, 0, 0, 0xffffff, s);
free(s);
}

void	lose(void)
{
	write(1,"you lose!",10);
	exit(0);
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
	movesf(k);
	i++;
	return (i);
	
}

int render_help_fire(t_list *k, int j)
{
	if(j == 3000)
		{
		k->imag_fire = mlx_xpm_file_to_image(k->mlx,
				"./xpm/fire3.xpm", &k->h, &k->w);
		draw_collect(k);
	}
	if(j == 4000)
		{
		k->imag_fire = mlx_xpm_file_to_image(k->mlx,
				"./xpm/fire4.xpm", &k->h, &k->w);	
		draw_collect(k);
	}
	if(j == 5000)
		{
		k->imag_fire = mlx_xpm_file_to_image(k->mlx,
				"./xpm/fire5.xpm", &k->h, &k->w);	
		draw_collect(k);
	}
	if(j == 6000)
		{
		k->imag_fire = mlx_xpm_file_to_image(k->mlx,
				"./xpm/fire6.xpm", &k->h, &k->w);	
		draw_collect(k);
	}
		if(j == 7000)
		{
		k->imag_fire = mlx_xpm_file_to_image(k->mlx,
				"./xpm/fire7.xpm", &k->h, &k->w);	
		draw_collect(k);
	}
		if(j == 8000)
		{
		k->imag_fire = mlx_xpm_file_to_image(k->mlx,
				"./xpm/fire8.xpm", &k->h, &k->w);	
		draw_collect(k);
	}
		if(j == 9000)
		{
		k->imag_fire = mlx_xpm_file_to_image(k->mlx,
				"./xpm/fire9.xpm", &k->h, &k->w);	
		draw_collect(k);
	}
	return (j);
}

int render_next_frame_fire(t_list *k)
{
	static int j;
	
	if (j == 6000)
		j = 0;
	if(j == 1000)
	{
		k->imag_fire = mlx_xpm_file_to_image(k->mlx,
				"./xpm/fire1.xpm", &k->h, &k->w);	
		draw_collect(k);
	}
	if(j == 2000)
	{
		k->imag_fire = mlx_xpm_file_to_image(k->mlx,
				"./xpm/fire2.xpm", &k->h, &k->w);	
		draw_collect(k );
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
	static int i;

	if(i == 10000)
	{
		i = 0;
		move_fire(k);
	}
	i++;
	return (0);
}

int	move_fire_h(t_list *k ,int i, int j)
{
	int	x;
	int y;
	x = (rand() % 3) - 1;
	y = (rand() % 3) - 1;
	if(x == y || -x == y)
		return (0);
	if(k->map[i+x][j+y] == 'P' || (k->x_p/64 ==j+y && k->y_p/64 == i+x))	
		lose();
	if(k->map[i+x][j+y] == '0')
	{
		mlx_put_image_to_window(k->mlx, k->win,
			k->imag_ground, j*64, i*64);
		k->map[i][j] = '0';
		k->map[i+x][j+y] = 'F';
		draw_collect(k);
	}
	return (0);
}
