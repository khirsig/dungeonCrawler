/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:41:34 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 12:38:59 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "window.h"
# include "gameloop/game.h"
# include "parser/map.h"
# include "player.h"

typedef struct s_data {
	t_window	window;
	t_game		game;
	t_map		map;
	t_player	player;
}				t_data;

#endif