/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:51:13 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 23:44:48 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"

static void	draw_texture(t_data *data, int x)
{
	int y;
	Color temp;

	y = data->game.ray.drawStart;
	while (y < data->game.ray.drawEnd)
	{
		data->game.ray.texY = (int)data->game.ray.texPos & (64 - 1);
		data->game.ray.texPos += data->game.ray.step;
		temp = data->game.wall[0][64 * data->game.ray.texY - 1 + data->game.ray.texX];
		if (data->game.ray.perpWallDist > 5)
		{
			temp.r -= (data->game.ray.perpWallDist - 5) * 20;
			if (temp.r < 0)
				temp.r = 0;
			temp.g-= (data->game.ray.perpWallDist - 5) * 20;
			if (temp.g < 0)
				temp.g = 0;
			temp.b -= (data->game.ray.perpWallDist - 5) * 20;
			if (temp.b < 0)
				temp.b = 0;

		}
		DrawPixel(x, y, temp);
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
		data->game.ray.drawStart = -data->game.ray.lineHeight / 2 + data->window.height / 2;
		if (data->game.ray.drawStart < 0)
			data->game.ray.drawStart = 0;
		data->game.ray.drawEnd = data->game.ray.lineHeight / 2 + data->window.height / 2;
		if (data->game.ray.drawEnd >= data->window.height)
			data->game.ray.drawEnd = data->window.height - 1;
		data->game.ray.texNum = data->map.grid[data->game.ray.mapY][data->game.ray.mapX] - 1;
		if (data->game.ray.side == 0)
			data->game.ray.wallX = data->player.posY + data->game.ray.perpWallDist * data->game.ray.dirY;
		else
			data->game.ray.wallX = data->player.posX + data->game.ray.perpWallDist * data->game.ray.dirX;
		data->game.ray.wallX -= floor((data->game.ray.wallX));
		data->game.ray.texX = (int)(data->game.ray.wallX * (double)(64));
		if (data->game.ray.side == 0 && data->game.ray.dirX > 0)
			data->game.ray.texX = 64 - data->game.ray.texX - 1;
		if (data->game.ray.side == 1 && data->game.ray.dirY < 0)
			data->game.ray.texX = 64 - data->game.ray.texX - 1;
		data->game.ray.step = 1.0 * 64 / data->game.ray.lineHeight;
		data->game.ray.texPos = (data->game.ray.drawStart - data->window.height / 2 + data->game.ray.lineHeight / 2) * data->game.ray.step;
		draw_texture(data, x);
		x++;
	}
}