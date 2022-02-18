/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:16:52 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/18 14:31:28 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZER_H
# define INITIALIZER_H

# include "raylib.h"
# include "../data.h"
# include "../main.h"

void	init_window(t_data *data);
void	init_gameloop(t_data *data);
void	init_player(t_data *data);
void	init_npc(t_data *data);
Texture	load_texture(char *path);
void	init_inventory(t_data *data);
void	init_weapons(t_data *data);
void	init_console(t_data *data);

#endif