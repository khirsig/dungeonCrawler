/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:52:17 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 23:06:13 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct s_ray {
	double	cameraX;
	double	dirX;
	double	dirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	double	wallX;
	double	step;
	double	texPos;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		stepX;
	int		stepY;
	int		mapX;
	int		mapY;
	int		hit;
	int		side;
	int		texNum;
	int		texX;
	int		texY;
}				t_ray;

#endif