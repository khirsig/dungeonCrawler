/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:35:34 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/18 21:54:18 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_player {
	Camera	camera;
	double	posX;
	double	posY;
	double	planeX;
	double	planeY;
	double	dirX;
	double	dirY;
	double	movementspeed;
	double	max_health;
	double	health;
	double	max_stamina;
	double	stamina;
	int		rotate_left;
	int		rotate_right;
}				t_player;

#endif