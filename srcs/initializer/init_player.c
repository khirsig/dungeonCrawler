/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:39:41 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/09 14:43:08 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"
#include <raymath.h>

static void set_start_point(t_data *data)
{
	int	x;
	int y;

	y = 0;
	while (data->map.grid[y] != NULL)
	{
		x = 0;
		while (data->map.grid[y][x] != '\0')
		{
			if (data->map.grid[y][x] == 'N' || data->map.grid[y][x] == 'S'
				|| data->map.grid[y][x] == 'E' || data->map.grid[y][x] == 'W')
			{

				data->player.posX = x * 10 + 5;
				data->player.posY = y * 10 + 5;
				data->player.posZ = 1.3f;
				data->player.dirZ = 1.3f;
				data->player.planeZ = 1.0f;
				data->player.planeX = 0.0f;
				data->player.planeY = 0.0f;
				if (data->map.grid[y][x] == 'N')
					data->player.planeY = -1.0f;
				if (data->map.grid[y][x] == 'S')
					data->player.planeY = 1.0f;
				if (data->map.grid[y][x] == 'W')
					data->player.planeX = -1.0f;
				if (data->map.grid[y][x] == 'E')
					data->player.planeX = 1.0f;
				data->player.dirX = data->player.posX + data->player.planeX;
				data->player.dirY = data->player.posY + data->player.planeY;
			}
			x++;
		}
		y++;
	}
}

void	init_player(t_data *data)
{
	set_start_point(data);
	data->player.is_sprinting = 0;
	data->player.is_moving = 0;
	data->player.base_ms = 0.10;
	data->player.max_health = 100.0000;
	data->player.health = data->player.max_health;
	data->player.max_stamina = 100.00000;
	data->player.stamina = data->player.max_stamina;
	data->player.camera.position = (Vector3){ data->player.posX, data->player.posZ, data->player.posY };
	data->player.camera.target = (Vector3){ data->player.dirX, data->player.dirZ, data->player.dirY };
	data->player.camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
	data->player.camera.fovy = SCREEN_FOV;
	data->player.soulgem = 0;
	data->player.gold = 0;
	data->player.level = 1;
	double	calc = 432.0 / 153.0;
	data->player.chLay.lenX = data->window.width / 10 * calc;
	data->player.chLay.lenY = data->window.width / 10;
	data->player.chLay.bg = load_texture_len("./resources/interface/charoverlay.png", data->player.chLay.lenX, data->player.chLay.lenY);
	data->player.chLay.circle = load_texture_len("./resources/interface/avatarcircle.png", data->player.chLay.lenY - data->player.chLay.lenY / 3.4, data->player.chLay.lenY - data->player.chLay.lenY / 3.4);
	data->player.chLay.avatar = load_texture_len("./resources/interface/AVATAR000.png", data->player.chLay.lenY - data->player.chLay.lenY / 3.4, data->player.chLay.lenY - data->player.chLay.lenY / 3.4);
	data->player.chLay.startX = data->window.width * 0.02;
	data->player.chLay.startY = data->window.height - data->player.chLay.lenY;
	printf("==================================MODEL=================================\n");
	data->player.wep.model = LoadModel("./resources/models/katana.iqm");
	data->player.wep.model.transform = MatrixRotateX(90);
	unsigned int animCount = 6;
	printf("==================================ANIM=================================\n");
	data->player.wep.anim = LoadModelAnimations("./resources/models/katana.iqm", &animCount);
	printf("==================================END=================================\n");
	data->player.wep.framecnt = 260;
	data->player.wep.angle = 0;
	// printf("================================================ %i %i\n", data->player.wep.model.materialCount, data->player.wep.anim[0].frameCount);
	data->player.wep.model.materialCount = 5;
	Texture tempT = LoadTexture("./resources/models/textures/Material_baseColor.png");
	data->player.wep.model.materials[0].maps[0].texture = tempT;
	// tempT = LoadTexture("./resources/models/textures/t_phoenix_baseColor.png");
	// data->player.wep.model.materials[0].maps[0].texture = tempT;
	// tempT = LoadTexture("./resources/models/textures/v_hands_normal.png");
	// data->player.wep.model.materials[2].maps[0].texture = tempT;
	// tempT = LoadTexture("./resources/models/textures/Material_baseColor.png");
	// data->player.wep.model.materials[3].maps[0].texture = tempT;
}