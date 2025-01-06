/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_and_coll.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2024/12/20 15:56:53 by abonnard          #+#    #+#             */
/*   Updated: 2024/12/20 16:06:24 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
		return (0);
	return (1);
}

int	check_collectibles_exist(t_map *map)
{
	int	x;
	int	y;
	int	found;

	found = 0;
	y = 0;
	while (map->plan[y])
	{
		x = 0;
		while (map->plan[y][x])
		{
			if (map->plan[y][x] == 'C')
				found = 1;
			x++;
		}
		y++;
	}
	if (!found)
	{
		ft_putstr_fd("Error\nNo collectibles found in map\n", 2);
		return (0);
	}
	return (1);
}

static int	add_collectible(t_Llist **collectibles, int x, int y)
{
	t_coord	*coord;
	t_Llist	*new_node;

	coord = malloc(sizeof(t_coord));
	if (!coord)
		return (0);
	coord->x = x;
	coord->y = y;
	new_node = ft_lstnew(coord);
	if (!new_node)
	{
		free(coord);
		return (0);
	}
	ft_lstadd_back(collectibles, new_node);
	return (1);
}

t_Llist	*store_collectibles(t_map *map)
{
	int		x;
	int		y;
	t_Llist	*collectibles;

	collectibles = NULL;
	y = 0;
	while (map->plan[y])
	{
		x = 0;
		while (map->plan[y][x])
		{
			if (map->plan[y][x] == 'C')
				if (!add_collectible(&collectibles, x, y))
					return (NULL);
			x++;
		}
		y++;
	}
	return (collectibles);
}
