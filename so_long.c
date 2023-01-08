/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:03:37 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/08 13:00:29 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int main(int ac, char **av)
{
	int		fd;
	char	**tab;
	char	*str;
	char	*sj;
	int i = 0;
	if(ac == 2)
	{
				
		if(check_file_ext(av[1],".ber"))
		{	
			sj = ft_strdup("");
			if(!sj)
				exit(0);
			fd = open(av[1], O_RDONLY);
			if(fd < 3)
				exit(0);
			str = get_next_line(fd);
			if(!str)
				exit(0);
			while (str)
			{
				if(str[0] == '\n')
				return	(write(2, "Error\n", 6));
				sj = ft_strjoinn(sj, str);
				free(str);
				str = get_next_line(fd);
			}
			tab = ft_split(sj,'\n');	
			check_lines(tab);
			check_wallls(tab);
			check_assets(tab);
			check_assets_numbers(tab);
		}
		else
		 er();
	}
	else
		er();
}