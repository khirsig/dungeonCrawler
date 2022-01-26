/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_interface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:45:45 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/27 00:35:11 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"

static void	display_minimap_door(t_data *data, double x, double y, double divider, char pos)
{
	double	x_og;
	double	y_og;
	double	x_end;
	double	y_end;
	double	x_length;
	double	y_length;

	x_og = x;
	y_og = y;
	y_end = y + divider;
	y_length = y_end - y;
	x_length = (x + divider) - x;
	while (y <= y_end)
	{
		x = x_og;
		x_end = x + divider;
		while (x <= x_end)
		{
			if ((pos == '_'  && y > y_og + (y_length / 5 * 4)) || (pos == '-' && y < y_og + (y_length / 5 * 1))
				|| (pos == ']' && x > x_og + (x_length / 5 * 4)) || (pos == '[' && x < x_og + (x_length / 5 * 1)))
				DrawPixel(x, y, PURPLE);
			x++;
		}
		y++;
	}
}

static void	display_minimap_wall(t_data *data, double x, double y, double divider)
{
	double	x_og;
	double	x_end;
	double	y_end;

	x_og = x;
	y_end = y + divider;
	// printf("x = [%i] y = [%i] y_end = [%i]\n", x, y, y_end);
	while (y <= y_end)
	{
		x = x_og;
		x_end = x + divider;
		while (x <= x_end)
		{
			DrawPixel((int)x, (int)y, DARKGRAY);
			x++;
		}
		y++;
	}
}

static char	display_minimap_pos(t_data *data, int x, int y, double divider, double size)
{
	char pos;
	double x_temp;
	double y_temp;
	int	temp1;
	int	temp2;
	int	door_temp;
	int	div;

	div = divider / 2;
	x_temp = data->player.posX / 10 + ((x - (int)(data->window.width - size / 2 - div)) / divider);
	y_temp = data->player.posY / 10 + ((y - (int)(size / 2 - div)) / divider);
	if (x_temp >= 0 && y_temp >= 0 && x_temp < data->map.width && y_temp < data->map.height)
		return (data->map.grid[(int)y_temp][(int)x_temp]);
	else
		return ('0');
}

static void display_minimap(t_data *data)
{
	double x_start;
	double x_calc;
	double x_rest;
	double x_end;
	double y_start;
	double y_calc;
	double y_rest;
	double y_end;
	double size;
	double divider;
	char	pos;

	if (data->window.height > data->window.width)
		size = (data->window.width / 3);
	else if (data->window.height != data->window.width)
		size = (data->window.height / 3);
	else
		size = (data->window.height / 4);
	divider = (int)(size / 8);
	x_end = data->window.width;
	y_end = size;
	y_start = (divider / 2);
	while (y_start <= y_end)
	{
		x_start = data->window.width - size + (divider / 2);
		while (x_start <= x_end)
		{
			pos = display_minimap_pos(data, x_start, y_start, divider, size);
			x_rest = ((data->player.posX / 10 - (int)(data->player.posX / 10)) * (divider / 2));
			y_rest = ((data->player.posY / 10 - (int)(data->player.posY / 10)) * (divider / 2));
			// printf("Rest: [%f] - [%d] * [%f] = [%f][%f] Size: [%f] Div: [%f] PPos: [%f][%f]\n",data->player.posY / 10, (int)(data->player.posY / 10), divider, x_rest, y_rest, size, divider, data->player.posX, data->player.posY);
			if (pos == '1' || pos == '8' || pos == '9')
				display_minimap_wall(data, x_start - x_rest, y_start - y_rest, divider);
			if (pos == '-' || pos == '_' || pos == '[' || pos == ']')
				display_minimap_door(data, x_start - x_rest, y_start - y_rest, divider, pos);
			x_start += divider;
		}
		y_start += divider;
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