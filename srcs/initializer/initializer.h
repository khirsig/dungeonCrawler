/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:16:52 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 13:41:07 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZER_H
# define INITIALIZER_H

# include "/opt/homebrew/Cellar/raylib/3.7.0/include/raylib.h"
# include "../data.h"
# include "../main.h"

void	init_window(t_data *data);
void	init_gameloop(t_data *data);
void	init_player(t_data *data);

#endif