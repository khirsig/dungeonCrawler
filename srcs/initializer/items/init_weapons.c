/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:10:43 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/17 16:22:52 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../initializer.h"

void	init_weapons(t_data *data)
{
	data->item.weapon = malloc(sizeof(t_weapon) * 2);
	data->item.weapon[0].icon = load_texture("resources/interface/items/WEP001.png");
}
