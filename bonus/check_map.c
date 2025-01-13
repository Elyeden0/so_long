/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:56:02 by abonnard          #+#    #+#             */
/*   Updated: 2025/01/13 11:19:06 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int flood_fill(char **map, int x, int y, int width, int height)
{
	if (x < 0 || y < 0 || x >= width || y >= height)
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'P' || map[y][x] == 'F')
		return (0);
	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E')
	{
		map[y][x] = 'F';
		flood_fill(map, x + 1, y, width, height);
		flood_fill(map, x - 1, y, width, height);
		flood_fill(map, x, y + 1, width, height);
		flood_fill(map, x, y - 1, width, height);
	}
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
	char	**tmp_map;
	int		valid;

	if (!map_is_rectangular(map))
		return (0);
	if (!check_border(map))
        return (0);
    if (!multiple_player(map))
        return (0);
    if (!check_multiple_exit(map))
        return (0);
    if (!check_collectibles_exist(map))
        return (0);

    // Create a copy of the map for flood fill
    tmp_map = copy_map(map);
    if (!tmp_map)
        return (0);

    // Check if player can reach exit and all collectibles
    valid = check_path_valid(tmp_map, map->pos_x, map->pos_y, map);

    // Free temporary map
    free_tmp_map(tmp_map, map->height);
    return (valid);
}

int	check_multiple_exit(t_map *map)
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
            if (map->plan[y][x] == 'E')
                count++;
            x++;
        }
        y++;
    }
    if (count != 1)
    {
        ft_putstr_fd("Error\nMap must have exactly one exit\n", 2);
        return (0);
    }
    return (1);
}

int	check_path_valid(char **map, int x, int y, t_map *original)
{
    int	collectibles;
    int	exit_found;

    collectibles = original->collec;
    exit_found = 0;

    flood_fill(map, x, y, original->width, original->height);

    // Check if all collectibles and exit are reachable
    for (int y = 0; y < original->height; y++)
    {
        for (int x = 0; x < original->width; x++)
        {
            if (original->plan[y][x] == 'C' && map[y][x] != 'F')
            {
                ft_putstr_fd("Error\nSome collectibles are not reachable\n", 2);
                return (0);
            }
            if (original->plan[y][x] == 'E' && map[y][x] != 'F')
            {
                ft_putstr_fd("Error\nExit is not reachable\n", 2);
                return (0);
            }
        }
    }
    return (1);
}

static char	**copy_map(t_map *map)
{
    char	**tmp;
    int		i;

    tmp = malloc(sizeof(char *) * (map->height + 1));
    if (!tmp)
        return (NULL);
    i = 0;
    while (i < map->height)
    {
        tmp[i] = ft_strdup(map->plan[i]);
        if (!tmp[i])
        {
            while (--i >= 0)
                free(tmp[i]);
            free(tmp);
            return (NULL);
        }
        i++;
    }
    tmp[i] = NULL;
    return (tmp);
}

static void	free_tmp_map(char **map, int height)
{
    int	i;

    i = 0;
    while (i < height)
        free(map[i++]);
    free(map);
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
