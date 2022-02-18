/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inventory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:03:54 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/18 01:19:29 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

static void	load_inventory_texture(t_data *data)
{
	Image image;

	image = LoadImage("./resources/interface/inventory/panel.png");
	// ImageResize(image, data->player.inv.gui.lenX, data->player.inv.gui.lenY);
	data->player.inv.gui.tex[0] = LoadTextureFromImage(image);
	UnloadImage(image);
	image = LoadImage("./resources/interface/inventory/cell.png");
	ImageResize(&image, 60, 60);
	data->player.inv.gui.tex[1] = LoadTextureFromImage(image);
	UnloadImage(image);
}

static Texture load_icon(char *path)
{
	Image image;
	Texture texture;

	image = LoadImage(path);
	ImageResize(&image, 40, 40);
	texture = LoadTextureFromImage(image);
	UnloadImage(image);
	return (texture);
}

static void	init_item(t_item *item, int id, char *name, int type, int price, int damage, int durability, int upgrade_level, char *tooltip, char *path)
{
	item->id = id;
	item->name = name;
	item->type = type;
	item->price = price;
	item->damage = damage;
	item->durability = durability;
	item->upgrade_level = upgrade_level;
	item->tooltip = tooltip;
	item->icon = load_icon(path);
}

void	init_inventory(t_data *data)
{
	data->player.inv.gui.lenX = data->window.width / 5;
	data->player.inv.gui.lenY = data->window.height / 2;
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
			data->player.inv.slot[y][x].type = 0;
			x++;
		}
		y++;
	}
	data->item = malloc(sizeof(t_item) * 3);
	init_item(&data->item[0], 0, "Apple", CONSUMEABLE, 10, -1, -1, -1, "Tastes fresh and delicious.", "./resources/interface/items/ITEM001.png");
	init_item(&data->item[1], 0, "Tutorial", STATIC, 0, -1, -1, -1, "Thanks for playing this one man game!.", "./resources/interface/items/ITEM000.png");
	data->player.inv.slot[0][1].id = 0;
	data->player.inv.slot[0][0].id = 1;
}
