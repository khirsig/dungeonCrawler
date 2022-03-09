/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:37:33 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/09 14:28:44 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"
#include "raymath.h"

void	draw_weapon(t_data *data)
{
	DrawModelEx(data->player.wep.model, (Vector3){ data->player.posX, 0, data->player.posY }, (Vector3){ 0, 1, 0}, data->player.wep.angle, (Vector3){ 0.1f, 0.1f, 0.1f }, WHITE);
	DrawModelEx(data->player.wep.model, (Vector3){ 70, 0, 140 }, (Vector3){ 0, 1, 0}, data->player.wep.angle, (Vector3){ 0.5f, 0.5f, 0.5f }, WHITE);
	data->player.wep.framecnt += 0.10;
	if (data->player.wep.framecnt > 280)
		data->player.wep.framecnt = 260;
	UpdateModelAnimation(data->player.wep.model, data->player.wep.anim[0], data->player.wep.framecnt);
}
