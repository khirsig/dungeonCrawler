/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:16:03 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/17 23:29:54 by khirsig          ###   ########.fr       */
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

static void	button_transform(Texture *tex, char *path_prefix, char *path_rest, int lenX, int lenY, int end)
{
	int index;
	Image image;
	char *temp;
	char *path;

	index = 2;
	while (index < end)
	{
		temp = ft_strjoin(path_prefix, ft_itoa(index - 2));
		path = ft_strjoin(temp, path_rest);
		free(temp);
		image = LoadImage(path);
		free(path);
		ImageResize(&image, lenX, lenY);
		tex[index] = LoadTextureFromImage(image);
		UnloadImage(image);
		index++;
	}
}

static void	init_window_mainmenu(t_data *data)
{
	Image	image;
	double	calc;

	image = LoadImage("./resources/interface/mainmenu/background.png");
	ImageResize(&image, data->window.width, data->window.height);
	data->window.texture[0] = LoadTextureFromImage(image);
	UnloadImage(image);
	image = LoadImage("./resources/interface/mainmenu/TITLE.png");
	calc = 897 / 141;
	data->window.title_lenX = data->window.width / 8 * calc;
	data->window.title_lenY = data->window.width / 8;
	ImageResize(&image, data->window.title_lenX, data->window.title_lenY);
	data->window.texture[1] = LoadTextureFromImage(image);
	UnloadImage(image);
	calc = 269 / 54;
	data->window.button_lenX = data->window.width / 18 * calc;
	data->window.button_lenY = data->window.width / 18;
	button_transform(data->window.texture, "./resources/interface/mainmenu/BUTTON00", ".png", data->window.button_lenX, data->window.button_lenY, 12);
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
	data->window.texture = malloc(sizeof(Texture) * 13);
	init_window_mainmenu(data);
	data->window.font = LoadFont("resources/fonts/main.ttf");
	data->window.title_size = data->window.title_lenY / 3;
	data->window.button_size = data->window.button_lenY / 4;
}