/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inventory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:03:54 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/17 20:04:15 by khirsig          ###   ########.fr       */
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
	data->player.inv.gui.tex[1] = LoadTextureFromImage(image);
	UnloadImage(image);
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
}
