/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:16:03 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 22:56:30 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

static Color	*load_texture(char *path)
{
	Image temp;
	Color *ret;

	temp = LoadImage(path);
	ret = LoadImageColors(temp);
	UnloadImage(temp);
	return (ret);
}

void	init_window(t_data *data)
{
	data->window.height = 800;
	data->window.width = 1200;
	InitWindow(data->window.width, data->window.height, "The Elder Scrolls: Dungeon");
	data->game.wall = malloc(sizeof(Color *) * 1);
	data->game.wall[0] = load_texture("resources/textures/wall.png");
}