/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enemys_around.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:36:57 by hdrahm            #+#    #+#             */
/*   Updated: 2024/03/22 00:37:01 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemys_a(int j, int i, t_mlptr *mlptr)
{
	ft_move_enemy_left(j, i, mlptr);
	ft_move_enemy_right(j, i, mlptr);
	ft_move_enemy_up(j, i, mlptr);
	ft_move_enemy_down(j, i, mlptr);
	printf("the player moves   %d\n", mlptr->moves);
}

void	enemys_d(int j, int i, t_mlptr *mlptr)
{
	ft_move_enemy_right(j, i, mlptr);
	ft_move_enemy_left(j, i, mlptr);
	ft_move_enemy_up(j, i, mlptr);
	ft_move_enemy_down(j, i, mlptr);
	printf("the player moves   %d\n", mlptr->moves);
}

void	enemys_w(int j, int i, t_mlptr *mlptr)
{
	ft_move_enemy_up(j, i, mlptr);
	ft_move_enemy_left(j, i, mlptr);
	ft_move_enemy_right(j, i, mlptr);
	ft_move_enemy_down(j, i, mlptr);
	printf("the player moves   %d\n", mlptr->moves);
}

void	enemys_s(int j, int i, t_mlptr *mlptr)
{
	ft_move_enemy_down(j, i, mlptr);
	ft_move_enemy_left(j, i, mlptr);
	ft_move_enemy_up(j, i, mlptr);
	ft_move_enemy_right(j, i, mlptr);
	printf("the player moves   %d\n", mlptr->moves);
}
