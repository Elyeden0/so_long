/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:43:44 by abonnard          #+#    #+#             */
/*   Updated: 2024/12/20 11:07:50 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/get_next_line.h"

int	allocate_map_plan(t_map *map)
{
	map->plan = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->plan)
		return (0);
	return (1);
}

int	parse_map_plan(t_map *map)
{
	if (!allocate_map_plan(map))
		return (0);
	if (!read_map_line(map, 0))
		return (0);
	map->width = ft_strlen(map->plan[0]);
	map->chunk_y = 1;
	while (map->chunk_y < map->height)
	{
		if (!read_map_line(map, map->chunk_y))
			return (0);
		map->chunk_y++;
	}
	return (1);
}

int	parse_map_size(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	map->height = ft_atoi(line);
	if (map->height < 1)
		return (0);
	return (1);
}

int	open_and_read_first_line(t_map *map, char *file, char **line)
{
	map->fd = open(file, O_RDONLY);
	if (map->fd < 0)
		return (0);
	*line = get_next_line(map->fd);
	if (!*line)
	{
		close(map->fd);
		return (0);
	}
	return (1);
}

int	parse_map(t_map *map, char *file)
{
	char	*line;

	if (!open_and_read_first_line(map, file, &line))
		return (0);
	if (!parse_map_size(map, line))
	{
		free(line);
		close(map->fd);
		return (0);
	}
	free(line);
	if (!parse_map_plan(map))
	{
		close(map->fd);
		return (0);
	}
	if (!check_map(map))
	{
		close(map->fd);
		return (0);
	}
	get_player_pos(map);
	close(map->fd);
	return (1);
}
