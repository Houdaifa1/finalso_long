/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:09:42 by hdrahm            #+#    #+#             */
/*   Updated: 2024/03/21 15:09:44 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_elements(t_info *info)
{
	if (info->p != 1)
	{
		if (info->p < 1)
			ft_printf("Error\nYou need to enter the Player : 'P'");
		else
			ft_printf("Error\nYou should enter just one Player");
		ft_free_arr(info->map);
		exit(1);
	}
	if (info->e != 1)
	{
		if (info->e < 1)
			ft_printf("Error\nYou need to enter the Exit : 'E'");
		else
			ft_printf("Error\nYou need to enter just one Exit");
		ft_free_arr(info->map);
		exit(1);
	}
	if (info->c < 1)
	{
		ft_printf("Error\nYou need to enter the coins in the map : 'C'");
		ft_free_arr(info->map);
		exit(1);
	}
}

static int	ft_nlenght(int n)
{
	unsigned int	count;
	long			x;

	x = n;
	count = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		if (x < 0)
		{
			x = -x;
			count++;
		}
		x = x / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	l;
	long			x;

	l = ft_nlenght(n);
	x = n;
	str = (char *)malloc(l + 1);
	if (str == NULL)
		return (NULL);
	if (x == 0)
		str[0] = '0';
	str[l] = '\0';
	while (x != 0)
	{
		if (x < 0)
		{
			x = -x;
			str[0] = '-';
		}
		str[l - 1] = (x % 10) + 48;
		x = x / 10;
		l--;
	}
	return (str);
}
