/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:16:03 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/22 19:46:23 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

static Texture	load_texture(char *path)
{
	Image image;
	Texture	texture;

	image = LoadImage(path);
	texture = LoadTextureFromImage(image);
	UnloadImage(image);
	return (texture);
}

void	init_window(t_data *data)
{
	data->window.height = 800;
	data->window.width = 1400;
	InitWindow(data->window.width, data->window.height, "The Elder Scrolls: Dungeon");
	data->game.wall = malloc(sizeof(Texture *) * 3);
	data->game.wall[0] = load_texture("resources/textures/crypt00.png");
	data->game.wall[1] = load_texture("resources/textures/crypt01.png");
	data->game.wall[2] = load_texture("resources/textures/crypt02.png");
}