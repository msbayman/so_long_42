/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:12:50 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/14 10:35:49 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<stddef.h>
# include<unistd.h>
# include<limits.h>
# include<stdlib.h>
# include<stdio.h> 
# include<string.h>
# include<fcntl.h>

typedef struct s_assets
{
	int				p;
	int				c;
	int				e;

}	t_assets;

int		ft_strlen(char *str);
int		check_file_ext(char *s , char *ext);
size_t	ft_strlenn( const char *c);
char	*ft_strdup(char *s1);
char	*ft_strjoinn(char	*s1, char	*s2);
char	*ft_substr(char	*s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
char	*linee(char *cont);
char	*linee_next(char *cont);
char	**ft_split(char *s, char c);
int		readline(int fd, char **cont);
char	*get_next_line(int fd);
char	*ft_strcat(char *dest, char *src);
char	*get_str(int size, char **strs, char *sep);
char	*ft_strjoin(int size, char **strs, char *sep);
char	**error_malloc(char **tab);
int		word_count(const char *str, char c);
void 	check_lines(char	**tab);
void	check_wallls(char **tab);
void	check_assets(char **tab);
void 	er();
int		cp(char **tab, char k);
void	check_assets_numbers(char **tab);
void	all_parsing_check(char **tab);
char	**copy_map(char **map);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	find_pos(int *x, int *y, char **tab, char c);
int		back_track_fun(char **tab, char c , int x, int y);
char	**print_map(char **tab);
void	freemap(char **str);
int		backtracking(char **str);







#endif