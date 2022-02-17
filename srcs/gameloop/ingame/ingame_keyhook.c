/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:35:30 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/17 13:23:36 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"

static int	get_door(t_data *data, int x, int y)
{
	int	index;

	index = 0;
	while (index < data->map.door_count)
	{
		if (data->map.door[index].x == x && data->map.door[index].y == y)
			return (index);
		index++;
	}
	return (-1);
}

static void	rotate_door(t_data *data)
{
	int index;

	index = 0;
	while (index < data->map.door_count)
	{
		if (data->map.door[index].state == OPENING && data->map.door[index].z < 10.0f)
			data->map.door[index].z += 0.10f;
		if (data->map.door[index].state == CLOSING && data->map.door[index].z > 0.0f)
			data->map.door[index].z -= 0.10f;
		if (data->map.door[index].z > 10.0f)
			data->map.door[index].z = 10.0f;
		if (data->map.door[index].z < 0.0f)
			data->map.door[index].z = 0.0f;
		index++;
	}
}

static void	ingame_player_actions(t_data *data)
{
	int	door_id;

	if (IsKeyPressed(KEY_F))
	{
		door_id = get_door(data, (int)(data->player.posX / 10 + data->player.planeX), (int)(data->player.posY / 10 + data->player.planeY));
		if (door_id != -1)
		{
			if (data->map.door[door_id].state == OPENING)
				data->map.door[door_id].state = CLOSING;
			else
				data->map.door[door_id].state = OPENING;
		}
	}
	rotate_door(data);
}

static void	ingame_player_movement_jump(t_data *data)
{
	if (data->player.is_jumping == 1)
	{
		if (data->player.posZ <= 3.00f)
		{
			data->player.posZ += 0.10f;
			data->player.dirZ += 0.10f;
		}
		else
			data->player.is_jumping = 2;
	}
	if (data->player.is_jumping == 2)
	{
		if (data->player.posZ > 0.00f)
		{
			data->player.posZ -= 0.10f;
			data->player.dirZ -= 0.10f;
		}
		else
		{
			data->player.posZ = 0.00f;
			data->player.dirZ = 0.00f;
			data->player.is_jumping = 0;
		}
	}
}

static void	ingame_player_movement_sprint(t_data *data)
{
	if (IsKeyPressed(KEY_LEFT_SHIFT))
	{
		data->player.is_sprinting = 1;
		data->player.movementspeed = 0.16;
	}
	if (IsKeyReleased(KEY_LEFT_SHIFT))
	{
		data->player.is_sprinting = 0;
		data->player.movementspeed = 0.08;
	}
	if (data->player.is_sprinting == 0 && data->player.stamina < data->player.max_stamina)
		data->player.stamina += 0.15;
	if (data->player.stamina > data->player.max_stamina)
		data->player.stamina = data->player.max_stamina;
	if (data->player.is_sprinting == 1 && data->player.stamina > 0.99)
		data->player.stamina -= 0.20;
	if (data->player.is_sprinting == 1 && data->player.stamina <= 0.99)
	{
		data->player.is_sprinting = 0;
		data->player.movementspeed = 0.08;
	}
}
static int	is_door_open(t_data *data, int x, int y)
{
	int	index;

	index = 0;
	while (index < data->map.door_count)
	{
		if (data->map.door[index].x == x && data->map.door[index].y == y && data->map.door[index].z >= 8.0f)
			return (1);
		index++;
	}
	return (0);
}

static int	collision_check(t_data *data, char dest, int x, int y)
{
	if (dest == '1' || dest == '8' || dest == '9')
		return (1);
	if ((dest == '[' || dest == ']' || dest == '-' || dest == '_') && is_door_open(data, x, y) == 1)
		return (1);
	return (0);
}

static void	ingame_player_movement(t_data *data)
{
	int	colX;
	int	colY;

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
	if (IsKeyDown(KEY_A))
	{
		data->player.posX += data->player.planeY * data->player.movementspeed;
		data->player.posY -= data->player.planeX * data->player.movementspeed;
		data->player.dirX += data->player.planeY * data->player.movementspeed;
		data->player.dirY -= data->player.planeX * data->player.movementspeed;
	}
	if (IsKeyDown(KEY_D))
	{
		data->player.posX -= data->player.planeY * data->player.movementspeed;
		data->player.posY += data->player.planeX * data->player.movementspeed;
		data->player.dirX -= data->player.planeY * data->player.movementspeed;
		data->player.dirY += data->player.planeX * data->player.movementspeed;
	}
	if (IsKeyPressed(KEY_SPACE))
		data->player.is_jumping = 1;
}

static void	ingame_player_rotation(t_data *data)
{
	double temp;

	if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT))
	{
		temp = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(data->player.rotatespeed) - data->player.planeY * sin(data->player.rotatespeed);
		data->player.planeY = temp * sin(data->player.rotatespeed) + data->player.planeY * cos(data->player.rotatespeed);
		data->player.dirX = data->player.posX + data->player.planeX;
		data->player.dirY = data->player.posY + data->player.planeY;
	}
	if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT))
	{
		temp = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(-data->player.rotatespeed) - data->player.planeY * sin(-data->player.rotatespeed);
		data->player.planeY = -temp * sin(data->player.rotatespeed) + data->player.planeY * cos(data->player.rotatespeed);
		data->player.dirX = data->player.posX + data->player.planeX;
		data->player.dirY = data->player.posY + data->player.planeY;
	}
}

void	ingame_keyhook(t_data *data)
{
	ingame_player_movement(data);
	ingame_player_movement_jump(data);
	ingame_player_rotation(data);
	ingame_player_actions(data);
	inventory_open(data);
}