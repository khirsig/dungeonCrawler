/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:07:38 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/25 17:45:14 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "/opt/homebrew/Cellar/raylib/3.7.0/include/raylib.h"
// # include <raylib.h>
# include "data.h"
# include "../config.h"

void	initializer(t_data *data);
void	parser(t_data *data, char *file);
void	gameloop(t_data *data);

#endif