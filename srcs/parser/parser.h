/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:57:28 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 16:10:45 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include <fcntl.h>
# include "../main.h"
# include "../data.h"

void	parser_map(t_data *data, char *file);
int		parser_map_x_length(char *file);
int		parser_map_y_length(char *file);
int		parser_map_error(t_data *data, char **map);

#endif