/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:30:44 by abonnard          #+#    #+#             */
/*   Updated: 2025/01/06 18:19:52 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
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

static int	load_coin_texture(t_map *map)
{
	if (!load_texture(map, &map->graph.coin0, "textures/coin0.xpm"))
		return (0);
	if (!load_texture(map, &map->graph.coin1, "textures/coin1.xpm"))
		return (0);
	if (!load_texture(map, &map->graph.coin2, "textures/coin2.xpm"))
		return (0);
	if (!load_texture(map, &map->graph.coin3, "textures/coin3.xpm"))
		return (0);
	if (!load_texture(map, &map->graph.coin4, "textures/coin4.xpm"))
		return (0);
	if (!load_texture(map, &map->graph.coin5, "textures/coin5.xpm"))
		return (0);
	if (!load_texture(map, &map->graph.coin6, "textures/coin6.xpm"))
		return (0);
	if (!load_texture(map, &map->graph.coin7, "textures/coin7.xpm"))
		return (0);
	return (1);
}

int	load_all_textures(t_map *map)
{
	if (!load_texture(map, &map->graph.wall, "textures/wall.xpm"))
		return (0);
	if (!load_texture(map, &map->graph.floor, "textures/floor.xpm"))
		return (0);
	if (!load_texture(map, &map->graph.player, "textures/player.xpm"))
		return (0);
	if (!load_texture(map, &map->graph.exit, "textures/exit.xpm"))
		return (0);
	load_coin_texture(map);
	return (1);
}

static void	free_coin_textures(t_map map)
{
	if (map.graph.coin0.img)
		mlx_destroy_image(map.mlx, map.graph.coin0.img);
	if (map.graph.coin1.img)
		mlx_destroy_image(map.mlx, map.graph.coin1.img);
	if (map.graph.coin2.img)
		mlx_destroy_image(map.mlx, map.graph.coin2.img);
	if (map.graph.coin3.img)
		mlx_destroy_image(map.mlx, map.graph.coin3.img);
	if (map.graph.coin4.img)
		mlx_destroy_image(map.mlx, map.graph.coin4.img);
	if (map.graph.coin5.img)
		mlx_destroy_image(map.mlx, map.graph.coin5.img);
	if (map.graph.coin6.img)
		mlx_destroy_image(map.mlx, map.graph.coin6.img);
	if (map.graph.coin7.img)
		mlx_destroy_image(map.mlx, map.graph.coin7.img);
}

void	free_textures(t_map *map)
{
	if (map->graph.wall.img)
		mlx_destroy_image(map->mlx, map->graph.wall.img);
	if (map->graph.floor.img)
		mlx_destroy_image(map->mlx, map->graph.floor.img);
	if (map->graph.player.img)
		mlx_destroy_image(map->mlx, map->graph.player.img);
	if (map->graph.exit.img)
		mlx_destroy_image(map->mlx, map->graph.exit.img);
	free_coin_textures(*map);
}
