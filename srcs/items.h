/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:05:40 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/18 00:45:58 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ITEMS_H
# define ITEMS_H

# define STATIC 0
# define CONSUMEABLE 1
# define WEAPON 2
# define HEAD 3

typedef struct s_item {
	Texture	icon;
	int		id;
	int		type;
	int		damage;
	int		durability;
	int		upgrade_level;
	int		price;
	char	*tooltip;
	char	*name;
}				t_item;


#endif