/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:51:13 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 15:56:42 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"

static void	draw_ver_line(t_data *data, int x)
{
	int	y;

	y = 0;
	// printf("%i < %i | x = %i\n", data->game.ray.drawStart, data->game.ray.drawEnd, x);
	while (y < data->game.ray.drawStart)
	{
		DrawPixel(x, y, BLACK);
		y++;
	}
	while (data->game.ray.drawStart <= data->game.ray.drawEnd)
	{
		if (data->game.ray.side == 1 && data->game.ray.hit == 1)
			DrawPixel(x, data->game.ray.drawStart, MAROON);
		else if (data->game.ray.side == 0 && data->game.ray.hit == 1)
			DrawPixel(x, data->game.ray.drawStart, RED);
		else
			DrawPixel(x, data->game.ray.drawStart, LIME);
		data->game.ray.drawStart++;
	}
	y = data->game.ray.drawEnd + 1;
	while (y < data->window.width)
	{
		DrawPixel(x, y, BLACK);
		y++;
	}
}

void	ingame_draw(t_data *data)
{
	int x;

	x = 0;
	while (x < data->window.width)
	{
		data->game.ray.cameraX = 2 * x / (double)data->window.width - 1;
		data->game.ray.dirX = data->player.dirX + data->player.planeX * data->game.ray.cameraX;
		data->game.ray.dirY = data->player.dirY + data->player.planeY * data->game.ray.cameraX;
		data->game.ray.mapX = (int) data->player.posX;
		data->game.ray.mapY = (int) data->player.posY;
		if (data->game.ray.dirX == 0)
			data->game.ray.deltaDistX = 1e30;
		else
			data->game.ray.deltaDistX = fabs(1 / data->game.ray.dirX);
		if (data->game.ray.dirY == 0)
			data->game.ray.deltaDistY = 1e30;
		else
			data->game.ray.deltaDistY = fabs(1 / data->game.ray.dirY);
		if (data->game.ray.dirX < 0)
		{
			data->game.ray.stepX = -1;
			data->game.ray.sideDistX = (data->player.posX - data->game.ray.mapX) * data->game.ray.deltaDistX;
		}
		else
		{
			data->game.ray.stepX = 1;
			data->game.ray.sideDistX = (data->game.ray.mapX + 1.0 - data->player.posX) * data->game.ray.deltaDistX;
		}
		if (data->game.ray.dirY < 0)
		{
			data->game.ray.stepY = -1;
			data->game.ray.sideDistY = (data->player.posY - data->game.ray.mapY) * data->game.ray.deltaDistY;
		}
		else
		{
			data->game.ray.stepY = 1;
			data->game.ray.sideDistY = (data->game.ray.mapY + 1.0 - data->player.posY) * data->game.ray.deltaDistY;
		}
		data->game.ray.hit = 0;
		while (data->game.ray.hit == 0)
		{
			if (data->game.ray.sideDistX < data->game.ray.sideDistY)
			{
				data->game.ray.sideDistX += data->game.ray.deltaDistX;
				data->game.ray.mapX += data->game.ray.stepX;
				data->game.ray.side = 0;
			}
			else
			{
				data->game.ray.sideDistY += data->game.ray.deltaDistY;
				data->game.ray.mapY += data->game.ray.stepY;
				data->game.ray.side = 1;
			}
			if (data->map.grid[data->game.ray.mapY][data->game.ray.mapX] == '1')
				data->game.ray.hit = 1;
			if (data->map.grid[data->game.ray.mapY][data->game.ray.mapX] == 'D')
				data->game.ray.hit = 2;
		}
		if (data->game.ray.side == 0)
			data->game.ray.perpWallDist = (data->game.ray.sideDistX - data->game.ray.deltaDistX);
		else
			data->game.ray.perpWallDist = (data->game.ray.sideDistY - data->game.ray.deltaDistY);
		data->game.ray.lineHeight = (int)(data->window.height / data->game.ray.perpWallDist);
		// printf("%i = %i / %f\n", data->game.ray.lineHeight, data->window.height, data->game.ray.perpWallDist);
		data->game.ray.drawStart = -data->game.ray.lineHeight / 2 + data->window.height / 2;
		// printf("%i = -%i / 2 + %f / 2\n", data->game.ray.drawStart, data->game.ray.lineHeight, data->game.ray.perpWallDist);
		if (data->game.ray.drawStart < 0)
			data->game.ray.drawStart = 0;
		data->game.ray.drawEnd = data->game.ray.lineHeight / 2 + data->window.height / 2;
		if (data->game.ray.drawEnd >= data->window.height)
			data->game.ray.drawEnd = data->window.height - 1;
		// DrawLine(x,data->game.ray.drawStart, x + 1, data->game.ray.drawEnd, BLUE);
		draw_ver_line(data, x);
		x++;
	}
}