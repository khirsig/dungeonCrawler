/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:13:23 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 13:36:10 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_error_map(t_data *data, char **map, int x, int y)
{
	if (((y == 0 && (map[y][x] != '1' && map[y][x] != ' '))
	|| (y != 0 && (map[y][x] != '1'
	&& map[y][x] != ' ') && map[y - 1][x] == ' '))
	|| ((y == data->map.height - 1 && (map[y][x] != '1' && map[y][x] != ' '))
	|| (y != data->map.height - 1
	&& (map[y][x] != '1' && map[y][x] != ' ') && map[y + 1][x] == ' '))
	|| ((x == 0 && (map[y][x] != '1' && map[y][x] != ' '))
	|| (x != 0 && (map[y][x] != '1'
	&& map[y][x] != ' ') && map[y][x - 1] == ' '))
	|| ((x == data->map.width - 1 && (map[y][x] != '1' && map[y][x] != ' '))
	|| (x != data->map.width - 1
	&& (map[y][x] != '1' && map[y][x] != ' ') && map[y][x + 1] == ' ')))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int	parser_map_error(t_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (is_error_map(data, map, x, y) == 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
