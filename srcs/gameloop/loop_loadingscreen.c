/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_loadingscreen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:34:48 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/25 18:09:07 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameloop.h"

void	loop_loadingscreen(t_data *data)
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("Loading Screen", data->window.width / 2, data->window.height / 2, 50, RAYWHITE);
	EndDrawing();
}