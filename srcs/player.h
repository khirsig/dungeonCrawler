/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:35:34 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/07 14:02:21 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "inventory.h"

typedef struct s_charOverlay {
	Texture	bg;
	Texture	circle;
	Texture	avatar;
	int		lenX;
	int		lenY;
	int		startX;
	int		startY;
}				t_charOverlay;

typedef struct s_player {
	Camera	camera;
	t_inventory inv;
	t_charOverlay chLay;
	double	posX;
	double	posY;
	double	posZ;
	double	planeX;
	double	planeY;
	double	planeZ;
	double	dirX;
	double	dirY;
	double	dirZ;
	double	movementspeed;
	double	base_ms;
	double	rotatespeed;
	double	sprintspeed;
	double	max_health;
	double	health;
	double	max_stamina;
	double	stamina;
	int		level;
	int		gold;
	int		soulgem;
	int		rotate_left;
	int		rotate_right;
	int		is_sprinting;
	int		is_jumping;
}				t_player;

#endif