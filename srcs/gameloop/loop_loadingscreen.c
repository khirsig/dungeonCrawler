/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_loadingscreen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:34:48 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 22:47:08 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameloop.h"

void	loop_loadingscreen(t_data *data)
{
	BeginDrawing();
	ClearBackground(BLACK);
	Image test2;
	test2 = LoadImage("resources/textures/wall.png");
	Color *c = LoadImageColors(test2);
	int i = 0;
	for (int x = 200; x < 200 + test2.height; x++)
	{
		for (int y = 200; y < 200 + test2.width; y++)
		{
			DrawPixel(y, x, c[i]);
			i++;
		}
	}
	UnloadImage(test2);
	DrawText("Loading Screen", data->window.width / 2, data->window.height / 2, 50, RAYWHITE);
	EndDrawing();
}