/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:02:36 by abonnard          #+#    #+#             */
/*   Updated: 2025/01/05 18:26:18 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "keymap.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../.minilibx-linux/mlx_int.h"
# include "../.minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_texture
{
	void	*img;
	char	*data;
	int		bits;
	int		len;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_graph
{
	struct s_texture	wall;
	struct s_texture	coin;
	struct s_texture	floor;
	struct s_texture	black;
	struct s_texture	exit;
	struct s_texture	exit_open;
	struct s_texture	player;
}	t_graph;

typedef struct s_map
{
	int				fd;
	int				collec;
	int				start;
	int				exit;
	int				width;
	int				height;
	int				pos_x;
	int				pos_y;
	int				chunk_x;
	int				chunk_y;
	int				count;
	int				done;
	void			*mlx;
	void			*win;
	char			**plan;
	struct s_graph	graph;
}	t_map;

# define WIN_SIZE_X 600
# define WIN_SIZE_Y 600

int		close_game(void);
int		key_hook_close(int keycode);
void	get_player_pos(t_map *map);
int		map_is_rectangular(t_map *map);
int		parse_map(t_map *map, char *file);
int		multiple_player(t_map *map);
int		flood_fill(t_map *map, int x, int y);
int		check_map(t_map *map);
int		check_border(t_map *map);
int		allocate_map_plan(t_map *map);
int		parse_map_plan(t_map *map);
int		open_and_read_first_line(t_map *map, char *file, char **line);
int		parse_map_size(t_map *map, char *line);
int		read_map_line(t_map *map, int index);
int		check_exit_accessible(t_map *map);
int		check_multiple_exit(t_map *map);
int		check_exit_accessible(t_map *map);
int		check_path_valid(t_map *map);
int		check_collectibles_exist(t_map *map);
t_Llist	*store_collectibles(t_map *map);
int		load_all_textures(t_map *map);
void	free_textures(t_map *map);
int		handle_movement(int keycode, t_map *map);
void	render_map(t_map *map);
void	exit_solong(t_map *map);
void	render_map(t_map *map);
void	update_player_pos(t_map *map, int new_x, int new_y);
void	draw_tile(t_map *map, int x, int y);
void	initialize_game(t_map *map, char *file);
int		init_textures(t_map *map);
int		check_file_extension(char *file);
void	update_exit_texture(t_map *map);
void	put_exit_texture(t_map *map, int x, int y);

#endif
