/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:17:53 by abonnard          #+#    #+#             */
/*   Updated: 2025/01/05 14:15:22 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_textures(t_map *map)
{
	int	width;
	int	height;

	map->graph.wall.img = mlx_xpm_file_to_image(map->mlx,
			"textures/wall.xpm", &width, &height);
	map->graph.floor.img = mlx_xpm_file_to_image(map->mlx,
			"textures/floor.xpm", &width, &height);
	map->graph.player.img = mlx_xpm_file_to_image(map->mlx,
			"textures/player.xpm", &width, &height);
	map->graph.exit.img = mlx_xpm_file_to_image(map->mlx,
			"textures/exit.xpm", &width, &height);
	map->graph.coin.img = mlx_xpm_file_to_image(map->mlx,
			"textures/coin.xpm", &width, &height);
	if (!map->graph.wall.img || !map->graph.floor.img
		|| !map->graph.player.img
		||!map->graph.exit.img || !map->graph.coin.img)
		return (0);
	return (1);
}

int	check_file_extension(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext || ft_strncmp(ext, ".ber", 5) != 0)
	{
		ft_putstr_fd("Error\nInvalid file extension (must be .ber)\n", 2);
		return (0);
	}
	return (1);
}

void	render_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			draw_tile(map, x, y);
			x++;
		}
		y++;
	}
}

void	exit_solong(t_map *map)
{
	int	i;

	if (map->plan)
	{
		i = 0;
		while (i < map->height)
			free(map->plan[i++]);
		free(map->plan);
	}
	if (map->mlx)
	{
		free_textures(map);
		if (map->win)
			mlx_destroy_window(map->mlx, map->win);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	exit(0);
}

int	main(int ac, char **av)
{
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	if (ac != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long maps/map_name.ber\n", 2);
		return (1);
	}
	initialize_game(&map, av[1]);
	mlx_hook(map.win, 2, 1L << 0, handle_movement, &map);
	mlx_hook(map.win, DestroyNotify, StructureNotifyMask, close_game, &map);
	mlx_loop(map.mlx);
	return (0);
}
