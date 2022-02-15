/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:57:05 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/31 01:41:50 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_char(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == '\0' || c == 'B' || c == '['
		|| c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == ']' || c == '-'
		|| c == '_' || c == 'n')
		return (1);
	else
		return (0);
}

static int	finalize_map(t_data *data, char **temp)
{
	int	x_index;
	int	y_index;
	int	strlen;

	data->map.grid = malloc(sizeof(char *) * data->map.height + 1);
	data->map.grid[data->map.height] = NULL;
	y_index = 0;
	while (y_index < data->map.height)
	{
		x_index = 0;
		strlen = ft_strlen(temp[y_index]);
		data->map.grid[y_index] = malloc(sizeof(char) * data->map.width + 1);
		data->map.grid[y_index][data->map.width] = '\0';
		while (x_index < strlen)
		{
			if (temp[y_index][x_index] == '\n')
				break ;
			if (check_char(temp[y_index][x_index]) == 0)
				return (0);
			int rnd = GetRandomValue(1, 100);
			if ( temp[y_index][x_index] == '1' && rnd >= 0 && rnd < 70)
				data->map.grid[y_index][x_index] = temp[y_index][x_index];
			else if (temp[y_index][x_index] == '1' && rnd >= 70 && rnd < 90)
				data->map.grid[y_index][x_index] = '8';
			else if (temp[y_index][x_index] == '1')
				data->map.grid[y_index][x_index] = '9';
			else
			{
				if (temp[y_index][x_index] == '-' || temp[y_index][x_index] == '_' || temp[y_index][x_index] == '[' || temp[y_index][x_index] == ']')
				{
					data->map.door_count++;
					data->map.door = realloc(data->map.door, data->map.door_count * sizeof(t_door));
					data->map.door[data->map.door_count - 1].x = x_index;
					data->map.door[data->map.door_count - 1].y = y_index;
					data->map.door[data->map.door_count - 1].z = 0.0f;
					data->map.door[data->map.door_count - 1].state = CLOSING;
				}
				if (temp[y_index][x_index] == 'n')
				{
					data->game.npc_count++;
					data->npc = realloc(data->npc, data->game.npc_count * sizeof(t_npc));
					data->npc[data->game.npc_count - 1].cycle = 0.00f;
					data->npc[data->game.npc_count - 1].state = IDLE;
					data->npc[data->game.npc_count - 1].id = data->game.npc_count - 1;
					data->npc[data->game.npc_count - 1].pos.x = x_index * 10 - 2.50f;
					data->npc[data->game.npc_count - 1].pos.y = y_index * 10 - 2.50f;
				}
				data->map.grid[y_index][x_index] = temp[y_index][x_index];
			}
			x_index++;
		}
		while (x_index < data->map.width)
		{
			data->map.grid[y_index][x_index] = ' ';
			x_index++;
		}
		y_index++;
	}
	return (1);
}

void	parser_map(t_data *data, char *file)
{
	char	**temp;
	char	*str;
	int		fd;
	int		index;

	fd = open(file, O_RDONLY);
	data->map.height = parser_map_y_length(file);
	data->map.width = parser_map_x_length(file);
	temp = malloc(sizeof(char *) * data->map.height + 1);
	temp[data->map.height] = NULL;
	str = get_next_line(fd);
	while (str != NULL && str[0] == '\n')
	{
		free(str);
		str = get_next_line(fd);
	}
	temp[0] = ft_strdup(str);
	index = 1;
	while (index < data->map.height)
	{
		temp[index] = get_next_line(fd);
		if (temp[index][0] == '\n')
			ft_putstr_fd("Error\n", 2);
		index++;
	}
	if (finalize_map(data, temp) == 0)
		ft_putstr_fd("Error\n", 2);
	parser_map_error(data, data->map.grid);
}
