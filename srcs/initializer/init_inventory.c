/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inventory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:03:54 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/17 16:10:50 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

void	init_inventory(t_data *data)
{
	data->player.inv.gui.lenX = data->window.width / 5;
	data->player.inv.gui.lenY = data->window.height / 2;
	data->player.inv.gui.posX = data->window.width / 2 - (data->player.inv.gui.lenX / 2);
	data->player.inv.gui.posY = data->window.width / 4 - (data->player.inv.gui.lenY / 2);
	data->player.inv.gui.status = CLOSED;
	data->player.inv.gui.moving = 0;
}
