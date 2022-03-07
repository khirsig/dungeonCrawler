/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:55:20 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/19 10:05:26 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../loop_ingame.h"

static int stack_items(t_data *data, int id, int amount)
{
	int	x;
	int	y;

	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			while (data->player.inv.slot[y][x].id == id && data->item[data->player.inv.slot[y][x].id].stackable >= data->player.inv.slot[y][x].amount + 1)
			{
				data->player.inv.slot[y][x].amount++;
				amount--;
				if (amount == 0)
					return (amount);
			}
			x++;
		}
		y++;
	}
	return (amount);
}

static int add_new_stack(t_data *data, int id, int amount)
{
	int	x;
	int	y;

	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			while (data->player.inv.slot[y][x].id == -1 && data->item[data->player.inv.slot[y][x].id].stackable >= data->player.inv.slot[y][x].amount + 1)
			{
				data->player.inv.slot[y][x].id = id;
				data->player.inv.slot[y][x].status = data->item[data->player.inv.slot[y][x].id].type;
				data->player.inv.slot[y][x].amount++;
				if (amount > 0 && data->item[data->player.inv.slot[y][x].id].stackable >= data->player.inv.slot[y][x].amount + 1)
					amount = stack_items(data, id, amount);
				if (amount == 0)
					return (amount);
			}
			x++;
		}
		y++;
	}
	return (amount);
}

void	add_item_to_inventory(t_data *data, int id, int amount)
{
	amount = stack_items(data, id, amount);
	if (amount == 0)
		return ;
	amount = add_new_stack(data, id, amount);
	if (amount == 0)
		return ;
	if (amount != 0)
		printf("Error: Inventory Full.\n");
}
