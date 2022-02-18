/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_console.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:30:31 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/18 14:31:11 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

void	init_console(t_data *data)
{
	data->console.prompt = NULL;
	data->console.status = 0;
}