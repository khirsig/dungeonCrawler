/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:35:30 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 15:54:12 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"

static void	ingame_player_movement(t_data *data)
{
	if (IsKeyDown(KEY_W))
	{
		data->player.posX += data->player.dirX * data->player.movementspeed;
		data->player.posY += data->player.dirY * data->player.movementspeed;
	}
	if (IsKeyDown(KEY_S))
	{
		data->player.posX -= data->player.dirX * data->player.movementspeed;
		data->player.posY -= data->player.dirY * data->player.movementspeed;
	}
	if (IsKeyDown(KEY_D))
	{
		data->player.posX += data->player.planeX * data->player.movementspeed;
		data->player.posY += data->player.planeY * data->player.movementspeed;
	}
	if (IsKeyDown(KEY_A))
	{
		data->player.posX -= data->player.planeX * data->player.movementspeed;
		data->player.posY -= data->player.planeY * data->player.movementspeed;
	}
}

static void	ingame_player_rotation(t_data *data)
{
	double temp;

	if (IsKeyDown(KEY_LEFT))
	{
		temp = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(0.05) - data->player.dirY * sin(0.05);
		data->player.dirY = temp * sin(0.05) + data->player.dirY * cos(0.05);
		temp = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(0.05) - data->player.planeY * sin(0.05);
		data->player.planeY = temp * sin(0.05) + data->player.planeY * cos(0.05);
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		temp = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(-0.05) - data->player.dirY * sin(-0.05);
		data->player.dirY = temp * sin(-0.05) + data->player.dirY * cos(-0.05);
		temp = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(-0.05) - data->player.planeY * sin(-0.05);
		data->player.planeY = temp * sin(-0.05) + data->player.planeY * cos(-0.05);
	}
}
void	ingame_keyhook(t_data *data)
{
	ingame_player_movement(data);
	ingame_player_rotation(data);
}