/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:17:53 by abonnard          #+#    #+#             */
/*   Updated: 2024/12/28 01:30:19 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int init_textures(t_map *map)
{
	int width;
	int height;

	map->graph.wall.img = mlx_xpm_file_to_image(map->mlx, "textures/wall.xpm", &width, &height);
	map->graph.floor.img = mlx_xpm_file_to_image(map->mlx, "textures/floor.xpm", &width, &height);
	map->graph.player.img = mlx_xpm_file_to_image(map->mlx, "textures/player.xpm", &width, &height);
	map->graph.exit.img = mlx_xpm_file_to_image(map->mlx, "textures/exit.xpm", &width, &height);
	map->graph.coin.img = mlx_xpm_file_to_image(map->mlx, "textures/coin.xpm", &width, &height);

	if (!map->graph.wall.img || !map->graph.floor.img || !map->graph.player.img ||
		!map->graph.exit.img || !map->graph.coin.img)
		return (0);
	return (1);
}

static int check_file_extension(char *filename)
{
	char *ext;

	ext = ft_strrchr(filename, '.');
	if (!ext || ft_strncmp(ext, ".ber", 5) != 0)
	{
		ft_putstr_fd("Error\nInvalid file extension (must be .ber)\n", 2);
		return (0);
	}
	return (1);
}

static void put_texture(t_map *map, void *img, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->win, img, x * 64, y * 64);
}

static void render_map(t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			mlx_put_image_to_window(map->mlx, map->win, map->graph.floor.img, x * 64, y * 64);
			if (map->plan[y][x] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->graph.wall.img, x * 64, y * 64);
			else if (map->plan[y][x] == 'P')
				mlx_put_image_to_window(map->mlx, map->win, map->graph.player.img, x * 64, y * 64);
			else if (map->plan[y][x] == 'E')
				mlx_put_image_to_window(map->mlx, map->win, map->graph.exit.img, x * 64, y * 64);
			else if (map->plan[y][x] == 'C')
				mlx_put_image_to_window(map->mlx, map->win, map->graph.coin.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int main(int ac, char **av)
{
	t_map map;

    if (ac != 2)
    {
        ft_putstr_fd("Error\nUsage: ./so_long maps/map_name.ber\n", 2);
        return (1);
    }
    if (!check_file_extension(av[1]))
        return (1);
    map.mlx = mlx_init();
    if (!map.mlx)
        return (1);
    if (!parse_map(&map, av[1]))
        return (1);
    int win_width = map.width * 64;
    int win_height = map.height * 64;
    map.win = mlx_new_window(map.mlx, win_width, win_height, "so_long");
    if (!map.win)
        return (1);
    if (!init_textures(&map))
        return (1);
    render_map(&map);
    mlx_hook(map.win, KeyPress, KeyPressMask, key_hook_close, &map);
    mlx_hook(map.win, DestroyNotify, StructureNotifyMask, close_game, &map);
    mlx_loop(map.mlx);
    return (0);
}
