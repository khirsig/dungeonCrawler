/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:05:40 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/17 16:17:01 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ITEMS_H
# define ITEMS_H

typedef struct s_weapon {
	Texture	icon;
	int		id;
	int		damage;
	int		durability;
	int		upgrade;
}				t_weapon;

typedef struct s_item {
	t_weapon	*weapon;
}				t_item;


#endif