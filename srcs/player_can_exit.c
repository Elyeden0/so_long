/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_can_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:23:01 by abonnard          #+#    #+#             */
/*   Updated: 2025/01/13 11:39:22 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int check_path_valid(t_map *map)
{
    t_map	tmp;
    int		x;
    int		y;
    int		valid;

    ft_memset(&tmp, 0, sizeof(t_map));
    tmp.width = map->width;
    tmp.height = map->height;
    tmp.plan = copy_map(map);
    if (!tmp.plan)
        return (0);

    // Get player position
    get_player_pos(&tmp);

    // Perform flood fill from player position
    flood_fill(&tmp, tmp.pos_x, tmp.pos_y);

    y = -1;
    valid = 1;
    while (++y < map->height && valid)
    {
        x = -1;
        while (++x < map->width && valid)
        {
            if ((map->plan[y][x] == 'C' || map->plan[y][x] == 'E')
                && tmp.plan[y][x] != 'F')
            {
                ft_putstr_fd("Error\nNot all collectibles/exit are reachable\n", 2);
                valid = 0;
            }
        }
    }
    free_tmp_map(tmp.plan, map->height);
    return (valid);
}
