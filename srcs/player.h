/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:35:34 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/18 23:45:42 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "inventory.h"

typedef struct s_player {
	Camera	camera;
	t_inventory inv;
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
	double	rotatespeed;
	double	sprintspeed;
	double	max_health;
	double	health;
	double	max_stamina;
	double	stamina;
	int		gold;
	int		soulgem;
	int		rotate_left;
	int		rotate_right;
	int		is_sprinting;
	int		is_jumping;
}				t_player;

#endif