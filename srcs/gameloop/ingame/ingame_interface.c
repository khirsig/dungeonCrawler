/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_interface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:45:45 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/26 00:01:19 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"

static char	display_minimap_pos(t_data *data, int x, int y, double divider, double size)
{
	char pos;
	int x_temp;
	int y_temp;
	int	temp1;
	int	temp2;
	int	door_temp;
	int	div;

	div = divider / 2;
	x_temp = data->player.posX / 10 + ((x - (int)(data->window.width - size / 2 - div - 1)) / divider);
	y_temp = data->player.posY / 10 + ((y - (int)(size / 2 - div)) / divider);
	if (x_temp >= 0 && y_temp >= 0 && x_temp < data->map.width && y_temp < data->map.height)
	{
		pos = data->map.grid[y_temp][x_temp];
		return (pos);
	}
	else
		return ('0');
}

static void display_minimap(t_data *data)
{
	double x_start;
	double x_calc;
	double x_end;
	double y_start;
	double y_calc;
	double y_end;
	double size;
	double divider;
	char	pos;

	if (data->window.height > data->window.width)
		size = (int)(data->window.width / 3);
	else if (data->window.height != data->window.width)
		size = (int)(data->window.height / 3);
	else
		size = (int)(data->window.height / 4);
	divider = (int)(size / 10);
	x_end = data->window.width;
	y_end = size;
	y_start = 0;
	while (y_start <= y_end)
	{
		x_start = data->window.width - size;
		while (x_start <= x_end)
		{
			pos = display_minimap_pos(data, x_start, y_start, divider, size);
			if (pos == '1' || pos == '8' || pos == '9')
				DrawPixel(x_start, y_start, DARKGRAY);
			if (pos == '-' || pos == '_' || pos == '[' || pos == ']')
				DrawPixel(x_start, y_start, PURPLE);
			x_start++;
		}
		y_start++;
	}
	double x_rotate;
	double y_rotate;
	double temp;
	double index;

	index = -0.7853;
	while (index < 0.7853)
	{
		temp = data->player.planeX;
		x_rotate = data->player.planeX * cos(index) - data->player.planeY * sin(index);
		y_rotate = temp * sin(index) + data->player.planeY * cos(index);
		DrawLine(data->window.width - size / 2, size / 2, (data->window.width - size / 2)
				+ x_rotate * (divider * 1.5f), (size / 2)
				+ y_rotate * (divider * 1.5f), (Color){ 253, 253, 253, 50 });
		index += 0.01;
	}
	DrawCircle(data->window.width - size / 2, size / 2, divider / 2 - divider / 5, BLUE);
}

static void	display_vitals(t_data *data)
{
	double	x_start;
	double	x_temp;
	double	x_end;
	double	y_start;
	double	y_temp;
	double	y_end;
	double	perc_stam;
	double	perc_hp;

	perc_hp = (100.0 * data->player.health) / data->player.max_health;
	perc_stam = (100.0 * data->player.stamina) / data->player.max_stamina;
	y_end = data->window.height - data->window.height / 26;
	y_start = data->window.height - (data->window.height / 26 * 2);
	x_start = data->window.width / 26;
	x_end = x_start + data->window.width / 5;
	y_temp = y_start;
	x_temp = x_start;
	while (y_start <= y_end)
	{
		x_start = x_temp;
		while (x_start <= x_end)
		{
			if (y_start <= y_temp + ((y_end - y_temp) / 5) * 2)
			{
				if (x_start - x_temp <= ((x_end - x_temp) * perc_hp) / 100.00)
					DrawPixel(x_start, y_start, (Color){ 255, 41, 55, 255 });
				else
					DrawPixel(x_start, y_start, DARKGRAY);
			}
			if (y_start >= y_temp + ((y_end - y_temp) / 5) * 3)
			{
				if (x_start - x_temp <= ((x_end - x_temp) * perc_stam) / 100)
					DrawPixel(x_start, y_start, LIME);
				else
					DrawPixel(x_start, y_start, DARKGRAY);
			}
			x_start++;
		}
		y_start++;
	}
}

void	ingame_interface(t_data *data)
{

	DrawFPS(5, 5);
	display_vitals(data);
	display_minimap(data);
}