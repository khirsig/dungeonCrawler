/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:11:30 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/25 20:49:23 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "door.h"

typedef struct s_map {
	char	**grid;
	t_door	*door;
	int		door_count;
	int		height;
	int		width;
}				t_map;

#endif