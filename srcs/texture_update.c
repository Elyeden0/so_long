/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:24:02 by abonnard          #+#    #+#             */
/*   Updated: 2025/01/05 18:27:24 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_exit_texture(t_map *map, int x, int y)
{
	if (map->collec == 0)
	{
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.exit_open.img, x * 64, y * 64);
	}
	else
	{
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.exit.img, x * 64, y * 64);
	}
}

void	update_exit_texture(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->plan[y][x] == 'E')
			{
				put_exit_texture(map, x, y);
			}
			x++;
		}
		y++;
	}
}
