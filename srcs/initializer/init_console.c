/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_console.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:30:31 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/18 17:30:53 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

void	init_console(t_data *data)
{
	data->console.prompt = NULL;
	data->console.status = 0;
	data->console.history = NULL;
	data->console.history_count = 0;
}