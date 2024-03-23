/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:26:26 by hdrahm            #+#    #+#             */
/*   Updated: 2024/03/23 20:45:21 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct mlptr
{
	void	*mlx_ptr;
	void	*mlx_wind;
	void	*imgw;
	void	*imgs;
	void	*imgpmu;
	void	*imgpmd;
	void	*imgpmr;
	void	*imgpml;
	void	*imgeu;
	void	*imged;
	void	*imgel;
	void	*imger;
	void	*imgc;
	void	*imge;
	int		pi;
	int		ei;
	int		ej;
	int		pj;
	int		c;
	int		moves;
	char	**map;
	int		high;
	int		size;
	void	*imgenl;
	void	*imgenred;
	void	*imgenr;
	char	*strmoves;

}			t_mlptr;

typedef struct info
{
	int		size;
	int		high;
	char	**map;
	char	*line;
	int		p;
	int		c;
	int		e;
	int		fd;
	int		r;
	int		x;

}			t_info;

char		*ft_strjoin(char const *s1, char const *s2);

void		*ft_calloc(size_t count, size_t size);

void		*ft_calloc(size_t count, size_t size);

void		ft_bzero(void *s, size_t n);

size_t		ft_strlen(const char *s);

int			ft_strchr(const char *s, int c);

char		*get_next_line(int fd);

void		translate_map(char *name);

void		ft_free_arr(char **map);

char		**ft_split(char const *s, char c);

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

int			ft_putchar(char c);

int			ft_putstr(char *str);

int			ft_printf(const char *format, ...);

int			check_path_to_p(char **map, int j, int i, t_info *info);

void		reset_map(char **map, t_info *info);

void		check_borders(char **map, t_info *info);

void		check_angle(char **map, t_info *info);

void		put_images(t_info *info);

void		check_elements(t_info *info);

void		count_elements(char **map, t_info *info);

void		ft_get_player_pos(t_info *info, t_mlptr *mlptr, int i, int j);

void		ft_change_map_imga(t_mlptr *mlptr);

void		ft_change_map_imgs(t_mlptr *mlptr);

void		ft_change_map_imgd(t_mlptr *mlptr);

void		ft_change_map_imgw(t_mlptr *mlptr);

void		ft_free_mlptr(t_mlptr *mlptr, char c);

void		ft_get_images(t_mlptr *mlptr);

char		*get_the_map_in_oneline(t_info *info);

void		ft_move_enemy_left(int pj, int pi, t_mlptr *mlptr);

void		ft_move_enemy_right(int pj, int pi, t_mlptr *mlptr);

void		ft_move_enemy_up(int pj, int pi, t_mlptr *mlptr);

void		ft_move_enemy_down(int pj, int pi, t_mlptr *mlptr);

void		ft_get_images(t_mlptr *mlptr);

char		*ft_itoa(int n);

void		put_score_in_wind(t_mlptr *mlptr, char *strmoves);

void		ft_put_map_images(t_mlptr *mlptr, int i, int j, char c);

void		enemys_a(int j, int i, t_mlptr *mlptr);

void		enemys_s(int j, int i, t_mlptr *mlptr);

void		enemys_w(int j, int i, t_mlptr *mlptr);

void		enemys_d(int j, int i, t_mlptr *mlptr);

int			ft_close_wind(t_mlptr *mlptr);

#endif
