/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_currency.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:56:00 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/19 00:10:49 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"
#include <limits.h>

void	add_gold(t_data *data, int amount)
{
	if ((long long)(data->player.gold) + amount > INT_MAX)
		data->player.gold = INT_MAX;
	else
		data->player.gold += amount;
}

void	add_soulgem(t_data *data, int amount)
{
	if ((long long)(data->player.soulgem) + amount > INT_MAX)
		data->player.soulgem = INT_MAX;
	else
		data->player.soulgem += amount;
}
