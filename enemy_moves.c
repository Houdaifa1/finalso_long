/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:24:05 by hdrahm            #+#    #+#             */
/*   Updated: 2024/03/21 00:24:08 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_enemy_left(int pj, int pi, t_mlptr *mlptr)
{
	if (mlptr->map[pj][pi + 1] == 'V')
	{
		if (mlptr->map[pj][pi] != 'V')
		{
			mlptr->map[pj][pi + 1] = '0';
			mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind,
				mlptr->imgs, (pi + 1) * 50, pj * 50);
			mlptr->map[pj][pi] = 'V';
			mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind,
				mlptr->imgenl, pi * 50, pj * 50);
		}
	}
}

void	ft_move_enemy_right(int pj, int pi, t_mlptr *mlptr)
{
	if (mlptr->map[pj][pi - 1] == 'V')
	{
		if (mlptr->map[pj][pi] != 'V')
		{
			mlptr->map[pj][pi - 1] = '0';
			mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind,
				mlptr->imgs, (pi - 1) * 50, pj * 50);
			mlptr->map[pj][pi] = 'V';
			mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind,
				mlptr->imgenl, pi * 50, pj * 50);
		}
	}
}

void	ft_move_enemy_up(int pj, int pi, t_mlptr *mlptr)
{
	if (mlptr->map[pj + 1][pi] == 'V')
	{
		if (mlptr->map[pj][pi] != 'V')
		{
			mlptr->map[pj + 1][pi] = '0';
			mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind,
				mlptr->imgs, pi * 50, (pj + 1) * 50);
			mlptr->map[pj][pi] = 'V';
			mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind,
				mlptr->imgenl, pi * 50, pj * 50);
		}
	}
}

void	ft_move_enemy_down(int pj, int pi, t_mlptr *mlptr)
{
	if (mlptr->map[pj - 1][pi] == 'V')
	{
		if (mlptr->map[pj][pi] != 'V')
		{
			mlptr->map[pj - 1][pi] = '0';
			mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind,
				mlptr->imgs, pi * 50, (pj - 1) * 50);
			mlptr->map[pj][pi] = 'V';
			mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind,
				mlptr->imgenl, pi * 50, pj * 50);
		}
	}
}
