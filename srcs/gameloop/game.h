/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:40:57 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 22:55:54 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define MAINMENU 0
# define LOADINGSCREEN 1
# define INGAME 2
# define INVENTORY 3
# define MAP 4

# include "ingame/ray.h"

typedef struct s_game {
	t_ray	ray;
	Color	**wall;
	int		state;
	int		FPS;
}				t_game;

#endif