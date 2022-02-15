/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:16:03 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/31 01:35:10 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

Texture	load_texture(char *path)
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
	data->window.height = SCREEN_HEIGHT;
	data->window.width = SCREEN_WIDTH;
	InitWindow(data->window.width, data->window.height, SCREEN_TITLE);
	data->game.wall = malloc(sizeof(Texture) * 4);
	data->game.wall[0] = load_texture("resources/textures/crypt00.png");
	data->game.wall[1] = load_texture("resources/textures/crypt01.png");
	data->game.wall[2] = load_texture("resources/textures/crypt02.png");
	data->window.cursor = malloc(sizeof(Texture) * 4);
	data->window.cursor[0] = load_texture("resources/interface/cursor_x.png");
	data->window.cursor[1] = load_texture("resources/interface/cursor_l.png");
	data->window.cursor[2] = load_texture("resources/interface/cursor_r.png");
	// data->game.enemy_skin = malloc(sizeof(Texture) * 3);
}