/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:15:29 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/18 14:31:19 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

void	initializer(t_data *data)
{
	init_window(data);
	init_gameloop(data);
	init_player(data);
	init_npc(data);
	init_inventory(data);
	init_console(data);
}