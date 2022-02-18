/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inventory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:03:54 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/18 23:36:27 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

static void	load_inventory_texture(t_data *data)
{
	Image image;

	image = LoadImage("./resources/interface/inventory/PANEL.png");
	ImageResize(&image, data->player.inv.gui.lenX, data->player.inv.gui.lenY);
	data->player.inv.gui.tex[0] = LoadTextureFromImage(image);
	UnloadImage(image);
	image = LoadImage("./resources/interface/inventory/cell.png");
	ImageResize(&image, data->player.inv.gui.lenCell, data->player.inv.gui.lenCell);
	data->player.inv.gui.tex[1] = LoadTextureFromImage(image);
	UnloadImage(image);
}

static Texture load_icon(t_data *data, char *path)
{
	Image image;
	Texture texture;
	int		lenIcon;

	lenIcon = data->player.inv.gui.lenCell - 2;
	image = LoadImage(path);
	ImageResize(&image, lenIcon, lenIcon);
	texture = LoadTextureFromImage(image);
	UnloadImage(image);
	return (texture);
}

static void	init_item(t_data *data, t_item *item, int id, char *name, int type, int price, int stackable, int damage, int durability, int upgrade_level, char *tooltip, Color rarity, char *path)
{
	item->id = id;
	item->name = name;
	item->type = type;
	item->price = price;
	item->damage = damage;
	item->stackable = stackable;
	item->durability = durability;
	item->upgrade_level = upgrade_level;
	item->tooltip = tooltip;
	item->icon = load_icon(data, path);
	item->rarity = rarity;
}

void	init_inventory(t_data *data)
{
	double	calc = 568.0 / 379.0;

	data->player.inv.gui.lenX = data->window.width / 4;
	data->player.inv.gui.lenY = data->window.width / 4 * calc;
	data->player.inv.gui.lenCell = data->player.inv.gui.lenX / 6;
	data->player.inv.gui.posX = data->window.width / 2 - (data->player.inv.gui.lenX / 2);
	data->player.inv.gui.posY = data->window.width / 4 - (data->player.inv.gui.lenY / 2);
	data->player.inv.gui.status = CLOSED;
	data->player.inv.gui.moving = 0;
	data->player.inv.gui.tex = malloc(sizeof(Texture) * 3);
	load_inventory_texture(data);
	int y = 0;
	while (y < 7)
	{
		int x = 0;
		while (x < 5)
		{
			data->player.inv.slot[y][x].id = -1;
			data->player.inv.slot[y][x].status = UNLOCKED;
			data->player.inv.slot[y][x].type = -1;
			data->player.inv.slot[y][x].amount = -1;
			x++;
		}
		y++;
	}
	data->item = malloc(sizeof(t_item) * 4);
	//		data, item array,      id, name,     type, price, stackable, damage, durability, upgrade lvl, tooltip, rarity, path
	init_item(data, &data->item[0], 0, "Apple", CONSUMEABLE, 10, 99, -1, -1, -1, "Tastes fresh and delicious.", WHITE, "./resources/interface/items/ITEM000.png");
	init_item(data, &data->item[1], 1, "Tutorial", STATIC, 0, 1, -1, -1, -1, "Thanks for playing this one man game!.", WHITE, "./resources/interface/items/ITEM001.png");
	init_item(data, &data->item[2], 2, "Claymore", WEAPON, 300, 1, 33, 100, 1, "A strong big claymore. May be wield with two hands.", WHITE, "./resources/interface/items/ITEM002.png");
}
