/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:25:32 by hdrahm            #+#    #+#             */
/*   Updated: 2024/03/21 00:25:50 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int arc, char **arv)
{
	int		i;
	int		j;
	char	*name;

	i = 0;
	j = 3;
	name = ".ber";
	if (arc == 2)
	{
		i = ft_strlen(arv[1]) - 1;
		while (j >= 0)
		{
			if (arv[1][i] != name[j])
			{
				ft_printf("The extention is wrong");
				exit(1);
			}
			j--;
			i--;
		}
		translate_map(arv[1]);
	}
	else
		ft_printf("Number of arguments not correct");
	return (0);
}
