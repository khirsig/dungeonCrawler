/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_tooltip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:12:57 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/19 11:44:52 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../loop_ingame.h"

static int	calc_tooltip_lenY(int data, int type)
{
	return (0);
}

static void	draw_tooltip_item(t_data *data, int posX, int posY, int slotX, int slotY)
{
	int	incr, space, textX, textY, textLen;

	space = 10;
	if (posY - data->player.inv.gui.ttip.lenY - space > 0)
		incr = -1;
	else
		incr = 1;
	data->player.inv.gui.ttip.posY = posY + (space * incr);
	if (posY - data->player.inv.gui.ttip.lenY - space > 0)
		data->player.inv.gui.ttip.posY -= data->player.inv.gui.ttip.lenY;
	data->player.inv.gui.ttip.posX = posX - (data->player.inv.gui.ttip.lenX / 2);
	if (data->player.inv.gui.ttip.posX < 0)
		data->player.inv.gui.ttip.posX = 0;
	if (data->player.inv.gui.ttip.posX > data->window.width)
		data->player.inv.gui.ttip.posX = data->window.width - data->player.inv.gui.ttip.lenX;
	DrawTexture(data->player.inv.gui.ttip.tex, data->player.inv.gui.ttip.posX, data->player.inv.gui.ttip.posY, WHITE);
	textLen = MeasureText(data->item[data->player.inv.slot[slotY][slotX].id].name, data->player.inv.gui.ttip.lenX / 10);
	textX = data->player.inv.gui.ttip.posX + (data->player.inv.gui.ttip.lenX / 2  - (textLen / 2));
	textY = data->player.inv.gui.ttip.posY + (data->player.inv.gui.ttip.lenY / 8);
	DrawTextEx(data->window.font, data->item[data->player.inv.slot[slotY][slotX].id].name, (Vector2){ textX, textY }, data->player.inv.gui.ttip.lenX / 10, 1, RED);
	textX = data->player.inv.gui.ttip.posX + (data->player.inv.gui.ttip.lenX / 6);
	textY = data->player.inv.gui.ttip.posY + (data->player.inv.gui.ttip.lenY / 10 * 8);
	DrawTextEx(data->window.font, data->item[data->player.inv.slot[slotY][slotX].id].tooltip, (Vector2){ textX, textY }, data->player.inv.gui.ttip.lenX / 20, 0.2, DARKGRAY);
}

void	hover_item(t_data *data)
{
	int x, y;

	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (data->window.mouseX <= data->player.inv.slot[y][x].x + data->player.inv.gui.lenCell && data->window.mouseX >= data->player.inv.slot[y][x].x
				&& data->window.mouseY <= data->player.inv.slot[y][x].y + data->player.inv.gui.lenCell && data->window.mouseY >= data->player.inv.slot[y][x].y
				&& data->player.inv.slot[y][x].id != -1)
				draw_tooltip_item(data, data->window.mouseX, data->window.mouseY, x, y);
			x++;
		}
		y++;
	}
}
