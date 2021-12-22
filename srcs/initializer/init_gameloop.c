/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameloop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:27:06 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/21 23:29:15 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

void	init_gameloop(t_data *data)
{
	data->game.state = MAINMENU;
	data->game.framesCounter = 0;
	SetTargetFPS(60);
}