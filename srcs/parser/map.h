/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:11:30 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/07 15:24:32 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "door.h"

typedef struct s_minimap {
	Texture	border;
	int		len;
	int		startX;
	int		startY;
}				t_minimap;

typedef struct s_map {
	char	**grid;
	t_door	*door;
	t_minimap mini;
	int		door_count;
	int		width;
	int		height;
}				t_map;

#endif