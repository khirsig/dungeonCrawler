/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:16:03 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 15:25:08 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

void	init_window(t_data *data)
{
	data->window.height = 800;
	data->window.width = 1200;
	InitWindow(data->window.width, data->window.height, "The Elder Scrolls: Dungeon");
}