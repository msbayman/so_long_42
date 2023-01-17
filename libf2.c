/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libf2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:30:09 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/17 14:31:45 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	**error_malloc(char **tab)
{
	unsigned int	i;	

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

int	word_count(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		if (str[i] == c)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		else
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (count);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*k;

	k = s;
	while (n)
	{
		*k++ = 0;
		n--;
	}
}

void	freemap(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i++]);
	}
	free(str);
}
