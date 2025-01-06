/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_can_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:23:01 by abonnard          #+#    #+#             */
/*   Updated: 2025/01/06 14:50:10 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	find_exit_position(char **map, int *x, int *y)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (map[*y][*x] == 'E')
				return (1);
			(*x)++;
		}
		(*y)++;
	}
	return (0);
}

static int	check_exit_after_flood(char **map, int x, int y)
{
	if (map[y][x] != 'P')
	{
		ft_putstr_fd("Error\nExit is not accessible\n", 2);
		return (0);
	}
	return (1);
}

int	check_exit_accessible(t_map *map)
{
	int		x;
	int		y;
	char	**tmp_map;

	tmp_map = map->plan;
	if (!find_exit_position(tmp_map, &x, &y))
		return (0);
	if (!flood_fill(map, map->pos_x, map->pos_y))
		return (0);
	return (check_exit_after_flood(tmp_map, x, y));
}

static int	check_collectibles_reachable(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				ft_putstr_fd("Error\nCollectible not reachable\n", 2);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_path_valid(t_map *map)
{
	int		x;
	int		y;
	char	**tmp_map;

	tmp_map = map->plan;
	if (!find_exit_position(tmp_map, &x, &y))
		return (0);
	if (!flood_fill(map, map->pos_x, map->pos_y))
		return (0);
	if (!check_exit_after_flood(tmp_map, x, y))
		return (0);
	return (check_collectibles_reachable(tmp_map));
}
