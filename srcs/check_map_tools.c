/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:58:26 by abonnard          #+#    #+#             */
/*   Updated: 2025/01/13 11:58:53 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_tmp_map(char **map, int height)
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
