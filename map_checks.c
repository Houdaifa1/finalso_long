/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:23:47 by hdrahm            #+#    #+#             */
/*   Updated: 2024/03/21 00:23:50 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_coins(char **map, t_info *info)
{
	int	j;
	int	i;

	j = 0;
	while (j < info->high)
	{
		i = 0;
		while (i < info->size)
		{
			if (map[j][i] == 'C')
			{
				info->x = 'C';
				if (check_path_to_p(map, j, i, info) != 1)
				{
					ft_printf("Error\nThere is no Valid path to the coins");
					ft_free_arr(map);
					exit(1);
				}
				reset_map(map, info);
			}
			i++;
		}
		j++;
	}
	put_images(info);
}

void	check_exit(char **map, t_info *info)
{
	int	i;
	int	j;

	j = 0;
	while (j < info->high)
	{
		i = 0;
		while (i < info->size)
		{
			if (map[j][i] == 'E')
			{
				info->x = 'P';
				if (check_path_to_p(map, j, i, info) != 1)
				{
					ft_printf("Error\nThere is no valid path to the exit ");
					ft_free_arr(info->map);
					exit(1);
				}
			}
			i++;
		}
		j++;
	}
	reset_map(map, info);
	check_coins(map, info);
}

void	count_elements(char **map, t_info *info)
{
	int	i;
	int	j;

	j = 0;
	info->c = 0;
	info->e = 0;
	info->p = 0;
	while (j < info->high)
	{
		i = 0;
		while (i < info->size)
		{
			if (map[j][i] == 'P')
				info->p++;
			if (map[j][i] == 'C')
				info->c++;
			if (map[j][i] == 'E')
				info->e++;
			i++;
		}
		j++;
	}
}

void	verify_elements(char **map, t_info *info)
{
	int	i;
	int	j;

	j = 0;
	while (j < info->high)
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != 'P' && map[j][i] != 'C' && map[j][i] != '0'
				&& map[j][i] != '1' && map[j][i] != 'E' && map[j][i] != 'V')
			{
				ft_printf("Error\nThere is an element other than 0,1,P,C,E,V");
				ft_free_arr(info->map);
				exit(1);
			}
			i++;
		}
		j++;
	}
	check_angle(map, info);
	check_borders(map, info);
	count_elements(map, info);
	check_elements(info);
	check_exit(map, info);
}

void	translate_map(char *name)
{
	char	*temp;
	t_info	info;
	int		i;

	info.fd = open(name, O_RDONLY);
	info.high = 0;
	temp = get_the_map_in_oneline(&info);
	if (temp == NULL)
	{
		ft_printf("Error\nThe file containing the map is wrong");
		exit(1);
	}
	i = ft_strlen(temp);
	if (temp[i - 1] == '\n')
	{
		ft_printf("Error\nThere is an empty line");
		free(temp);
		exit(1);
	}
	info.map = ft_split(temp, '\n');
	free(temp);
	verify_elements(info.map, &info);
	ft_free_arr(info.map);
}
