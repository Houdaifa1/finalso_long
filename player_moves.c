/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:44:31 by hdrahm            #+#    #+#             */
/*   Updated: 2024/03/21 15:44:39 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_images(t_mlptr *mlptr, int i, int j, char c)
{
	if (c == '4')
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgel,
			i, j);
	if (c == '6')
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imger,
			i, j);
	if (c == '8')
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgeu,
			i, j);
	if (c == '2')
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imged,
			i, j);
	if (c == 'a')
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgpml,
			i, j);
	if (c == 'd')
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgpmr,
			i, j);
	if (c == 'w')
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgpmu,
			i, j);
	if (c == 's')
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgpmd,
			i, j);
}

void	ft_change_map_imga(t_mlptr *mlptr)
{
	if (mlptr->map[mlptr->pj][mlptr->pi - 1] == '0'
		|| mlptr->map[mlptr->pj][mlptr->pi - 1] == 'C')
	{
		mlptr->moves++;
		mlptr->map[mlptr->pj][mlptr->pi] = '0';
		ft_put_map_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, '0');
		mlptr->pi = mlptr->pi - 1;
		player_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, 'a');
		if (mlptr->map[mlptr->pj][mlptr->pi] == 'C')
		{
			player_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, '4');
			mlptr->c--;
		}
		enemys_a(mlptr->pj, mlptr->pi + 1, mlptr);
	}
	else if ((mlptr->map[mlptr->pj][mlptr->pi - 1] == 'E' && mlptr->c == 0)
		|| mlptr->map[mlptr->pj][mlptr->pi - 1] == 'V')
	{
		mlptr->moves++;
		mlptr->map[mlptr->pj][mlptr->pi] = '0';
		ft_put_map_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, '0');
		printf("the player moves   %d\n", mlptr->moves);
		ft_free_mlptr(mlptr, 'Y');
		exit(1);
	}
}

void	ft_change_map_imgs(t_mlptr *mlptr)
{
	if (mlptr->map[mlptr->pj + 1][mlptr->pi] == '0' || (mlptr->map[mlptr->pj
			+ 1][mlptr->pi] == 'C'))
	{
		mlptr->moves++;
		mlptr->map[mlptr->pj][mlptr->pi] = '0';
		ft_put_map_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, '0');
		mlptr->pj = mlptr->pj + 1;
		player_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, 's');
		if (mlptr->map[mlptr->pj][mlptr->pi] == 'C')
		{
			player_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, '2');
			mlptr->c--;
		}
		enemys_s(mlptr->pj - 1, mlptr->pi, mlptr);
	}
	else if ((mlptr->map[mlptr->pj + 1][mlptr->pi] == 'E' && mlptr->c == 0)
		|| mlptr->map[mlptr->pj + 1][mlptr->pi] == 'V')
	{
		mlptr->moves++;
		mlptr->map[mlptr->pj][mlptr->pi] = '0';
		ft_put_map_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, '0');
		printf("the player moves   %d\n", mlptr->moves);
		ft_free_mlptr(mlptr, 'Y');
		exit(1);
	}
}

void	ft_change_map_imgd(t_mlptr *mlptr)
{
	if (mlptr->map[mlptr->pj][mlptr->pi + 1] == '0'
		|| mlptr->map[mlptr->pj][mlptr->pi + 1] == 'C')
	{
		mlptr->moves++;
		mlptr->map[mlptr->pj][mlptr->pi] = '0';
		ft_put_map_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, '0');
		mlptr->pi = mlptr->pi + 1;
		player_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, 'd');
		if (mlptr->map[mlptr->pj][mlptr->pi] == 'C')
		{
			player_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, '6');
			mlptr->c--;
		}
		enemys_d(mlptr->pj, mlptr->pi - 1, mlptr);
	}
	else if ((mlptr->map[mlptr->pj][mlptr->pi + 1] == 'E' && mlptr->c == 0)
		|| mlptr->map[mlptr->pj][mlptr->pi + 1] == 'V')
	{
		mlptr->moves++;
		mlptr->map[mlptr->pj][mlptr->pi] = '0';
		ft_put_map_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, '0');
		printf("the player moves   %d\n", mlptr->moves);
		ft_free_mlptr(mlptr, 'Y');
		exit(1);
	}
}

void	ft_change_map_imgw(t_mlptr *mlptr)
{
	if (mlptr->map[mlptr->pj - 1][mlptr->pi] == '0' || mlptr->map[mlptr->pj
		- 1][mlptr->pi] == 'C')
	{
		mlptr->moves++;
		mlptr->map[mlptr->pj][mlptr->pi] = '0';
		ft_put_map_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, '0');
		mlptr->pj = mlptr->pj - 1;
		player_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, 'w');
		if (mlptr->map[mlptr->pj][mlptr->pi] == 'C')
		{
			player_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, '8');
			mlptr->c--;
		}
		enemys_w(mlptr->pj + 1, mlptr->pi, mlptr);
	}
	else if ((mlptr->map[mlptr->pj - 1][mlptr->pi] == 'E' && mlptr->c == 0)
		|| mlptr->map[mlptr->pj - 1][mlptr->pi] == 'V')
	{
		mlptr->moves++;
		mlptr->map[mlptr->pj][mlptr->pi] = '0';
		ft_put_map_images(mlptr, mlptr->pi * 50, mlptr->pj * 50, '0');
		printf("the player moves   %d\n", mlptr->moves);
		ft_free_mlptr(mlptr, 'Y');
		exit(0);
	}
}
