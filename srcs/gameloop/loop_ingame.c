/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_ingame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:28:54 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 15:47:12 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameloop.h"

void	loop_ingame(t_data *data)
{
	BeginDrawing();
	ClearBackground(BLACK);
	ingame_keyhook(data);
	ingame_draw(data);
	EndDrawing();
}