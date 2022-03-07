/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:18:26 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/07 15:20:17 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

Texture load_texture_len(char *path, int lenX, int lenY)
{
	Image image;
	Texture texture;
	int		lenIcon;

	image = LoadImage(path);
	ImageResize(&image, lenX, lenY);
	texture = LoadTextureFromImage(image);
	UnloadImage(image);
	return (texture);
}

Texture	load_texture(char *path)
{
	Image image;
	Texture	texture;

	image = LoadImage(path);
	texture = LoadTextureFromImage(image);
	UnloadImage(image);
	return (texture);
}
