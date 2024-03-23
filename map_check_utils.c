/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:25:17 by hdrahm            #+#    #+#             */
/*   Updated: 2024/03/21 00:25:19 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_angle(char **map, t_info *info)
{
	int	i;
	int	j;

	info->size = ft_strlen(map[0]);
	j = 1;
	while (j < info->high)
	{
		i = ft_strlen(map[j]);
		if (i != info->size)
		{
			ft_printf("Error\nThe map is not rectangular");
			ft_free_arr(info->map);
			exit(1);
		}
		j++;
	}
}

void	check_borders(char **map, t_info *info)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < info->size)
	{
		if (map[j][i] != '1' || map[info->high - 1][i] != '1')
		{
			ft_printf("Error\nThe borders contain an element other than 1");
			ft_free_arr(info->map);
			exit(1);
		}
		i++;
	}
	while (j < info->high)
	{
		if (map[j][0] != '1' || map[j][info->size - 1] != '1')
		{
			ft_printf("Error\nThe borders contain an element other than 1");
			ft_free_arr(info->map);
			exit(1);
		}
		j++;
	}
}

void	reset_map(char **map, t_info *info)
{
	int	j;
	int	i;

	j = 0;
	while (j < info->high)
	{
		i = 0;
		while (i < info->size)
		{
			if (map[j][i] == '3')
				map[j][i] = '0';
			if (map[j][i] == 'H')
				map[j][i] = 'E';
			if (map[j][i] == 'F')
				map[j][i] = 'C';
			i++;
		}
		j++;
	}
}

int	check_path_to_p(char **map, int j, int i, t_info *info)
{
	if (i < 0 || j < 0 || i > info->size || j > info->high)
		return (0);
	if (map[j][i] == 'P')
		return (1);
	if (map[j][i] == '1' || map[j][i] == '3' || map[j][i] == 'H'
		|| map[j][i] == 'F' || map[j][i] == 'V')
		return (0);
	if (map[j][i] == 'E' && info->x == 'C')
		return (0);
	if (map[j][i] == '0' || map[j][i] == 'E' || map[j][i] == 'C')
	{
		map[j][i] = map[j][i] + 3;
		info->r = check_path_to_p(map, j + 1, i, info);
		if (info->r == 1)
			return (info->r);
		info->r = check_path_to_p(map, j - 1, i, info);
		if (info->r == 1)
			return (info->r);
		info->r = check_path_to_p(map, j, i + 1, info);
		if (info->r == 1)
			return (info->r);
		info->r = check_path_to_p(map, j, i - 1, info);
		return (info->r);
	}
	return (0);
}

void	ft_get_player_pos(t_info *info, t_mlptr *mlptr, int i, int j)
{
	j = 0;
	mlptr->map = info->map;
	mlptr->c = info->c;
	mlptr->high = info->high;
	mlptr->size = info->size;
	while (j < info->high)
	{
		i = 0;
		while (i < info->size)
		{
			if (info->map[j][i] == 'P')
			{
				mlptr->pi = i;
				mlptr->pj = j;
			}
			i++;
		}
		j++;
	}
}
