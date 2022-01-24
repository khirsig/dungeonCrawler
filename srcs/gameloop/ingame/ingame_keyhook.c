/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:35:30 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/24 01:00:15 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"

static void	ingame_player_movement_sprint(t_data *data)
{
	int	is_sprinting;

	is_sprinting = 0;
	if (IsKeyDown(KEY_LEFT_SHIFT))
		is_sprinting = 1;
	if (data->player.stamina < 0)
	{
		is_sprinting = 0;
		data->player.stamina = 0.0000;
	}
	if (data->player.stamina > 0.5 && is_sprinting == 1)
	{
		data->player.movementspeed = 0.12;
		data->player.stamina -= 0.5;
	}
	else if (data->player.stamina < data->player.max_stamina)
	{
		data->player.movementspeed = 0.08;
		data->player.stamina += 0.2;
	}
	else
		data->player.stamina = data->player.max_stamina;
}

static void	ingame_player_movement(t_data *data)
{
	ingame_player_movement_sprint(data);
	if (IsKeyDown(KEY_W))
	{
		float tempX = data->player.posX;
		float tempY = data->player.posY;
		data->player.posX += (data->player.dirX - data->player.posX) * data->player.movementspeed;
		data->player.posY += (data->player.dirY - data->player.posY) * data->player.movementspeed;
		data->player.dirX += (data->player.dirX - tempX) * data->player.movementspeed;
		data->player.dirY += (data->player.dirY - tempY) * data->player.movementspeed;
	}
	if (IsKeyDown(KEY_S))
	{
		float tempX = data->player.posX;
		float tempY = data->player.posY;
		data->player.posX -= (data->player.dirX - data->player.posX) * data->player.movementspeed;
		data->player.posY -= (data->player.dirY - data->player.posY) * data->player.movementspeed;
		data->player.dirX -= (data->player.dirX - tempX) * data->player.movementspeed;
		data->player.dirY -= (data->player.dirY - tempY) * data->player.movementspeed;
	}
	if (IsKeyDown(KEY_D))
	{
		data->player.posX += data->player.planeX * data->player.movementspeed;
		data->player.posY += data->player.planeY * data->player.movementspeed;
		data->player.dirX += data->player.planeX * data->player.movementspeed;
		data->player.dirY += data->player.planeY * data->player.movementspeed;
	}
	if (IsKeyDown(KEY_A))
	{
		data->player.posX -= data->player.planeX * data->player.movementspeed;
		data->player.posY -= data->player.planeY * data->player.movementspeed;
		data->player.dirX -= data->player.planeX * data->player.movementspeed;
		data->player.dirY -= data->player.planeY * data->player.movementspeed;
	}
}

static void	ingame_player_rotation(t_data *data)
{
	double temp;

	printf("Plane: [%f] [%f]\n", data->player.planeX, data->player.planeY);
	if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT))
	{
		temp = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(0.05) - data->player.planeY * sin(0.05);
		data->player.planeY = temp * sin(0.05) + data->player.planeY * cos(0.05);
		data->player.dirX = data->player.posX + data->player.planeX;
		data->player.dirY = data->player.posY + data->player.planeY;
	}
	if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT))
	{
		temp = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(-0.05) - data->player.planeY * sin(-0.05);
		data->player.planeY = -temp * sin(0.05) + data->player.planeY * cos(0.05);
		data->player.dirX = data->player.posX + data->player.planeX;
		data->player.dirY = data->player.posY + data->player.planeY;
	}
}
void	ingame_keyhook(t_data *data)
{
	ingame_player_movement(data);
	ingame_player_rotation(data);
}