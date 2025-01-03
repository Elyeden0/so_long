/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:30:44 by abonnard          #+#    #+#             */
/*   Updated: 2025/01/03 18:32:40 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"

static int	load_texture(t_map *map, t_texture *texture, char *path)
{
	int	width;
	int	height;

	texture->img = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	if (!texture->img)
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		ft_putendl_fd(path, 2);
		return (0);
	}
	texture->width = width;
	texture->height = height;
	return (1);
}

int	load_all_textures(t_map *map)
{
	if (!load_texture(map, &map->graph.wall, "textures/wall.xpm"))
		return (0);
	if (!load_texture(map, &map->graph.floor, "textures/floor.xpm"))
		return (0);
	if (!load_texture(map, &map->graph.coin, "textures/coin.xpm"))
		return (0);
	if (!load_texture(map, &map->graph.player, "textures/player.xpm"))
		return (0);
	if (!load_texture(map, &map->graph.exit, "textures/exit.xpm"))
		return (0);
	return (1);
}

void	free_textures(t_map *map)
{
	if (map->graph.wall.img)
		mlx_destroy_image(map->mlx, map->graph.wall.img);
	if (map->graph.floor.img)
		mlx_destroy_image(map->mlx, map->graph.floor.img);
	if (map->graph.coin.img)
		mlx_destroy_image(map->mlx, map->graph.coin.img);
	if (map->graph.player.img)
		mlx_destroy_image(map->mlx, map->graph.player.img);
	if (map->graph.exit.img)
		mlx_destroy_image(map->mlx, map->graph.exit.img);
}
