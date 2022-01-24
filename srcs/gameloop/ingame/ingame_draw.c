/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:51:13 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/22 20:04:57 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"

void	ingame_draw(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x] == '1')
				DrawCubeTexture(data->game.wall[0], (Vector3){ x * 5, 0.0f, y * 5 }, 5.0f, 5.0f, 5.0f, WHITE);
			if (data->map.grid[y][x] == '0')
			{
				DrawCubeTexture(data->game.wall[0], (Vector3){ x * 5, -5.0f, y * 5 }, 5.0f, 5.0f, 5.0f, WHITE);
				DrawCubeTexture(data->game.wall[0], (Vector3){ x * 5, 5.0f, y * 5 }, 5.0f, 5.0f, 5.0f, WHITE);
			}
			if (data->map.grid[y][x] == '8')
				DrawCubeTexture(data->game.wall[1], (Vector3){ x * 5, 0.0f, y * 5 }, 5.0f, 5.0f, 5.0f, WHITE);
			if (data->map.grid[y][x] == '9')
				DrawCubeTexture(data->game.wall[2], (Vector3){ x * 5, 0.0f, y * 5 }, 5.0f, 5.0f, 5.0f, WHITE);
			x++;
		}
		y++;
	}
}