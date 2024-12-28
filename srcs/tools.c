/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:08:52 by abonnard          #+#    #+#             */
/*   Updated: 2024/12/20 11:11:13 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/get_next_line.h"

int	close_game(void)
{
	exit(0);
}

int	key_hook_close(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		close_game();
	return (0);
}
