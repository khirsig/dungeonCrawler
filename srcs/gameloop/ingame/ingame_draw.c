/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:10:13 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/17 13:23:04 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"

static void	ingame_draw_npc(t_data *data, double div)
{
	Color	fade;
	int		index;
	int		min;
	double	dist_x;
	double	dist_y;

	index = 0;
	while (index < data->game.npc_count)
	{
			dist_x = data->player.posX / 10 - data->npc[index].pos.x / 10;
			if (dist_x < 0)
				dist_x *= -1;
			dist_y = data->player.posY / 10 - data->npc[index].pos.y / 10;
			if (dist_y < 0)
				dist_y *= -1;
			if (dist_y > dist_x)
				min = div * dist_y;
			else
				min = div * dist_x;
			if (min > 255)
				min = 255;
			if (min < 255)
			{
				fade = (Color){ 255 - min, 255 - min, 255 - min, 255 };
				DrawBillboard(data->player.camera, data->npc[index].texture[(int)data->npc[index].cycle], (Vector3) { data->npc[index].pos.x, data->npc[index].pos.z, data->npc[index].pos.y }, data->npc[index].size, fade);
			}
			index++;
	}
}

static void	ingame_draw_door(t_data *data, double div)
{
	Color	fade;
	int		index;
	int		min;
	double	dist_x;
	double	dist_y;

	index = 0;
	while (index < data->map.door_count)
	{
		dist_x = data->player.posX / 10 - data->map.door[index].x;
		if (dist_x < 0)
			dist_x *= -1;
		dist_y = data->player.posY / 10 - data->map.door[index].y;
		if (dist_y < 0)
			dist_y *= -1;
		if (dist_y > dist_x)
			min = div * dist_y;
		else
			min = div * dist_x;
		if (min > 255)
			min = 255;
		if (min < 255)
		{
			fade = (Color){ 255 - min, 255 - min, 255 - min, 255 };
			if (data->map.grid[data->map.door[index].y][data->map.door[index].x] == '-')
				DrawCubeTexture(data->game.wall[2], (Vector3){ data->map.door[index].x * 10, data->map.door[index].z, data->map.door[index].y * 10 - 5 }, 10.0f, 10.0f, 0.0f, fade);
			if (data->map.grid[data->map.door[index].y][data->map.door[index].x] == '_')
				DrawCubeTexture(data->game.wall[2], (Vector3){ data->map.door[index].x * 10, data->map.door[index].z, data->map.door[index].y * 10 + 5 }, 10.0f, 10.0f, 0.0f, fade);
			if (data->map.grid[data->map.door[index].y][data->map.door[index].x] == ']')
				DrawCubeTexture(data->game.wall[2], (Vector3){ data->map.door[index].x * 10 + 5, data->map.door[index].z, data->map.door[index].y * 10 }, 0.0f, 10.0f, 10.0f, fade);
			if (data->map.grid[data->map.door[index].y][data->map.door[index].x] == '[')
				DrawCubeTexture(data->game.wall[2], (Vector3){ data->map.door[index].x * 10 - 5, data->map.door[index].z, data->map.door[index].y * 10 }, 0.0f, 10.0f, 10.0f, fade);
		}
		index++;
	}
}

void	ingame_draw(t_data *data)
{
	Color fade;
	int	x;
	int	x_end;
	int	y;
	int	y_end;
	double	div;
	double	dist_x;
	double	dist_y;
	int	min;

	div = 255 / 100 * 20;
	if (data->player.posY / 10 - 6 < 0)
		y = 0;
	else
		y = data->player.posY / 10 - 6;
	if (data->player.posY / 10 + 6 > data->map.height - 1)
		y_end = data->map.height - 1;
	else
		y_end = data->player.posY / 10 + 6;
	if (data->player.posX / 10 + 6 > data->map.width - 1)
		x_end = data->map.width - 1;
	else
		x_end = data->player.posX / 10 + 6;
	while (y <= y_end)
	{
		if (data->player.posX / 10 - 6 < 0)
			x = 0;
		else
			x = data->player.posX / 10 - 6;
		while (x <= x_end)
		{
			dist_x = data->player.posX / 10 - x;
			if (dist_x < 0)
				dist_x *= -1;
			dist_y = data->player.posY / 10 - y;
			if (dist_y < 0)
				dist_y *= -1;
			if (dist_y > dist_x)
				min = div * dist_y;
			else
				min = div * dist_x;
			fade = (Color){ 255 - min, 255 - min, 255 - min, 255 };
			if (min <= 255)
			{
				if (data->map.grid[y][x] == '1')
					DrawCubeTexture(data->game.wall[0], (Vector3){ x * 10, 0.0f, y * 10 }, 10.0f, 10.0f, 10.0f, fade);
				else if (data->map.grid[y][x] == '8')
					DrawCubeTexture(data->game.wall[1], (Vector3){ x * 10, 0.0f, y * 10 }, 10.0f, 10.0f, 10.0f, fade);
				else if (data->map.grid[y][x] == '9')
					DrawCubeTexture(data->game.wall[0], (Vector3){ x * 10, 0.0f, y * 10 }, 10.0f, 10.0f, 10.0f, fade);
				else
				{
					DrawCubeTexture(data->game.wall[0], (Vector3){ x * 10, -10.0f, y * 10 }, 10.0f, 10.0f, 10.0f, fade);
					DrawCubeTexture(data->game.wall[0], (Vector3){ x * 10, 10.0f, y * 10 }, 10.0f, 10.0f, 10.0f, fade);
				}
			}
			x++;
		}
		y++;
	}
	ingame_draw_door(data, div);
	// if (data->game.npc_count >= 1)
	// 	ingame_draw_npc(data, div);
}