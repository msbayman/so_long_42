/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:28:36 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/14 10:51:35 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_strlen(char *str)
{
	int	n;
	if(str == NULL)
		return (0);
	n = 0;
	while (str[n])
		n++;
	return (n);
}

void  check_lines(char	**tab)
{
	int	i;
	int	j;
	
	i = 0;
	j = ft_strlen(tab[0]);
	if(j == 0)
		er();
	while (tab[i])
	{
		if(j != ft_strlen(tab[i]))
			er();
		i++;
	}
	 
}

int check_file_ext(char *s , char *ext)
{
	int	exten;
	int	av_s;
	int	i;
	
	exten = ft_strlen(ext);
	av_s = ft_strlen(s);
	i = 1;
	while(1)
	{
		while(s[av_s - i] == ext[exten - i] && i <= exten)
			i++;
		if(s[av_s - i] != ext[exten - i] && i <= exten)
			return (0);
		if(i > exten)
			return (1);
	}
}

void check_wallls(char **tab)
{
	int i;
	int j;
	int cp;

	cp = 0;
	j = 0;
	while (tab[j])
		j++;
	i = ft_strlen(tab[0]);
	if(i == j || i < 3 || j < 3)
		er();
	while(cp<i)
	{
		if (tab[0][cp] != '0'+1 || tab[j-1][cp] != '0'+1)
			er();
		cp++;
	}
	cp = 1;
	while (cp < j)
	{
		if (tab[cp][0] != '0'+1 || tab[cp++][i-1] != '0'+1 )
			er();
	}
}

// void tba3(char **tab)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (tab[i])
// 	{
// 		j = 0;
// 		while(tab[i][j])
// 		{
// 			printf("%c", tab[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

void check_assets(char **tab)
{
	int i;
	int j;
	
	i = 0;
	while (tab[j])
		j++;
	while(j--)
	{
		i = 0;
		while(i < ft_strlen(tab[0]))
		{
			if((tab[j][i] != '1' && tab[j][i] != '0' && tab[j][i] != 'E' && tab[j][i] != 'P' && tab[j][i] != 'C'))
				er();
			i++;
		}
	}
}

void check_assets_numbers(char **tab)
{
	t_assets *k;
	
	k = malloc(sizeof(t_assets));
	if(!k)
		er();
	k->c = cp(tab, 'C');
	k->p = cp(tab, 'P');
	k->e = cp(tab, 'E');
	if (k->c < 1 || k->p != 1 || k->e != 1)
		er();
	free(k);
}

int cp(char **tab, char k)
{
	int i;
	int j;
	int ccp;
	
	ccp = 0;
	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while(tab[i][j])
		{
			if(tab[i][j] == k)
				ccp++;
			j++;
		}
		i++;
	}
	return (ccp);
}

void	all_parsing_check(char **tab)
{
	int nb_collect;
	int x;
	int y;
	int i;
	char **copy;

	i = 0;
	copy = (char **)ft_calloc(ft_strlen(*tab),sizeof(char*));
	check_lines(tab);
	check_wallls(tab);
	check_assets(tab);
	check_assets_numbers(tab);
	i = backtracking(tab);
	if(i == 0)
		er();
}