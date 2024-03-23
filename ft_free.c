/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:26:44 by hdrahm            #+#    #+#             */
/*   Updated: 2024/03/21 00:26:46 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_arr(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i++]);
	}
	free(map);
}

int	ft_close_wind(t_mlptr *mlptr)
{
	ft_free_mlptr(mlptr, 'Y');
	exit(0);
}

void	ft_free2(t_mlptr *mlptr)
{
	if (mlptr->imgw)
		mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgw);
	if (mlptr->imgc)
		mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgc);
	if (mlptr->imge)
		mlx_destroy_image(mlptr->mlx_ptr, mlptr->imge);
	if (mlptr->imgs)
		mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgs);
	if (mlptr->imgenl)
		mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgenl);
	if (mlptr->imgenred)
		mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgenred);
	if (mlptr->imgenr)
		mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgenr);
}

void	ft_free_mlptr(t_mlptr *mlptr, char c)
{
	ft_free2(mlptr);
	if (mlptr->imgpmu)
		mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgpmu);
	if (mlptr->imgpmd)
		mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgpmd);
	if (mlptr->imgpmr)
		mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgpmr);
	if (mlptr->imgpml)
		mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgpml);
	if (mlptr->imger)
		mlx_destroy_image(mlptr->mlx_ptr, mlptr->imger);
	if (mlptr->imgel)
		mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgel);
	if (mlptr->imgeu)
		mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgeu);
	if (mlptr->imged)
		mlx_destroy_image(mlptr->mlx_ptr, mlptr->imged);
	if (c == 'Y')
	{
		mlx_destroy_window(mlptr->mlx_ptr, mlptr->mlx_wind);
		ft_free_arr(mlptr->map);
	}
	mlx_destroy_display(mlptr->mlx_ptr);
	free(mlptr->mlx_ptr);
}
