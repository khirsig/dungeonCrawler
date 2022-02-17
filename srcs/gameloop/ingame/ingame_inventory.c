/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_inventory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:03:17 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/17 20:10:40 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"

void	inventory_open(t_data *data)
{
	if(IsKeyPressed(KEY_I))
	{
		printf("Inv Debug: status: %i x: %i y: %i x_len: %i y_len: %i\n", data->player.inv.gui.status, data->player.inv.gui.posX, data->player.inv.gui.posY, data->player.inv.gui.lenX, data->player.inv.gui.lenY);
		if (data->player.inv.gui.status == CLOSED)
			data->player.inv.gui.status = OPEN;
		else if (data->player.inv.gui.status == OPEN)
			data->player.inv.gui.status = CLOSED;
	}
}

void	inventory_move(t_data *data)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && data->player.inv.gui.moving == 0)
	{
		int mouseX = GetMouseX();
		int	mouseY = GetMouseY();
		if (mouseX > data->player.inv.gui.posX && mouseX < data->player.inv.gui.posX + data->player.inv.gui.lenX && mouseY > data->player.inv.gui.posY && mouseY < data->player.inv.gui.posY + data->player.inv.gui.lenY)
		{
			data->player.inv.gui.moving = 1;
			data->player.inv.gui.mouseX = mouseX;
			data->player.inv.gui.mouseY = mouseY;
		}
	}
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && data->player.inv.gui.moving == 1)
		data->player.inv.gui.moving = 0;
	if (data->player.inv.gui.moving == 1)
	{
		int mouseX = GetMouseX();
		int	mouseY = GetMouseY();
		data->player.inv.gui.posX += mouseX - data->player.inv.gui.mouseX;
		data->player.inv.gui.posY += mouseY - data->player.inv.gui.mouseY;
		data->player.inv.gui.mouseX = mouseX;
		data->player.inv.gui.mouseY = mouseY;
	}
}

void	inventory_draw(t_data *data)
{
	inventory_move(data);
	// printf("Hallo %i %i %i %i %i?\n", data->player.inv.gui.status, data->player.inv.gui.posX, data->player.inv.gui.posY, data->player.inv.gui.lenX, data->player.inv.gui.lenY);
	// DrawRectangle(data->player.inv.gui.posX, data->player.inv.gui.posY, data->player.inv.gui.lenX, data->player.inv.gui.lenY, DARKGRAY);
	DrawTexture(data->player.inv.gui.tex[0], data->player.inv.gui.posX, data->player.inv.gui.posY, WHITE);
	DrawTexture(data->player.inv.gui.tex[1], data->player.inv.gui.posX + 25, data->player.inv.gui.posY + 80, WHITE);
	DrawTexture(data->player.inv.gui.tex[1], data->player.inv.gui.posX + 75, data->player.inv.gui.posY + 130, WHITE);
	DrawTexture(data->player.inv.gui.tex[1], data->player.inv.gui.posX + 25, data->player.inv.gui.posY + 130, WHITE);
	DrawTexture(data->player.inv.gui.tex[1], data->player.inv.gui.posX + 75, data->player.inv.gui.posY + 80, WHITE);
	// inventory_draw_box(data->player.inv.gui.posX, data->player.inv.gui.posY, data->player.inv.gui.lenX, data->player.inv.gui.lenY, DARKGRAY);
}
