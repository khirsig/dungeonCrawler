/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:30:32 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/18 17:37:33 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSOLE_H
# define CONSOLE_H

typedef struct s_console {
	char	**history;
	char	*prompt;
	int		history_count;
	int		history_save;
	int		status;
}				t_console;

#endif