/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libf3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:31:04 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/21 18:55:32 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long_bonus.h"

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr((n / 10));
		ft_putnbr((n % 10));
	}
	if (n <= 9)
		ft_putchar(n + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	num_len(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = num_len(n);
	i = 0;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len--] = '\0';
	if (n < 0)
	{
		i = 1;
		str[0] = '-';
		n *= -1;
	}
	while (len >= i)
	{
		str[len--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

void	draw_collect_help(t_list *k, int i, int j)
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
}
