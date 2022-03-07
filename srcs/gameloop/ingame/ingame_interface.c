/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_interface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:45:45 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/07 19:34:06 by khirsig          ###   ########.fr       */
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
	x_temp = data->player.posX / 10 + ((x - (data->map.mini.startX + size / 2 - div)) / divider);
	y_temp = data->player.posY / 10 + ((y - (data->map.mini.startY + size / 2 - div)) / divider);
	if (x_temp >= 0 && y_temp >= 0 && x_temp < data->map.width && y_temp < data->map.height)
		return (data->map.grid[(int)y_temp][(int)x_temp]);
	else if (x_temp < 0 || y_temp < 0 || x_temp >= data->map.width || y_temp >= data->map.height)
		return ('1');
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
	x_og = data->player.posX / 10 + ((x - (data->map.mini.startX + size / 2 - div)) / divider);
	x_temp = x_og;
	sub = 0;
	while (x_og == x_temp)
	{
		x_temp = data->player.posX / 10 + (((x - sub) - (data->map.mini.startX + size / 2 - div)) / divider);
		sub++;
	}
	x_og = x - sub + 2;
	y_og = data->player.posY / 10 + ((y - (data->map.mini.startY + size / 2 - div)) / divider);
	y_temp = y_og;
	sub = 0;
	while (y_og == y_temp)
	{
		y_temp = data->player.posY / 10 + (((y - sub) - (data->map.mini.startY + size / 2 - div)) / divider);
		sub++;
	}
	y_og = y - sub + 2;
	div = divider / 5;
	if ((pos == '_'  && y > y_og + div * 4) || (pos == '-' && y < y_og + div)
		|| (pos == ']' && x > x_og + div * 4) || (pos == '[' && x < x_og + div))
		{
			door_id = get_door_id(data, x_temp + 1, y_temp + 1);
			if (door_id != -1 && data->map.door[door_id].state == OPENING)
			{
				if (((pos == '-' || pos == '_') && (x <= x_og + (int)(divider / 5 * 1) || x > x_og + (int)(divider - (divider / 5 * 1))))
					|| ((pos == '[' || pos == ']') && (y <= y_og + (int)(divider / 5 * 1) || y > y_og + (int)(divider - (divider / 5 * 1)))))
					DrawRectangle(x, y, 1, 1, (Color){ 100, 42, 160, 200 });
			}
			else
				DrawRectangle(x, y, 1, 1, (Color){ 100, 42, 160, 200 });
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

	divider = (int)(data->map.mini.len / 8);
	size = data->map.mini.len - divider / 3;
	x_end = data->map.mini.startX + size;
	y_start = data->map.mini.startY + divider / 3;
	y_end = data->map.mini.startY + size;
	while (y_start <= y_end)
	{
		x_start = data->map.mini.startX + divider / 3;
		while (x_start <= x_end)
		{
			pos = display_minimap_pos(data, x_start, y_start, divider, size);
			if (pos == '1' || pos == '8' || pos == '9')
				DrawRectangle(x_start, y_start, 1, 1, (Color){ 10, 10, 10, 200 });
			else
				DrawRectangle(x_start, y_start, 1, 1, (Color){ 225, 225, 225, 100 });
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
		DrawLine(data->map.mini.startX + size / 2, data->map.mini.startY + size / 2, (data->map.mini.startX + size / 2)
				+ x_rotate * (divider * 1.5f), (data->map.mini.startY + size / 2)
				+ y_rotate * (divider * 1.5f), (Color){ 170, 170, 170, 100 });
		index += 0.01;
	}
	DrawCircle(data->map.mini.startX + size / 2, data->map.mini.startY + size / 2, divider / 4, (Color){ 220, 220, 220, 255 });
	DrawTexture(data->map.mini.border, data->map.mini.startX, data->map.mini.startY, WHITE);
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
	y_end = data->player.chLay.startY + data->player.chLay.lenY / 1.6;
	y_start = data->player.chLay.startY + data->player.chLay.lenY / 3;
	x_start = data->player.chLay.startX + data->player.chLay.lenX / 3.1;
	x_end = data->player.chLay.startX + data->player.chLay.lenX / 1.2;
	y_temp = y_start;
	x_temp = x_start;
	while (y_start <= y_end)
	{
		x_start = x_temp;
		while (x_start <= x_end)
		{
			if (y_start <= y_temp + ((y_end - y_temp) / 5) * 2.4)
			{
				if (x_start - x_temp <= ((x_end - x_temp) * perc_hp) / 100.00)
					DrawRectangle(x_start, y_start, 1, 1, (Color){ 255, 41, 55, 170 });
				else
					DrawRectangle(x_start, y_start, 1, 1, (Color){ 10, 10, 10, 170 });
			}
			if (y_start >= y_temp + ((y_end - y_temp) / 5) * 2.6)
			{
				if (x_start - x_temp <= ((x_end - x_temp) * perc_stam) / 100)
					DrawRectangle(x_start, y_start, 1, 1, (Color){ 0, 200, 67, 170 });
				else
					DrawRectangle(x_start, y_start, 1, 1, (Color){ 10, 10, 10, 170 });
			}
			x_start++;
		}
		y_start++;
	}
	DrawTexture(data->player.chLay.bg, data->player.chLay.startX, data->player.chLay.startY, WHITE);
	DrawTexture(data->player.chLay.avatar, data->player.chLay.startX + data->player.chLay.lenX / 12, data->player.chLay.startY + data->player.chLay.lenY / 8, WHITE);
	DrawTexture(data->player.chLay.circle, data->player.chLay.startX + data->player.chLay.lenX / 12, data->player.chLay.startY + data->player.chLay.lenY / 8, WHITE);
	DrawTextEx(data->window.font, ft_itoa(data->player.level), (Vector2){ data->player.chLay.startX + data->player.chLay.lenX / 20 - (data->player.level / 10), data->player.chLay.startY + data->player.chLay.lenY / 1.45 }, data->player.chLay.lenY / 10, 1.0, RAYWHITE);
	char temp[50];
	sprintf(temp, "%i / %i", (int)data->player.health, (int)data->player.max_health);
	DrawTextEx(data->window.font, temp, (Vector2){ x_temp + data->player.chLay.lenX / 5, y_temp + data->player.chLay.lenY / 16.0 }, data->player.chLay.lenY / 20, 1.0, RAYWHITE);
	sprintf(temp, "%i / %i", (int)data->player.stamina, (int)data->player.max_stamina);
	DrawTextEx(data->window.font, temp, (Vector2){ x_temp + data->player.chLay.lenX / 5, y_temp + data->player.chLay.lenY / 4.7 }, data->player.chLay.lenY / 20, 1.0, RAYWHITE);
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
	DrawText("MS:", 5, 95, 5, PURPLE);
	sprintf(temp, "%.2lf", data->player.movementspeed);
	DrawText(temp, 40, 95, 5, WHITE);
}

static void	display_cursor(t_data *data)
{
	DisableCursor();
}

void	ingame_interface(t_data *data)
{
	if (data->game.debugmode == 1)
		ingame_interface_debug(data);
	display_vitals(data);
	display_minimap(data);
}
