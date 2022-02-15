/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_ingame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:28:54 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/31 20:54:33 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameloop.h"

void	loop_ingame(t_data *data)
{
	data->player.camera.position = (Vector3){ data->player.posX, data->player.posZ, data->player.posY };
	data->player.camera.target = (Vector3){ data->player.dirX, data->player.dirZ, data->player.dirY };
	if (data->npc[0].cycle < 22.0f)
		data->npc[0].cycle += 0.05f;
	else
		data->npc[0].cycle = 0.00f;
	UpdateCamera(&data->player.camera);
	BeginDrawing();
	ClearBackground(BLACK);
	ingame_keyhook(data);
	BeginMode3D(data->player.camera);
	DrawSphere((Vector3){ data->player.dirX / 10, data->player.dirY / 10, data->player.dirZ / 10 }, 1.0f, BLUE);
	ingame_draw(data);
	EndMode3D();
	ingame_interface(data);
	EndDrawing();
}