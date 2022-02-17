/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:39:41 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/16 14:52:09 by khirsig          ###   ########.fr       */
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

				data->player.posX = x * 10 + 5;
				data->player.posY = y * 10 + 5;
				data->player.posZ = 1.3f;
				data->player.dirZ = 1.3f;
				data->player.planeZ = 1.0f;
				data->player.planeX = 0.0f;
				data->player.planeY = 0.0f;
				if (data->map.grid[y][x] == 'N')
					data->player.planeY = -1.0f;
				if (data->map.grid[y][x] == 'S')
					data->player.planeY = 1.0f;
				if (data->map.grid[y][x] == 'W')
					data->player.planeX = -1.0f;
				if (data->map.grid[y][x] == 'E')
					data->player.planeX = 1.0f;
				data->player.dirX = data->player.posX + data->player.planeX;
				data->player.dirY = data->player.posY + data->player.planeY;
			}
			x++;
		}
		y++;
	}
}

void	init_player(t_data *data)
{
	set_start_point(data);
	data->player.is_sprinting = 0;
	data->player.max_health = 100.0000;
	data->player.health = data->player.max_health;
	data->player.max_stamina = 100.00000;
	data->player.stamina = data->player.max_stamina;
	data->player.camera.position = (Vector3){ data->player.posX, data->player.posZ, data->player.posY };
	data->player.camera.target = (Vector3){ data->player.dirX, data->player.dirZ, data->player.dirY };
	data->player.camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
	data->player.camera.fovy = SCREEN_FOV;
}