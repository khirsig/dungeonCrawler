/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:18:08 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/07 16:09:36 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

void	init_minimap(t_data *data)
{
	data->map.mini.len = data->window.height / 3.5;
	data->map.mini.border = load_texture_len("./resources/interface/minimap/minimapborder.png", data->map.mini.len, data->map.mini.len);
	data->map.mini.startX = data->window.width - data->map.mini.len * 1.2;
	data->map.mini.startY = data->map.mini.len * 0.2;
}
