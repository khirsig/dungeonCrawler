/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:10:13 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/24 17:50:12 by khirsig          ###   ########.fr       */
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
				DrawCubeTexture(data->game.wall[0], (Vector3){ x * 10, 0.0f, y * 10 }, 10.0f, 10.0f, 10.0f, WHITE);
			else if (data->map.grid[y][x] == '8')
				DrawCubeTexture(data->game.wall[1], (Vector3){ x * 10, 0.0f, y * 10 }, 10.0f, 10.0f, 10.0f, WHITE);
			else if (data->map.grid[y][x] == '9')
				DrawCubeTexture(data->game.wall[2], (Vector3){ x * 10, 0.0f, y * 10 }, 10.0f, 10.0f, 10.0f, WHITE);
			else
			{
				DrawCubeTexture(data->game.wall[0], (Vector3){ x * 10, -10.0f, y * 10 }, 10.0f, 10.0f, 10.0f, WHITE);
				DrawCubeTexture(data->game.wall[0], (Vector3){ x * 10, 10.0f, y * 10 }, 10.0f, 10.0f, 10.0f, WHITE);
			}
			x++;
		}
		y++;
	}
}