/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:16:03 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/08 21:46:56 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"
#include <raymath.h>

static void	button_transform(Texture *tex, char *path_prefix, char *path_rest, int lenX, int lenY, int start, int end)
{
	Image image;
	char *temp;
	char *path;
	int	og_start;

	og_start = start;
	while (start < end)
	{
		temp = ft_strjoin(path_prefix, ft_itoa(start - og_start));
		path = ft_strjoin(temp, path_rest);
		free(temp);
		image = LoadImage(path);
		free(path);
		ImageResize(&image, lenX, lenY);
		tex[start] = LoadTextureFromImage(image);
		UnloadImage(image);
		start++;
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
	button_transform(data->window.texture, "./resources/interface/mainmenu/BUTTON00", ".png", data->window.button_lenX, data->window.button_lenY, 2, 12);
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
	Mesh mesh = GenMeshCube(10, 10, 10);
	data->game.wall_model = malloc(sizeof(Model) * 4);
	data->game.wall_model[0] = LoadModelFromMesh(mesh);
	data->game.wall_model[1] = LoadModelFromMesh(mesh);
	mesh = GenMeshCube(10, 10, 0);
	data->game.wall_model[2] = LoadModelFromMesh(mesh);
	data->game.wall_model[0].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = data->game.wall[0];
	data->game.wall_model[1].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = data->game.wall[1];
	data->game.wall_model[2].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = data->game.wall[2];
	data->game.wall_model[2].transform = MatrixRotateX(180 * DEG2RAD);
	data->window.cursor = malloc(sizeof(Texture) * 4);
	data->window.cursor[0] = load_texture("resources/interface/cursor_x.png");
	data->window.cursor[1] = load_texture("resources/interface/cursor_l.png");
	data->window.cursor[2] = load_texture("resources/interface/cursor_r.png");
	data->window.texture = malloc(sizeof(Texture) * 13);
	init_window_mainmenu(data);
	data->window.font = LoadFont("resources/fonts/main.ttf");
	data->window.title_size = data->window.title_lenY / 3;
	data->window.button_size = data->window.button_lenY / 4;
}