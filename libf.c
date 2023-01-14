/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:33:11 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/14 10:42:19 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_word(const char *s1, int *index, char c)
{
	char	*copy;
	int		word_len;
	int		i;

	word_len = 0;
	while (s1[*index] == c)
		(*index)++;
		i = *index;
	while (s1[i] && s1[i] != c)
	{
		word_len++;
		i++;
	}
	copy = malloc(sizeof(char) * (word_len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[*index] && s1[*index] != c)
		copy[i++] = s1[(*index)++];
	copy[i] = '\0';
	return (copy);
}

char	**ft_split(char *s, char c)
{
	char	**arr;
	int		index;
	int		wc;
	int		i;

	index = 0;
	i = 0;
	if (!s)
		return (NULL);
	wc = word_count(s, c);
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	while (i < wc)
	{
	arr[i] = get_word(s, &index, c);
		if (!arr[i])
			return (error_malloc(arr));
	i++;
	}
	arr[i] = 0;
	return (arr);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!dest || !src)
		return (dest);
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*get_str(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		sep_l;
	int		str_l;	

	str_l = 0;
	i = 0;
	if (size == 0)
	{
		str = malloc(sizeof(char));
		*str = 0;
		return (str);
	}
	while (i < size)
	{
		str_l += ft_strlen(strs[i]);
		i++;
	}
	sep_l = ft_strlen(sep) * (size - 1);
	str = malloc(sizeof(char) * (str_l + sep_l) + 1);
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		j;
	int		k;
	int		i;
	char	*str;

	str = get_str(size, strs, sep);
	i = -1;
	k = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			str[k++] = strs[i][j];
			j++;
		}
		j = 0;
		while (sep[j] && i != size - 1)
		str[k++] = sep[j++];
	}
	str[k ] = '\0';
	return (str);
}

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