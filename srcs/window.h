/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:42:25 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/17 21:16:59 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct s_window {
	int	height;
	int	width;
	Texture2D	*cursor;
	int			mouseX;
	int			mouseY;
	Texture		*texture;
	int			title_lenX;
	int			title_lenY;
	int			title_size;
	int			button_lenX;
	int			button_lenY;
	int			button_size;
	Font		font;
	int			fps;
}				t_window;

#endif