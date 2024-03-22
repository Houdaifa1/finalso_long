/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:26:28 by hdrahm            #+#    #+#             */
/*   Updated: 2024/03/21 00:26:31 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_player(int keynum, t_mlptr *mlptr)
{
	char	*strmoves;

	strmoves = NULL;
	if (keynum == 97 || keynum == 65361)
		ft_change_map_imga(mlptr);
	if (keynum == 115 || keynum == 65364)
		ft_change_map_imgs(mlptr);
	if (keynum == 100 || keynum == 65363)
		ft_change_map_imgd(mlptr);
	if (keynum == 119 || keynum == 65362)
		ft_change_map_imgw(mlptr);
	if (keynum == 65307)
	{
		ft_free_mlptr(mlptr, 'Y');
		exit(1);
	}
	strmoves = ft_itoa(mlptr->moves);
	put_score_in_wind(mlptr, strmoves);
	return (0);
}

void	ft_put_image_in_win(t_info *info, t_mlptr *mlptr, int x, int y)
{
	int	a;
	int	b;
	int	i;
	int	j;

	j = 0;
	b = 0;
	while (j < y)
	{
		i = 0;
		a = 0;
		while (i < x)
		{
			ft_put_map_images(mlptr, i, j, info->map[b][a]);
			i = i + 50;
			a++;
		}
		j = j + 50;
		b++;
	}
}

void	put_enemy_animation(t_mlptr *mlptr, void *imgc)
{
	int	i;
	int	j;

	j = 0;
	while (j < mlptr->high)
	{
		i = 0;
		while (i < mlptr->size)
		{
			if (mlptr->map[j][i] == 'V')
				mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, imgc, i
					* 50, j * 50);
			i++;
		}
		j++;
	}
}

int	ft_test(t_mlptr *mlptr)
{
	static int	i;

	if (i < 10)
		put_enemy_animation(mlptr, mlptr->imgenr);
	if (i < 40)
		put_enemy_animation(mlptr, mlptr->imgenb);
	if (i < 60)
		put_enemy_animation(mlptr, mlptr->imgenb);
	if (i > 60)
		i = 0;
	i++;
	return (0);
}

void	put_images(t_info *info)
{
	t_mlptr	mlptr;
	int		x;
	int		y;

	x = 50 * info->size;
	y = 50 * info->high;
	mlptr.mlx_ptr = mlx_init();
	ft_get_images(&mlptr);
	if (mlptr.imgw == NULL || mlptr.imgpmu == NULL || mlptr.imgpmd == NULL
		|| mlptr.imgpmr == NULL || mlptr.imgpml == NULL || mlptr.imgc == NULL
		|| mlptr.imgs == NULL || mlptr.imge == NULL || mlptr.imger == NULL
		|| mlptr.imgel == NULL || mlptr.imgeu == NULL || mlptr.imged == NULL
		|| mlptr.imgenb == NULL || mlptr.imgenr == NULL)
	{
		ft_free_mlptr(&mlptr, 'N');
		ft_free_arr(info->map);
		exit(1);
	}
	mlptr.mlx_wind = mlx_new_window(mlptr.mlx_ptr, x, y, "./so_long");
	ft_put_image_in_win(info, &mlptr, x, y);
	ft_get_player_pos(info, &mlptr, 0, 0);
	mlptr.moves = 0;
	mlx_hook(mlptr.mlx_wind, 02, 1L << 0, &ft_move_player, &mlptr);
	mlx_loop_hook(mlptr.mlx_ptr, ft_test, &mlptr);
	mlx_loop(mlptr.mlx_ptr);
}
