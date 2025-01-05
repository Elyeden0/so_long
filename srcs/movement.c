/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:00:41 by abonnard          #+#    #+#             */
/*   Updated: 2025/01/05 17:59:29 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_valid_move(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return (0);
	if (map->plan[y][x] == '1')
		return (0);
	return (1);
}

void	update_exit_texture(t_map *map)
{
	int	x;
	int	y;

	if (map->collec == 0)
	{
		y = 0;
		while (y < map->height)
		{
			x = 0;
			while (x < map->width)
			{
				if (map->plan[y][x] == 'E')
				{
					mlx_put_image_to_window(map->mlx, map->win,
						map->collec == 0 ? map->graph.exit_open.img
						: map->graph.exit.img, x * 64, y * 64);
				}
				x++;
			}
			y++;
		}
	}


}

static void	handle_collectible(t_map *map, int x, int y)
{
	if (map->plan[y][x] == 'C')
	{
		map->collec--;
		map->plan[y][x] = '0';
		update_exit_texture(map);
	}
}

void	update_player_pos(t_map *map, int new_x, int new_y)
{
	static int	was_exit = 0;

	handle_collectible(map, new_x, new_y);
	if (was_exit)
		map->plan[map->pos_y][map->pos_x] = 'E';
	else
		map->plan[map->pos_y][map->pos_x] = '0';
	was_exit = (map->plan[new_y][new_x] == 'E');
	map->pos_x = new_x;
	map->pos_y = new_y;
	if (was_exit && map->collec == 0)
	{
		ft_putstr_fd("Congratulations! You won!\n", 1);
		exit_solong(map);
	}
	map->plan[new_y][new_x] = 'P';
	map->count++;
	ft_putnbr_fd(map->count, 1);
	ft_putchar_fd('\n', 1);
}

int	handle_movement(int keycode, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = map->pos_x;
	new_y = map->pos_y;
	if (keycode == KEY_W || keycode == KEY_UP)
		new_y--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		new_y++;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		new_x--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		new_x++;
	else if (keycode == KEY_ESC)
		exit_solong(map);
	else
		return (0);
	if (is_valid_move(map, new_x, new_y))
	{
		update_player_pos(map, new_x, new_y);
		render_map(map);
	}
	return (0);
}
