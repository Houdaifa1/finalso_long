/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:10:02 by hdrahm            #+#    #+#             */
/*   Updated: 2024/03/21 15:10:04 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_images2(t_mlptr *mlptr)
{
	int	img_width;
	int	img_height;

	mlptr->imgw = mlx_xpm_file_to_image(mlptr->mlx_ptr, "./textures/wall.xpm",
			&img_width, &img_height);
	mlptr->imgc = mlx_xpm_file_to_image(mlptr->mlx_ptr, "./textures/coins.xpm",
			&img_width, &img_height);
	mlptr->imgs = mlx_xpm_file_to_image(mlptr->mlx_ptr, "./textures/space.xpm",
			&img_width, &img_height);
	mlptr->imge = mlx_xpm_file_to_image(mlptr->mlx_ptr, "./textures/door.xpm",
			&img_width, &img_height);
	mlptr->imgenr = mlx_xpm_file_to_image(mlptr->mlx_ptr,
			"./textures/enemyright.xpm", &img_width, &img_height);
}

void	ft_get_images(t_mlptr *mlptr)
{
	int	img_width;
	int	img_height;

	ft_get_images2(mlptr);
	mlptr->imgpmu = mlx_xpm_file_to_image(mlptr->mlx_ptr,
			"./textures/moveup.xpm", &img_width, &img_height);
	mlptr->imgpmd = mlx_xpm_file_to_image(mlptr->mlx_ptr,
			"./textures/movedown.xpm", &img_width, &img_height);
	mlptr->imgpmr = mlx_xpm_file_to_image(mlptr->mlx_ptr,
			"./textures/moveright.xpm", &img_width, &img_height);
	mlptr->imgpml = mlx_xpm_file_to_image(mlptr->mlx_ptr,
			"./textures/moveleft.xpm", &img_width, &img_height);
	mlptr->imger = mlx_xpm_file_to_image(mlptr->mlx_ptr,
			"./textures/eatright.xpm", &img_width, &img_height);
	mlptr->imgel = mlx_xpm_file_to_image(mlptr->mlx_ptr,
			"./textures/eatleft.xpm", &img_width, &img_height);
	mlptr->imgeu = mlx_xpm_file_to_image(mlptr->mlx_ptr,
			"./textures/eatup.xpm", &img_width, &img_height);
	mlptr->imged = mlx_xpm_file_to_image(mlptr->mlx_ptr,
			"./textures/eatdown.xpm", &img_width, &img_height);
	mlptr->imgenl = mlx_xpm_file_to_image(mlptr->mlx_ptr,
			"./textures/enemyleft.xpm", &img_width, &img_height);
	mlptr->imgenred = mlx_xpm_file_to_image(mlptr->mlx_ptr,
			"./textures/imgenr.xpm", &img_width, &img_height);
}

void	put_score_in_wind(t_mlptr *mlptr, char *strmoves)
{
	mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgw, 0, 0);
	mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgw, 50,
		0);
	mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgw, 100,
		0);
	mlx_string_put(mlptr->mlx_ptr, mlptr->mlx_wind, 10, 50, 0xffffff,
		"Player moves :");
	mlx_string_put(mlptr->mlx_ptr, mlptr->mlx_wind, 105, 50, 0xffffff,
		strmoves);
	free(strmoves);
}

void	ft_put_map_images(t_mlptr *mlptr, int i, int j, char c)
{
	if (c == '1')
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgw, i,
			j);
	else if (c == '0')
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgs, i,
			j);
	else if (c == 'P')
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgpmr,
			i, j);
	else if (c == 'C')
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgc, i,
			j);
	else if (c == 'E')
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imge, i,
			j);
	else if (c == 'V')
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgenl,
			i, j);
}
