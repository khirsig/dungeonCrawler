/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_mainmenu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:32:18 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/17 22:18:07 by khirsig          ###   ########.fr       */
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

static void	draw_button(t_data *data, Texture tex, int posX, int posY, Color col, char *text, int texID)
{
	int	texX;

	DrawTexture(tex, posX, posY, WHITE);
	if (texID == 1)
		texX = posX + (data->window.button_lenX / 40 * 14);
	if (texID == 2)
		texX = posX + (data->window.button_lenX / 40 * 14);
	if (texID == 3)
		texX = posX + (data->window.button_lenX / 40 * 17);
	if (texID == 4)
		texX = posX + (data->window.button_lenX / 40 * 12);
	if (texID == 5)
		texX = posX + (data->window.button_lenX / 40 * 19);
	DrawTextEx(data->window.font, text, (Vector2){ texX, posY + (data->window.button_lenY / 5 * 2) }, data->window.button_size, 1, col);
}

void	loop_mainmenu(t_data *data)
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawTexture(data->window.texture[0], 0, 0, WHITE);
	DrawTexture(data->window.texture[1], data->window.width / 2 - data->window.title_lenX / 7 * 4, data->window.height / 4 - data->window.title_lenY / 2, WHITE);
	DrawTextEx(data->window.font, "Dungeon Crawler", (Vector2){ data->window.width / 2 - data->window.title_lenX / 4, data->window.height / 4 - data->window.title_lenY / 2 / 6}, data->window.title_size, 1, (Color){ 255, 255, 255, 150});
	if (is_on_button(data, data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 4) == 1)
	{
		draw_button(data, data->window.texture[3], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 4, (Color){ 255, 255, 255, 180}, "Start Game", 1);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			data->game.state = INGAME;
	}
	else
		draw_button(data, data->window.texture[2], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 4, (Color){ 255, 255, 255, 100}, "Start Game", 1);
	if (is_on_button(data, data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 5) == 1)
		draw_button(data, data->window.texture[3], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 5, (Color){ 255, 255, 255, 180}, "Load Game", 2);
	else
		draw_button(data, data->window.texture[2], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 5, (Color){ 255, 255, 255, 100}, "Load Game", 2);
	if (is_on_button(data, data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 6) == 1)
		draw_button(data, data->window.texture[3], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 6, (Color){ 255, 255, 255, 180}, "Options", 3);
	else
		draw_button(data, data->window.texture[2], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 6, (Color){ 255, 255, 255, 100}, "Options", 3);
	if (is_on_button(data, data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 7) == 1)
		draw_button(data, data->window.texture[3], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 7, (Color){ 255, 255, 255, 180}, "Achievements", 4);
	else
		draw_button(data, data->window.texture[2], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 7, (Color){ 255, 255, 255, 100}, "Achievements", 4);
	if (is_on_button(data, data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 8) == 1)
	{
		draw_button(data, data->window.texture[3], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 8, (Color){ 255, 255, 255, 180}, "Exit", 5);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			exit(EXIT_SUCCESS);
	}
	else
		draw_button(data, data->window.texture[2], data->window.width / 2 - data->window.button_lenX / 2, data->window.height / 10 * 8, (Color){ 255, 255, 255, 100}, "Exit", 5);
	EndDrawing();
}