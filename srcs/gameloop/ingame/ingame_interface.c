/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_interface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:45:45 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/29 14:28:29 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"

static char	display_minimap_pos(t_data *data, double x, double y, double divider, double size)
{
	char pos;
	double x_temp;
	double y_temp;
	int	div;

	div = divider / 2;
	x_temp = data->player.posX / 10 + ((x - (data->window.width - size / 2 - div)) / divider);
	y_temp = data->player.posY / 10 + ((y - (size / 2 - div)) / divider);
	if (x_temp >= 0 && y_temp >= 0 && x_temp < data->map.width && y_temp < data->map.height)
		return (data->map.grid[(int)y_temp][(int)x_temp]);
	else
		return ('0');
}

static int	get_door_id(t_data *data, int x, int y)
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

static void	display_minimap_door(t_data *data, double x, double y, double divider, double size, char pos)
{
	double	div;
	int	x_og;
	int	y_og;
	int	x_temp;
	int	y_temp;
	int	door_id;
	double	sub;
	double	x_length;
	double	y_length;

	div = divider / 2;
	x_og = data->player.posX / 10 + ((x - (data->window.width - size / 2 - div)) / divider);
	x_temp = x_og;
	sub = 0;
	while (x_og == x_temp)
	{
		x_temp = data->player.posX / 10 + (((x - sub) - (data->window.width - size / 2 - div)) / divider);
		sub++;
	}
	x_og = x - sub + 1;
	y_og = data->player.posY / 10 + ((y - (size / 2 - div)) / divider);
	y_temp = y_og;
	sub = 0;
	while (y_og == y_temp)
	{
		y_temp = data->player.posY / 10 + (((y - sub) - (size / 2 - div)) / divider);
		sub++;
	}
	y_og = y - sub + 1;
	if ((pos == '_'  && y > y_og + (divider / 5 * 4)) || (pos == '-' && y < y_og + (divider / 5 * 1))
		|| (pos == ']' && x > x_og + (divider / 5 * 4)) || (pos == '[' && x < x_og + (divider / 5 * 1)))
		{
			door_id = get_door_id(data, x_temp + 1, y_temp + 1);
			if (door_id != -1 && data->map.door[door_id].state == OPENING)
			{
				if (((pos == '-' || pos == '_') && (x < x_og + (divider / 5 * 1) || x > x_og + (divider / 5 * 4)))
					|| ((pos == '[' || pos == ']') && (y < y_og + (divider / 5 * 1) || y > y_og + (divider / 5 * 4))))
					DrawPixel(x, y, PURPLE);
			}
			else
				DrawPixel(x, y, PURPLE);
		}
}

static void display_minimap(t_data *data)
{
	double x_start;
	double x_end;
	double y_start;
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
	x_end = (int)data->window.width;
	y_end = (int)size;
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
				display_minimap_door(data, x_start, y_start, divider, size, pos);
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

static void	ingame_interface_debug(t_data *data)
{
	char	temp[50];
	DrawFPS(5, 5);
	sprintf(temp, "%.2lf", data->player.posX);
	DrawText("PPos:", 5, 35, 5, BLUE);
	DrawText(temp, 40, 35, 5, WHITE);
	sprintf(temp, "%.2lf", data->player.posY);
	DrawText(temp, 90, 35, 5, WHITE);
	sprintf(temp, "%.2lf", data->player.posZ);
	DrawText(temp, 140, 35, 5, WHITE);
	sprintf(temp, "%.2lf", data->player.dirX);
	DrawText("PDir:", 5, 55, 5, RED);
	DrawText(temp, 40, 55, 5, WHITE);
	sprintf(temp, "%.2lf", data->player.dirY);
	DrawText(temp, 90, 55, 5, WHITE);
	sprintf(temp, "%.2lf", data->player.dirZ);
	DrawText(temp, 140, 55, 5, WHITE);
	DrawText("Plane:", 5, 75, 5, LIME);
	sprintf(temp, "%.2lf", data->player.planeX);
	DrawText(temp, 40, 75, 5, WHITE);
	sprintf(temp, "%.2lf", data->player.planeY);
	DrawText(temp, 90, 75, 5, WHITE);
	sprintf(temp, "%.2lf", data->player.planeZ);
	DrawText(temp, 140, 75, 5, WHITE);
}

void	ingame_interface(t_data *data)
{
	if (data->game.debugmode == 1)
		ingame_interface_debug(data);
	display_vitals(data);
	display_minimap(data);
}
