/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:23:40 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 13:52:43 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameloop.h"

void	gameloop(t_data *data)
{
	while (!WindowShouldClose())
	{
		data->game.framesCounter++;
		if (IsKeyPressed(KEY_X))
			data->game.state = MAINMENU;
		if (IsKeyPressed(KEY_Y))
			data->game.state = LOADINGSCREEN;
		if (IsKeyPressed(KEY_O))
			data->game.state = INGAME;
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