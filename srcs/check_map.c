/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:56:02 by abonnard          #+#    #+#             */
/*   Updated: 2025/01/05 16:26:57 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return (0);
	if (map->plan[y][x] == '1' || map->plan[y][x] == 'C'
		|| map->plan[y][x] == 'E' || map->plan[y][x] == 'P')
		return (0);
	if (map->plan[y][x] == '0')
	{
		map->plan[y][x] = 'P';
		map->count++;
	}
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
	return (1);
}

int	map_is_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (map->plan[i])
	{
		if (ft_strlen(map->plan[i]) != (size_t)map->width)
			return (0);
		i++;
	}
	return (1);
}

int	check_border(t_map *map)
{
	int	i;

	i = 0;
	while (map->plan[0][i])
	{
		if (map->plan[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map->plan[map->height - 1][i])
	{
		if (map->plan[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->plan[i][0] != '1' || map->plan[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_map *map)
{
	if (!map_is_rectangular(map))
		return (0);
	if (!check_border(map))
		return (0);
	if (!multiple_player(map))
		return (0);
	if (!check_collectibles_exist(map))
		return (0);
	if (check_exit_accessible(map))
		return (1);
	if (check_path_valid(map))
		return (1);
	return (1);
}

int	read_map_line(t_map *map, int index)
{
	char	*line;

	line = get_next_line(map->fd);
	if (!line)
	{
		free(map->plan);
		return (0);
	}
	map->plan[index] = line;
	return (1);
}
