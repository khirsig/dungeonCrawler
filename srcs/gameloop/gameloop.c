/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:23:40 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/17 22:14:46 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameloop.h"

void	gameloop(t_data *data)
{
	while (!WindowShouldClose())
	{
		data->window.mouseX = GetMouseX();
		data->window.mouseY = GetMouseY();
		data->game.FPS = GetFPS();
		if (IsKeyPressed(KEY_TAB))
		{
			if (data->game.debugmode == 0)
				data->game.debugmode = 1;
			else
				data->game.debugmode = 0;
		}
		switch(data->game.state)
		{
			case MAINMENU:
			{
				loop_mainmenu(data);
			} break ;
			case LOADINGSCREEN:
			{
				loop_loadingscreen(data);
			} break ;
			case INGAME:
			{
				loop_ingame(data);
			} break ;
		}
	}
}