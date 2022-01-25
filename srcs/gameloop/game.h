/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:40:57 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/25 20:06:00 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define MAINMENU 0
# define LOADINGSCREEN 1
# define INGAME 2
# define INVENTORY 3
# define MAP 4


typedef struct s_game {
	Texture	*wall;
	Image	test;
	int		state;
	int		FPS;
}				t_game;

#endif