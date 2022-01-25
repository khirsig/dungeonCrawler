/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:29:09 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/25 21:06:05 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_H
# define DOOR_H

# define CLOSING 0
# define OPENING 1

typedef struct s_door {
	int		x;
	int		y;
	double	z;
	int		state;
}				t_door;

#endif