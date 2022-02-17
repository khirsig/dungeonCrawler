/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:57:55 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/17 20:03:52 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVENTORY_H
# define INVENTORY_H

# define CLOSED 0
# define OPEN 1

typedef struct s_gui {
	Texture	*tex;
	int		lenX;
	int		lenY;
	int		posX;
	int		posY;
	int		status;
	int		moving;
	int		mouseX;
	int		mouseY;
}				t_gui;

typedef struct s_inventory {
	t_gui	gui;
	int		head;
	int		weapon;
	int		chest;
	int		legs;
	int		feet;
	int		hands;
	int		neck;
}				t_inventory;

#endif