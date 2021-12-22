/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:39:41 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 17:53:40 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

static void set_start_point(t_data *data)
{
	int	x;
	int y;

	y = 0;
	while (data->map.grid[y] != NULL)
	{
		x = 0;
		while (data->map.grid[y][x] != '\0')
		{
			if (data->map.grid[y][x] == 'N' || data->map.grid[y][x] == 'S'
				|| data->map.grid[y][x] == 'E' || data->map.grid[y][x] == 'W')
			{
				data->player.posX = x + 0.50;
				data->player.posY = y + 0.50;
				data->player.planeX = -0.66;
				data->player.dirY = -1;
			}
			x++;
		}
		y++;
	}
}

void	init_player(t_data *data)
{
	set_start_point(data);
	data->player.movementspeed = 0.05;
	data->player.max_health = 100.0000;
	data->player.health = data->player.max_health;
	data->player.max_stamina = 100.00000;
	data->player.stamina = data->player.max_stamina;
}