/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:08:52 by abonnard          #+#    #+#             */
/*   Updated: 2025/01/06 18:34:09 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include "../libft/get_next_line.h"

int	close_game(void)
{
	exit(0);
}

int	key_hook_close(int keycode)
{
	if (keycode == KEY_ESC)
		close_game();
	return (0);
}

static void coin_animation(t_map *map)
{
	int i;

	i = 0;
	if (i == 0)
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.coin0.img, 0, 0);
	else if (i == 1)
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.coin1.img, 0, 0);
	else if (i == 2)
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.coin2.img, 0, 0);
	else if (i == 3)
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.coin3.img, 0, 0);
	else if (i == 4)
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.coin4.img, 0, 0);
	else if (i == 5)
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.coin5.img, 0, 0);
	else if (i == 6)
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.coin6.img, 0, 0);
	else if (i == 7)
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.coin7.img, 0, 0);
	i++;
	if (i == 8)
		i = 0;
	usleep(100000);
}

void	draw_tile(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->win,
		map->graph.floor.img, x * 64, y * 64);
	if (map->plan[y][x] == '1')
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.wall.img, x * 64, y * 64);
	else if (map->plan[y][x] == 'P')
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.player.img, x * 64, y * 64);
	else if (map->plan[y][x] == 'E')
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.exit.img, x * 64, y * 64);
	else if (map->plan[y][x] == 'C')
		coin_animation(map);
}

void	initialize_game(t_map *map, char *file)
{
	int	win_width;
	int	win_height;

	if (!check_file_extension(file))
		exit_solong(map);
	map->mlx = mlx_init();
	if (!map->mlx || !parse_map(map, file))
	{
		ft_putstr_fd("Error\nInvalid map, please put a valid map\n", 2);
		exit_solong(map);
	}
	while(True)
	{
		get_player_pos(map);
		update_player_pos(map, map->pos_x, map->pos_y);
		win_width = map->width * 64;
		win_height = map->height * 64;
		map->win = mlx_new_window(map->mlx, win_width, win_height, "so_long");
		if (!map->win || !init_textures(map))
			exit_solong(map);
		render_map(map);
	}

}
