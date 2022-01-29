/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:10:13 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/26 09:30:22 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"

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
			fade = (Color){ 255 - min, 255 - min, 255 - min, 255 };
		if (data->map.grid[data->map.door[index].y][data->map.door[index].x] == '-')
			DrawCubeTexture(data->game.wall[2], (Vector3){ data->map.door[index].x * 10, data->map.door[index].z, data->map.door[index].y * 10 - 5 }, 10.0f, 10.0f, 0.0f, fade);
		if (data->map.grid[data->map.door[index].y][data->map.door[index].x] == '_')
			DrawCubeTexture(data->game.wall[2], (Vector3){ data->map.door[index].x * 10, data->map.door[index].z, data->map.door[index].y * 10 + 5 }, 10.0f, 10.0f, 0.0f, fade);
		if (data->map.grid[data->map.door[index].y][data->map.door[index].x] == ']')
			DrawCubeTexture(data->game.wall[2], (Vector3){ data->map.door[index].x * 10 + 5, data->map.door[index].z, data->map.door[index].y * 10 }, 0.0f, 10.0f, 10.0f, fade);
		if (data->map.grid[data->map.door[index].y][data->map.door[index].x] == '[')
			DrawCubeTexture(data->game.wall[2], (Vector3){ data->map.door[index].x * 10 - 5, data->map.door[index].z, data->map.door[index].y * 10 }, 0.0f, 10.0f, 10.0f, fade);
		index++;
	}
}

void	ingame_draw(t_data *data)
{
	Color fade;
	int	x;
	int	y;
	double	div;
	double	dist_x;
	double	dist_y;
	int	min;

	div = 255 / 100 * 20;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
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
}