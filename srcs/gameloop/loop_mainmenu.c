/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_mainmenu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:32:18 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 14:18:48 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameloop.h"

void	loop_mainmenu(t_data *data)
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("Main Menu", data->window.width / 2, data->window.height / 2, 50, RAYWHITE);
	EndDrawing();
}