/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:35:34 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/24 18:38:58 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_player {
	Camera	camera;
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
	double	max_health;
	double	health;
	double	max_stamina;
	double	stamina;
	int		rotate_left;
	int		rotate_right;
	int		is_sprinting;
}				t_player;

#endif