/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:24:11 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 15:46:52 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMELOOP_H
# define GAMELOOP_H

# include "/opt/homebrew/Cellar/raylib/3.7.0/include/raylib.h"
# include "../data.h"
# include "ingame/loop_ingame.h"

void	loop_mainmenu(t_data *data);
void	loop_loadingscreen(t_data *data);
void	loop_ingame(t_data *data);

#endif