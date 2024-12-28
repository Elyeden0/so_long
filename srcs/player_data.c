/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:08:31 by abonnard          #+#    #+#             */
/*   Updated: 2024/12/19 16:12:03 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_player_pos(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->plan[y])
	{
		x = 0;
		while (map->plan[y][x])
		{
			if (map->plan[y][x] == 'P')
			{
				map->pos_x = x;
				map->pos_y = y;
				map->plan[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

int	multiple_player(t_map *map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (map->plan[y])
	{
		x = 0;
		while (map->plan[y][x])
		{
			if (map->plan[y][x] == 'P')
				count++;
			x++;
		}
		y++;
	}
	if (count != 1)
		return (0);
	return (1);
}
