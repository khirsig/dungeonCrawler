/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_interface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:45:45 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 17:53:24 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"

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
					DrawPixel(x_start, y_start, RED);
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
	display_vitals(data);
}