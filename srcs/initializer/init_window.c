/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:16:03 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/17 21:47:27 by khirsig          ###   ########.fr       */
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

void	init_window_mainmenu(t_data *data)
{
	Image image;

	image = LoadImage("./resources/interface/mainmenu/background.png");
	ImageResize(&image, data->window.width, data->window.height);
	data->window.texture[0] = LoadTextureFromImage(image);
	UnloadImage(image);
	image = LoadImage("./resources/interface/mainmenu/overlaytitle.png");
	data->window.title_lenX = data->window.width / 4 * 3;
	data->window.title_lenY = data->window.height / 5;
	ImageResize(&image, data->window.title_lenX, data->window.title_lenY);
	data->window.texture[1] = LoadTextureFromImage(image);
	UnloadImage(image);
	image = LoadImage("./resources/interface/mainmenu/buttonnormal.png");
	data->window.button_lenX = data->window.width / 4;
	data->window.button_lenY = data->window.height / 10;
	ImageResize(&image, data->window.button_lenX, data->window.button_lenY);
	data->window.texture[2] = LoadTextureFromImage(image);
	UnloadImage(image);
	image = LoadImage("./resources/interface/mainmenu/buttonhover.png");
	ImageResize(&image, data->window.button_lenX, data->window.button_lenY);
	data->window.texture[3] = LoadTextureFromImage(image);
	UnloadImage(image);
}

void	init_window(t_data *data)
{
	// int	monitor = GetMonitorCount();
	data->window.height = SCREEN_HEIGHT;
	data->window.width = SCREEN_WIDTH;
	// printf("===========/n%i: %i %i\n", monitor, data->window.height, data->window.width);
	InitWindow(data->window.width, data->window.height, SCREEN_TITLE);
	// SetWindowState(FLAG_FULLSCREEN_MODE);
	data->game.wall = malloc(sizeof(Texture) * 4);
	data->game.wall[0] = load_texture("resources/textures/crypt00.png");
	data->game.wall[1] = load_texture("resources/textures/crypt01.png");
	data->game.wall[2] = load_texture("resources/textures/crypt02.png");
	data->window.cursor = malloc(sizeof(Texture) * 4);
	data->window.cursor[0] = load_texture("resources/interface/cursor_x.png");
	data->window.cursor[1] = load_texture("resources/interface/cursor_l.png");
	data->window.cursor[2] = load_texture("resources/interface/cursor_r.png");
	// data->game.enemy_skin = malloc(sizeof(Texture) * 3);
	data->window.texture = malloc(sizeof(Texture) * 5);
	init_window_mainmenu(data);
	data->window.font = LoadFont("resources/fonts/main.ttf");
	data->window.title_size = data->window.title_lenY / 3;
	data->window.button_size = data->window.button_lenY / 4;
}