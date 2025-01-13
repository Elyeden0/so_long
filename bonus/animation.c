/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:59:19 by abonnard          #+#    #+#             */
/*   Updated: 2025/01/08 10:03:48 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	init_coin_texture(t_map *map)
{
	int	width;
	int	height;

	map->graph.coin0.img = mlx_xpm_file_to_image(map->mlx,
			"textures/coin0.xpm", &width, &height);
	map->graph.coin1.img = mlx_xpm_file_to_image(map->mlx,
			"textures/coin1.xpm", &width, &height);
	map->graph.coin2.img = mlx_xpm_file_to_image(map->mlx,
			"textures/coin2.xpm", &width, &height);
	map->graph.coin3.img = mlx_xpm_file_to_image(map->mlx,
			"textures/coin3.xpm", &width, &height);
	map->graph.coin4.img = mlx_xpm_file_to_image(map->mlx,
			"textures/coin4.xpm", &width, &height);
	map->graph.coin5.img = mlx_xpm_file_to_image(map->mlx,
			"textures/coin5.xpm", &width, &height);
	map->graph.coin6.img = mlx_xpm_file_to_image(map->mlx,
			"textures/coin6.xpm", &width, &height);
	map->graph.coin7.img = mlx_xpm_file_to_image(map->mlx,
			"textures/coin7.xpm", &width, &height);
	if (!map->graph.coin0.img || !map->graph.coin1.img
		|| !map->graph.coin2.img || !map->graph.coin3.img
		|| !map->graph.coin4.img || !map->graph.coin5.img
		|| !map->graph.coin6.img || !map->graph.coin7.img)
		return (0);
	return (1);
}

static void coin_frame(t_map *map, int frame)
{
    int x, y;

    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->plan[y][x] == 'C')
            {
                if (frame == 0)
                    mlx_put_image_to_window(map->mlx, map->win, map->graph.coin0.img, x * 64, y * 64);
                else if (frame == 1)
                    mlx_put_image_to_window(map->mlx, map->win, map->graph.coin1.img, x * 64, y * 64);
                else if (frame == 2)
                    mlx_put_image_to_window(map->mlx, map->win, map->graph.coin2.img, x * 64, y * 64);
                else if (frame == 3)
                    mlx_put_image_to_window(map->mlx, map->win, map->graph.coin3.img, x * 64, y * 64);
                else if (frame == 4)
                    mlx_put_image_to_window(map->mlx, map->win, map->graph.coin4.img, x * 64, y * 64);
                else if (frame == 5)
                    mlx_put_image_to_window(map->mlx, map->win, map->graph.coin5.img, x * 64, y * 64);
                else if (frame == 6)
                    mlx_put_image_to_window(map->mlx, map->win, map->graph.coin6.img, x * 64, y * 64);
                else if (frame == 7)
                    mlx_put_image_to_window(map->mlx, map->win, map->graph.coin7.img, x * 64, y * 64);
            }
            x++;
        }
        y++;
    }
}

void coin_animation(t_map *map)
{
    static int frame = 0;

    coin_frame(map, frame);
    frame++;
    if (frame == 8)
        frame = 0;
}

int	update_animation(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	coin_animation(map);
	render_map(map);
	return (0);
}
