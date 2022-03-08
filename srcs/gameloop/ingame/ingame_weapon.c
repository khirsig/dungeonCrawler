/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:37:33 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/08 09:17:51 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"
#include "raymath.h"

void	draw_weapon(t_data *data)
{
	data->player.wep.model.transform = MatrixRotateY(-data->player.planeX + data->player.planeY);
	DrawModel(data->player.wep.model, (Vector3){ data->player.posX, data->player.posZ, data->player.posY }, 0.5f, WHITE);
}
