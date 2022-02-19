/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_inventory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:03:17 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/19 02:05:20 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"

void	inventory_open(t_data *data)
{
	if(IsKeyPressed(KEY_I))
	{
		if (data->player.inv.gui.status == CLOSED)
			data->player.inv.gui.status = OPEN;
		else if (data->player.inv.gui.status == OPEN)
			data->player.inv.gui.status = CLOSED;
	}
}

static int	calc_pow(int i)
{
	if (i / 10 == 0)
		return (5);
	if (i / 100 == 0)
		return (3);
	if (i / 1000 == 0)
		return (7);
	if (i / 10000 == 0)
		return (8);
	if (i / 100000 == 0)
		return (9);
	return (0);
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

static char *get_currency_string(t_data *data, int amount)
{
	char *amount_conv;
	char *ret;
	int len;
	int i;
	int j;

	amount_conv = ft_itoa(amount);
	len = strlen(amount_conv);
	if (len <= 3)
		return (amount_conv);
	else if (len > 3 && len <= 6)
	{
		ret = malloc(sizeof(char) * (len + 2));
		ret[len + 1] = '\0';
		i = 0;
		j = 0;
		while (amount_conv[j] != '\0')
		{
			if (i != len - 3)
			{
				ret[i] = amount_conv[j];
				j++;
			}
			else
				ret[i] = '.';
			i++;
		}
		return (ret);
	}
	else if (len > 6)
	{
		j = len - 6 + 3;
		ret = malloc(sizeof(char) * (j));
		ret[j] = '\0';
		ret[j - 1] = 'm';
		i = 0;
		while (i < j - 1)
		{
			if (i != j - 3)
				ret[i] = amount_conv[i];
			else
				ret[i] = ',';
			i++;
		}
		return (ret);
	}
	return (amount_conv);
}

void	inventory_draw(t_data *data)
{
	inventory_move(data);
	DrawTexture(data->player.inv.gui.tex[0], data->player.inv.gui.posX, data->player.inv.gui.posY, WHITE);
	int incr = data->player.inv.gui.lenCell;
	DrawTextEx(data->window.font, get_currency_string(data, data->player.gold), (Vector2){ data->player.inv.gui.posX + data->player.inv.gui.lenX / 9 * 2, data->player.inv.gui.posY + data->player.inv.gui.lenY / 40 * 39 }, incr / 5, 1, GRAY);
	DrawTextEx(data->window.font, get_currency_string(data, data->player.soulgem), (Vector2){ data->player.inv.gui.posX + data->player.inv.gui.lenX / 13 * 8, data->player.inv.gui.posY + data->player.inv.gui.lenY / 40 * 39 }, incr / 5, 1, GRAY);
	int	y = 0;
	while (y < 7)
	{
		int posY = data->player.inv.gui.posY + (data->player.inv.gui.lenY / 7) + incr * y;
		int	x = 0;
		while (x < 5)
		{
			int posX = data->player.inv.gui.posX + (data->player.inv.gui.lenX / 11) + incr * x;
			if (data->player.inv.slot[y][x].status == UNLOCKED && data->player.inv.slot[y][x].id == -1)
				DrawTexture(data->player.inv.gui.tex[1], posX, posY, WHITE);
			else if (data->player.inv.slot[y][x].id != -1)
			{
				DrawTexture(data->player.inv.gui.tex[1], posX, posY, data->item[data->player.inv.slot[y][x].id].rarity);
				DrawTexture(data->item[data->player.inv.slot[y][x].id].icon, posX + 1, posY + 1, WHITE);
				if (data->player.inv.slot[y][x].amount > 1)
					DrawText(ft_itoa(data->player.inv.slot[y][x].amount), posX + (incr - (incr / calc_pow(data->player.inv.slot[y][x].amount))), posY + (incr / 10), incr / 5, WHITE);
			}
			x++;
		}
		y++;
	}
}
