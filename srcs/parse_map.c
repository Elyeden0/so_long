/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:43:44 by abonnard          #+#    #+#             */
/*   Updated: 2025/01/03 16:03:00 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/get_next_line.h"

static int count_map_lines(char *file)
{
    int     fd;
    int     lines;
    char    *line;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    lines = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        lines++;
        free(line);
    }
    close(fd);
    return (lines);
}

static char *clean_line(char *line)
{
    char    *clean;
    int     len;

    if (!line)
        return (NULL);
    len = ft_strlen(line);
    if (line[len - 1] == '\n')
        line[len - 1] = '\0';
    clean = ft_strdup(line);
    free(line);
    return (clean);
}

static int read_map_to_array(t_map *map, char *file)
{
    int     fd;
    char    *line;
    int     i;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    i = 0;
    while (i < map->height)
    {
        line = get_next_line(fd);
        map->plan[i] = clean_line(line);
        if (!map->plan[i])
        {
            while (i > 0)
                free(map->plan[--i]);
            free(map->plan);
            close(fd);
            return (0);
        }
        i++;
    }
    close(fd);
    return (1);
}

int parse_map(t_map *map, char *file)
{
    map->height = count_map_lines(file);
    if (map->height <= 0)
        return (0);

    map->plan = ft_calloc(map->height + 1, sizeof(char *));
    if (!map->plan)
        return (0);

    if (!read_map_to_array(map, file))
        return (0);

    map->width = ft_strlen(map->plan[0]);
    if (!check_map(map))
    {
        int i = 0;
        while (i < map->height)
            free(map->plan[i++]);
        free(map->plan);
        return (0);
    }
    return (1);
}
