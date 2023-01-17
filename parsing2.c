/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:44:41 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/17 18:02:35 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_assets_numbers(char **tab, t_list *b)
{
	t_assets	*k;

	b->cp_collect = 0;
	k = malloc(sizeof(t_assets));
	if (!k)
		er();
	k->c = cp(tab, 'C');
	k->p = cp(tab, 'P');
	k->e = cp(tab, 'E');
	if (k->c < 1 || k->p != 1 || k->e != 1)
		er();
	b->cp_collect = k->c;
	b->cp_exit = k->e;
	free(k);
}

int	cp(char **tab, char k)
{
	int	i;
	int	j;
	int	ccp;

	ccp = 0;
	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == k)
				ccp++;
			j++;
		}
		i++;
	}
	return (ccp);
}

void	all_parsing_check(char **tab, t_list *k)
{
	int	i;

	i = 0;
	check_lines(tab, k);
	check_wallls(tab);
	check_assets(tab);
	check_assets_numbers(tab, k);
	i = backtracking(tab);
	if (i == 0)
		er();
}

void	parsing2(char **str, char **sj, int fd)
{
	while (str[0])
	{
		if (str[0][0] == '\n')
			er();
		sj[0] = ft_strjoinn(sj[0], str[0]);
		free(str[0]);
		str[0] = get_next_line(fd);
	}
}

void	parsing(char *av, t_list *k)
{
	int		fd;
	char	**tab;
	char	*str;
	char	*sj;

	if (check_file_ext(av, ".ber"))
	{	
		sj = ft_strdup("");
		if (!sj)
			er();
		fd = open(av, O_RDONLY);
		if (fd < 0)
			er();
		str = get_next_line(fd);
		if (!str)
			er();
		parsing2 (&str, &sj, fd);
		free (sj);
		tab = ft_split(sj, '\n');
		all_parsing_check(tab, k);
	k->map = tab;
	}
	else
		er();
}
