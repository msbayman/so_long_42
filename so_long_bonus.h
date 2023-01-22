/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:20:39 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/22 14:21:12 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include<stddef.h>
# include<unistd.h>
# include<limits.h>
# include<stdlib.h>
# include<stdio.h> 
# include<string.h>
# include<fcntl.h>
# include <mlx.h>

typedef struct s_assets
{
	int				p;
	int				c;
	int				e;
	int				f;

}	t_assets;

typedef struct s_co
{
	int			x;
	int			y;

}	t_co;

typedef struct s_list
{
	void		*mlx;
	void		*win;
	void		*imag_player;
	void		*imag_wall;
	void		*imag_exit;
	void		*imag_ground;
	void		*imag_collect;
	void		*imag_fire;
	void		*try;
	int			h;
	int			w;
	int			x_p;
	int			y_p;		
	char		**map;
	int			cp;
	int			cp_collect;
	int			cp_exit;
}	t_list;

int		ft_strlen(char *str);
int		check_file_ext(char *s, char *ext);
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
void	check_lines(char **tab, t_list *k);
void	check_wallls(char **tab);
void	check_assets(char **tab);
void	er(void);
int		cp(char **tab, char k);
void	check_assets_numbers(char **tab, t_list *k);
void	all_parsing_check(char **tab, t_list *k);
char	**copy_map(char **map);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	find_pos(int *x, int *y, char **tab, char c);
int		back_track_fun(char **tab, char c, int x, int y);
char	**print_map(char **tab);
void	freemap(char **str);
int		backtracking(char **str);
void	parsing(char *av, t_list *k);
void	draw_map(t_list *k);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	check_collect(t_list *so_long);
int		up(t_list *so_long);
int		down(t_list *so_long);
int		right(t_list *so_long);
int		left(t_list *so_long);
void	parsing2(char **str, char **sj, int fd);
char	*ft_itoa(int n);
void	print_cp(t_list *so_long);
void	draw_collect(t_list *k);
int		render_help(t_list *k, int i);
int		render_next_frame(t_list *k);
void	lose(void);
int		render_next_frame_fire(t_list *k);
int		move_fire(t_list *k);
int		move_fire_h(t_list *k, int i, int j);
int		movesf(t_list *k);
void	draw_collect_help(t_list *k, int i, int j);
void	draw_map1_help(t_list *k, int i, int j);
void	init_image(t_list *so_long);
int		move_player(int k, t_list *so_long);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	check_anime(t_list *k);

#endif