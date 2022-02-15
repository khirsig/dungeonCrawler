/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_npc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:55:27 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/04 02:15:51 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

static void	init_breton_woman(t_data *data, int index)
{
	printf("HALLO\n");
	data->npc[index].texture = malloc(sizeof(Texture) * 23);
	data->npc[index].texture[0] = load_texture("resources/sprites/002_skeleton/0-0.png");
	data->npc[index].texture[1] = load_texture("resources/sprites/002_skeleton/0-1.png");
	data->npc[index].texture[2] = load_texture("resources/sprites/002_skeleton/0-2.png");
	data->npc[index].texture[3] = load_texture("resources/sprites/002_skeleton/0-3.png");
	data->npc[index].texture[4] = load_texture("resources/sprites/002_skeleton/1-0.png");
	data->npc[index].texture[5] = load_texture("resources/sprites/002_skeleton/1-1.png");
	data->npc[index].texture[6] = load_texture("resources/sprites/002_skeleton/1-2.png");
	data->npc[index].texture[7] = load_texture("resources/sprites/002_skeleton/1-3.png");
	data->npc[index].texture[8] = load_texture("resources/sprites/002_skeleton/2-0.png");
	data->npc[index].texture[9] = load_texture("resources/sprites/002_skeleton/2-1.png");
	data->npc[index].texture[10] = load_texture("resources/sprites/002_skeleton/2-2.png");
	data->npc[index].texture[11] = load_texture("resources/sprites/002_skeleton/2-3.png");
	data->npc[index].texture[12] = load_texture("resources/sprites/002_skeleton/3-0.png");
	data->npc[index].texture[13] = load_texture("resources/sprites/002_skeleton/3-1.png");
	data->npc[index].texture[14] = load_texture("resources/sprites/002_skeleton/3-2.png");
	data->npc[index].texture[15] = load_texture("resources/sprites/002_skeleton/3-3.png");
	data->npc[index].texture[16] = load_texture("resources/sprites/002_skeleton/4-0.png");
	data->npc[index].texture[17] = load_texture("resources/sprites/002_skeleton/4-1.png");
	data->npc[index].texture[18] = load_texture("resources/sprites/002_skeleton/4-2.png");
	data->npc[index].texture[19] = load_texture("resources/sprites/002_skeleton/4-3.png");
	data->npc[index].texture[20] = load_texture("resources/sprites/002_skeleton/5-0.png");
	data->npc[index].texture[21] = load_texture("resources/sprites/002_skeleton/5-1.png");
	data->npc[index].pos.z = -0.8f;
	data->npc[index].health = 100;
	data->npc[index].size = 4.0f;
}

void	init_npc(t_data *data)
{
	int	index;
	int	rnd;

	index = 0;
	while (index < data->game.npc_count)
	{
		// rnd = GetRandomValue(0, 1)
		rnd = 0;
		if (rnd == BRETON_WOMAN)
			init_breton_woman(data, index);
		index++;
	}
}
