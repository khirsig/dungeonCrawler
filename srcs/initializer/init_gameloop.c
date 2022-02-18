/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameloop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:27:06 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/18 14:30:39 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

void	init_gameloop(t_data *data)
{
	data->game.state = MAINMENU;
	data->game.debugmode = 0;
	SetTargetFPS(SCREEN_FPS);
}