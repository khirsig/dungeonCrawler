/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tooltip.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:09:33 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/19 10:11:25 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLTIP_H
# define TOOLTIP_H

typedef struct s_tooltip {
	Texture	tex;
	int		lenX;
	int		lenY;
	int		posX;
	int		posY;
}
				t_tooltip;

#endif