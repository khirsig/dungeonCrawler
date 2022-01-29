/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_ingame.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:50:55 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/27 18:55:27 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INGAME_DRAW_H
# define INGAME_DRAW_H

# include "../../main.h"
# include <stdlib.h>

void	ingame_keyhook(t_data *data);
void	ingame_draw(t_data *data);
void	ingame_interface(t_data *data);

#endif