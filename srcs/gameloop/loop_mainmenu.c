/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_mainmenu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:32:18 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/17 23:29:10 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameloop.h"

static int	is_on_button(t_data *data, int posX, int posY)
{
	if (data->window.mouseX >= posX && data->window.mouseY >= posY && data->window.mouseX <= posX + data->window.button_lenX && data->window.mouseY <= posY + data->window.button_lenY)
		return (1);
	else
		return (0);
}

static void	draw_button(t_data *data, Texture tex, int posX, int posY)
{
	DrawTexture(tex, posX, posY, WHITE);
}

void	loop_mainmenu(t_data *data)
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawTexture(data->window.texture[0], 0, 0, WHITE);
	DrawTexture(data->window.texture[1], data->window.width / 2 - data->window.title_lenX / 7 * 4, data->window.height / 4 - data->window.title_lenY / 2, WHITE);
	if (is_on_button(data, data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 4) == 1)
	{
		draw_button(data, data->window.texture[3], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 4);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			data->game.state = INGAME;
	}
	else
		draw_button(data, data->window.texture[2], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 4);
	if (is_on_button(data, data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 5) == 1)
		draw_button(data, data->window.texture[5], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 5);
	else
		draw_button(data, data->window.texture[4], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 5);
	if (is_on_button(data, data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 6) == 1)
		draw_button(data, data->window.texture[7], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 6);
	else
		draw_button(data, data->window.texture[6], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 6);
	if (is_on_button(data, data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 7) == 1)
		draw_button(data, data->window.texture[9], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 7);
	else
		draw_button(data, data->window.texture[8], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 7);
	if (is_on_button(data, data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 8) == 1)
	{
		draw_button(data, data->window.texture[11], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 8);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			exit(EXIT_SUCCESS);
	}
	else
		draw_button(data, data->window.texture[10], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 8);
	EndDrawing();
}