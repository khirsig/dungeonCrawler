/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_ingame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:28:54 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/24 18:14:52 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameloop.h"

void	loop_ingame(t_data *data)
{
	data->player.camera.position = (Vector3){ data->player.posX, data->player.posZ, data->player.posY };
	data->player.camera.target = (Vector3){ data->player.dirX, data->player.dirZ, data->player.dirY };
	printf("Pos: [%f] [%f]\n", data->player.posX, data->player.posY);
	UpdateCamera(&data->player.camera);
	BeginDrawing();
	ClearBackground(BLACK);
	ingame_keyhook(data);
	BeginMode3D(data->player.camera);
	ingame_draw(data);
	DrawSphere((Vector3){ data->player.dirX, data->player.dirZ, data->player.dirY }, 0.05f, RED);
	EndMode3D();
	ingame_interface(data);
	EndDrawing();
}