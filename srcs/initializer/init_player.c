/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:39:41 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/24 01:01:01 by khirsig          ###   ########.fr       */
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
	// set_start_point(data);
	data->player.movementspeed = 0.08;
	data->player.max_health = 100.0000;
	data->player.health = data->player.max_health;
	data->player.max_stamina = 100.00000;
	data->player.stamina = data->player.max_stamina;
	data->player.posX = 4.0f;
	data->player.posY = 4.0f;
	// data->player.dirY = 5.0f;
	// data->player.dirX = 5.0f;
	data->player.planeX = 1.0f;
	data->player.planeY = -1.0f;
	data->player.dirX = data->player.posX + data->player.planeX;
	data->player.dirY = data->player.posY + data->player.planeY;
	data->player.camera.position = (Vector3){ data->player.posX, 2.0f, data->player.posY };
	data->player.camera.target = (Vector3){ data->player.dirX, 5.8f, data->player.dirY };
	data->player.camera.up = (Vector3){ 0.0f, -1.0f, 0.0f };
	data->player.camera.fovy = 60.0f;
	// data->player.camera.projection = CAMERA_PERSPECTIVE;
	// SetCameraMode(data->player.camera, CAMERA_FIRST_PERSON);
}